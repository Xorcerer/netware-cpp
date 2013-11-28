#ifndef CAMPMIDDLEWARE_H
#define CAMPMIDDLEWARE_H

#include <string>
#include <sys/socket.h>
#include "config.h"
#include "serializer.h"
#include "dispatcher.h"
#include "scope_ptr.h"

namespace camp {

class RecvThread;

class CampMiddleware
{
public:
    CampMiddleware(std::string const &host, int port);
    ~CampMiddleware() throw();

    void start();
    bool connected() const;

    template <typename T>
    void dispatch(T &context)
    {
        if (!m_recv_thread_ptr)
            return;

        int msg_id;
        int msg_size;
        char const * buffer;
        while((buffer = popMsgToBuffer(msg_id, msg_size)))
            camp::dispatch(msg_id, buffer, msg_size, context);
    }

    template <typename T>
    int send(T const &msg)
    {
        if (!m_recv_thread_ptr)
            return -1;
        int msg_size = serialize(msg, m_buffer, BUFF_SIZE);
        return sendBuffer(msg_size);
    }

private:
    char const *popMsgToBuffer(int &msg_id, int &msg_size);
    int sendBuffer(int size);

    int m_current_msg_size;
    std::string const m_host;
    int const m_port;
    camp::utils::ScopePtr<RecvThread> m_recv_thread_ptr;
    char m_buffer[BUFF_SIZE];
};

}
#endif // CAMPMIDDLEWARE_H
