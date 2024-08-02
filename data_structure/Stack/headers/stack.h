#ifndef STACK_H
#define STACK_H

//#include "../Double_linked_list/headers/list.h"
#include "/Users/haykpipoyan/Desktop/Picsart_Academy/C++/Algorithms/data_structure/Double_linked_list/headers/list.h"

namespace my_std
{
template <typename T>
class stack {
    public:
        stack() = default;
        ~stack() = default;

        bool is_empty() const;
        bool push(const int& val);
        void pop();
        int& top();

    private:
        list<T> ob;

};

}
#include "stack.hpp"

#endif // STACK_H
