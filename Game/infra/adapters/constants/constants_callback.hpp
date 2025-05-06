#ifndef CONSTANTS_CALLBACK_HPP
#define CONSTANTS_CALLBACK_HPP

#include <window_adapter.hpp>

using WindowArgs = WindowAdapter;
using WindowCallbackWrapper = void (WindowArgs &);
using WindowCallback = std::function<WindowCallbackWrapper>;

#endif // CONSTANTS_CALLBACK_HPP
