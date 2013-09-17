#ifndef CAMPMIDDLEWARE_H
#define CAMPMIDDLEWARE_H

#include <string>

namespace camp {

class ThreadBase;

class CampMiddleware
{
public:
    CampMiddleware(std::string const &host, int port);

private:
    ThreadBase* m_recv_thread;
};

}
#endif // CAMPMIDDLEWARE_H
