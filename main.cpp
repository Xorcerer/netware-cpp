#include <iostream>
#include "thread.h"


using namespace std;

class MyThread : public camp::ThreadBase
{
    virtual void run() { cout << "Hello World!" << endl; }
};

int main()
{
    MyThread t;
    t.start();
    t.join();

    cout << "Exited." << endl;
    return 0;
}

