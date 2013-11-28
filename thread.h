#ifndef THREAD_H
#define THREAD_H

#include <pthread.h>
#include <stdexcept>

namespace camp
{

class ThreadBase;

static void * threadbase_dispatcher(void *arg);

// Ref: http://peter.bourgon.org/blog/2010/10/27/who-needs-boost-a-simple-pthreads-wrapper.html
class ThreadBase
{
public:
    ThreadBase() : m_threadbase_ptr(NULL) { }
    virtual ~ThreadBase() { }

    void start()
    {
        if (m_threadbase_ptr != NULL)
            throw std::runtime_error("multiple ThreadBase start");

        m_threadbase_ptr = new pthread_t;
        int rc = pthread_create(m_threadbase_ptr, NULL, threadbase_dispatcher, this);
        if (rc != 0)
            throw std::runtime_error("ThreadBase pthread_create failed");
    }

    void join()
    {
        if (!m_threadbase_ptr)
            return;

        int rc = pthread_join(*m_threadbase_ptr, NULL);
        if (rc != 0)
            throw std::runtime_error("ThreadBase pthread_join failed");
        delete m_threadbase_ptr;
        m_threadbase_ptr = NULL;
    }

    virtual void run() = 0;

private:
    pthread_t *m_threadbase_ptr;
};

static void * threadbase_dispatcher(void *arg)
{
    ThreadBase *tb(static_cast<ThreadBase *>(arg));
    tb->run();
    return NULL;
}

}

#endif // THREAD_H
