/*
 * A Demo for campmiddleware.
 */
#include <iostream>

#include "handler.h"
#include "campmiddleware.h"
#include "protos/player.pb.h"

using namespace camp::protocols::player;

namespace camp {

// A specialization of template handleMessage<>() for each *Ack proto.
// If any specialization of *Ack not implemented, the compiler would warn you in LINK stage.

// NOTICE: The namespace sould be in `camp`.
// `context` is passed from CampMiddleware::dispatch(), the types should match.

template<>
void handleMessage<LoginOrCreateAccountAck, std::string>(LoginOrCreateAccountAck &ack, std::string &context)
{
    std::cout << "ack: " << ack.session_key() << std::endl;
    std::cout << "context: " << context << std::endl;
}

}

int main()
{
    // Raw ip only.
    camp::CampMiddleware mw("127.0.0.1", 11080);
    mw.start();

    // Just a demo for test the connection state.
    // DO USE IT in PRODUCTION.
    while (!mw.connected())
        sleep(1);

    // Construct a message.
    LoginOrCreateAccountReq req;
    req.set_auth_token("Hello world!");

    // Send than test the error code, which is the same of POSIX ::send()
    int r = mw.send(req);
    if (r < 0)
        perror("Sent failed");

    std::string context = "I am context";
    // Dispatch received messages, the context should be the same in specialization of template handleMessage<>().
    mw.dispatch(context);

    sleep(1);
    std::cout << "Exited." << std::endl;
    return 0;
}
