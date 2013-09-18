#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <assert.h>
#include "message_ids.h"

namespace camp
{

template <typename T>
int serialize(T const & msg, char *buffer, size_t size)
{
    const int body_offset = sizeof(int) * 2;
    int body_size = msg.ByteSize();
    *(int *)(buffer + sizeof(int)) = MessageId<T>::ID;

    assert(msg.SerializeToArray(buffer + body_offset, size));

    *(int *)buffer = body_size + sizeof(int);
    return body_size + body_offset;
}

template <typename T>
void deserialize(T & msg, char const *buffer, size_t size)
{
    assert(msg.ParseFromArray(buffer, size));
}

}

#endif // SERIALIZER_H
