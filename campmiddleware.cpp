#include "campmiddleware.h"
#include "thread.h"
#include "config.h"
#include "socket_utils.h"


namespace camp
{

class RecvThread: public ThreadBase
{
    char m_buffer[BUFF_SIZE];
    std::string const m_host;
    int m_port;
    volatile size_t m_rindex;
    volatile size_t m_windex;
    volatile int m_server_fd;
    volatile bool m_connected;

public:
    RecvThread(std::string const &host, int port):
        ThreadBase(),
        m_host(host),
        m_port(port),
        m_rindex(0),
        m_windex(0),
        m_server_fd(-1),
        m_connected(false)
    {}

    size_t availableSize() const;
    virtual void run();

    void close();

    bool pop(char *buffer, size_t size);
    int serverFd() const { return m_server_fd; }
    bool connected() const { return m_connected; }
};

size_t RecvThread::availableSize() const
{
    if (m_windex >= m_rindex)
        return m_windex - m_rindex;

    return BUFF_SIZE - m_rindex + m_windex;
}

void RecvThread::run()
{
    ssize_t r;

    m_server_fd = connect_socket(m_port, m_host.c_str());
    if (m_server_fd < 0)
    {
        perror("Failed to connect to server.");
        close();
        return;
    }

    for(;;)
    {
        while (m_rindex + 1 == m_windex)
            sleep(1);

        int fd = m_server_fd;
        fd_set rd, wr, er;
        FD_ZERO (&rd);
        FD_ZERO (&wr);
        FD_ZERO (&er);
        FD_SET(fd, &rd);
        FD_SET(fd, &wr);
        FD_SET(fd, &er);

        r = select(fd + 1, &rd, &wr, &er, NULL);
        if (r == -1 && errno == EINTR)
            continue;
        if (r < 0)
        {
            close();
            perror ("select()");
            return;
        }

        if (FD_ISSET(fd, &wr))
        {
            m_connected = true;
        }

        if (FD_ISSET(fd, &er))
        {
            close();
            return;
        }

        if (FD_ISSET(fd, &rd))
        {
            if (m_windex >= m_rindex)
                r = recv(fd, m_buffer + m_windex, BUFF_SIZE - m_windex, 0);
            else
                r = recv(fd, m_buffer + m_windex, m_rindex - m_windex - 1, 0);
            if (r <= 0)
            {
                if (r < 0) perror("recv()");
                close();
                return;
            }

            m_windex += r;
        }
    }
}

void RecvThread::close()
{
    if (m_server_fd >= 0) {
        shutdown (m_server_fd, SHUT_RDWR);
        ::close(m_server_fd);
        m_server_fd = -1;
        m_connected = false;
    }
}

bool RecvThread::pop(char *buffer, size_t size)
{
    if (availableSize() < size)
        return false;

    if (m_rindex < m_windex)
    {
        memcpy(buffer, m_buffer + m_rindex, size);
        m_rindex += size;
        return true;
    }

    size_t tail_size = BUFF_SIZE - m_rindex;
    if (tail_size > size)
    {
        memcpy(buffer, m_buffer + m_rindex, size);
        m_rindex += size;
        return true;
    }

    memcpy(buffer, m_buffer + m_rindex, tail_size);
    memcpy(buffer, m_buffer, size - tail_size);
    m_rindex = size - tail_size;
    return true;
}

CampMiddleware::CampMiddleware(std::string const &host, int port) :
    m_current_msg_size(-1), m_host(host), m_port(port)
{

}

CampMiddleware::~CampMiddleware() throw()
{
    if (m_recv_thread)
        delete m_recv_thread;
}

void CampMiddleware::start()
{
    m_recv_thread = new RecvThread(m_host, m_port);
    m_recv_thread->start();
}

bool CampMiddleware::connected() const
{
    return m_recv_thread && (m_recv_thread->serverFd() > 0);
}

char const *CampMiddleware::popMsgToBuffer(int &msg_id, int &msg_size)
{
    if (!m_recv_thread)
        return NULL;

    if (m_current_msg_size < 0)
        if (!m_recv_thread->pop(reinterpret_cast<char *>(&m_current_msg_size), sizeof(int)))
            return NULL;

    if (!m_recv_thread->pop(m_buffer, m_current_msg_size))
        return NULL;
    msg_id = *reinterpret_cast<int *>(m_buffer);
    msg_size = m_current_msg_size - sizeof(int);
    m_current_msg_size = -1;
    return m_buffer + sizeof(int);
}

int CampMiddleware::sendBuffer(int size)
{
    return ::send(m_recv_thread->serverFd(), m_buffer, size, 0);
}

}
