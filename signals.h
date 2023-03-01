#pragma once

template<typename T, typename returntype, typename... args>
class SignalHandler
{
    T* obj;
    void (T::*handler)(args...);
public:
    SignalHandler(T* obj, returntype (T::*handler)(args...)): obj(obj), handler(handler) {};
    returntype operator()(args...a) {return (obj->*handler)(a...);};
    operator bool() const { return handler != nullptr && obj != nullptr;}
};