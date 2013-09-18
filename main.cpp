#include <iostream>

#include "handler.h"
#include "campmiddleware.h"
#include "protos/player.pb.h"

using namespace std;
using namespace camp::protocols::player;

namespace camp {

// 实现消息处理函数的模板特型,对于每个Ack协议,都要实现对应的handle,否则会在编译器报错.
// 请注意该模板特型需要放置在camp的命名空间下..
// context由dispatch函数传入，用于传递逻辑上下文。
template<>
void handleMessage<LoginOrCreateAccountAck, string>(LoginOrCreateAccountAck &ack, string& context)
{
    cout << "ack: " << ack.session_key() << endl;
    cout << "context: " << context << endl;
}

}

int main()
{
    // 连接服务器,只接受ip所谓第一个参数,不接收域名.
    camp::CampMiddleware mw("127.0.0.1", 11080);
    // 启动接收线程.
    mw.start();

    // 可以在主循环通过connected方法测试是否已经连接.
    // 这里的while仅仅用于演示.
    while (!mw.connected())
        sleep(1);

    // 构造一个消息.
    LoginOrCreateAccountReq req;
    req.set_auth_token("Hello world!");

    // 发送消息, 在连接上之前使用send方法无效.
    // 返回值r,为内部调用c语言函数::send()的返回值.
    int r = mw.send(req);
    if (r < 0)
    {
        perror("Sent failed");
    }

    std::string context = "I am context";
    // 分发消息,应在主循环被调用,context的类型应以handleMessage方法上的context类型一致.
    mw.dispatch(context);

    sleep(1);
    cout << "Exited." << endl;
    return 0;
}

