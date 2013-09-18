#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "handler.h"
#include "serializer.h"
#include "protos/common.pb.h"
#include "protos/player.pb.h"


namespace camp
{
template <typename TContext>
void dispatch(int msg_id, char const *buffer, int size, TContext context)
{
    switch (msg_id) {
    case 2:
    {
        camp::protocols::player::LoginOrCreateAccountAck msg;
        deserialize(msg, buffer, size);
        handleMessage(msg, context);
        break;
    }
    default:
        break;
    }
}

}

#endif // DISPATCHER_H
