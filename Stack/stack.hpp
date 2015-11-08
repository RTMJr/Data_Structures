#ifndef STACK_HPP
#define STACK_HPP

#include "doubly_linked_list.hpp"
#include <cstddef> // for NULL

class Stack : public Doubly_Linked_List {
  public:
    Stack();
    ~Stack();
    Stack(const Stack& the_stack);
    int top();
    void push(int new_value);
    void pop();
    void view_stack();
    int get_size();
  private:
    int size;
    Doubly_Linked_List* data;
};

#endif // STACK_HPP
