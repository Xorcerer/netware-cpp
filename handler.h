#ifndef HANDLER_H
#define HANDLER_H

namespace camp
{

template <typename TMsg, typename TContext>
void handleMessage(TMsg &msg, TContext &context);

}

#endif // HANDLER_H
