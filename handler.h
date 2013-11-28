#ifndef HANDLER_H
#define HANDLER_H

namespace camp
{

// Handlers called by dispatcher.
template <typename TMsg, typename TContext>
void handleMessage(TMsg &msg, TContext &context);

}

#endif // HANDLER_H
