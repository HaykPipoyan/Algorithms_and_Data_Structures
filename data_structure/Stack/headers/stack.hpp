#ifndef STACK_HPP
#define STACK_HPP

#include "stack.h"
#include <iostream>

namespace my_std
{
template <typename T>
bool stack<T>::is_empty() const
{
    return ob.is_empty();
}

template <typename T>
bool stack<T>::push(const int& val)
{
    ob.push_back(val);
    return true;
}

template <typename T>
void stack<T>::pop()
{
    if(!ob.is_empty()) {
        ob.pop_back;
    }
}

template <typename T>
int& stack<T>::top()
{
    if (!ob.empty()) {
        return ob.back();
    }
    throw std::out_of_range("Stack is empty");
}

}
#endif // STACK_HPP
