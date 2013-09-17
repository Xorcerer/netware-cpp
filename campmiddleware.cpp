#include "campmiddleware.h"
#include "thread.h"


namespace camp
{

class RecvThread: public ThreadBase
{
    //char[]
public:
    virtual void run();
};

void RecvThread::run()
{

}

CampMiddleware::CampMiddleware(std::string const &host, int port)
{

}

}
