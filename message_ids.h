#ifndef MESSAGE_IDS_H
#define MESSAGE_IDS_H

/*
 * WARNING: This file is generated automatically by script from template.
 * DO NOT EDIT manually.
*/

#include "protos/player.pb.h"

namespace camp
{

template <typename T>
struct MessageId;

template <>
struct MessageId<camp::protocols::player::LoginOrCreateAccountReq>
{ enum { ID = 9 }; };

template <>
struct MessageId<camp::protocols::player::LoginOrCreateAccountAck>
{ enum { ID = 2 }; };


}

#endif // MESSAGE_IDS_H
