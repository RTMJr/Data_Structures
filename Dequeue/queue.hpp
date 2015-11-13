#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "doubly_linked_list.hpp"

typedef Doubly_Linked_List DL_List;

class Queue : public DL_List {
  public:
    Queue();
    int back();
    int front();
    void push_back(int new_value);
    void pop_front();
    void view_queue();
    Node* get_head();
    Node* get_tail();
    int get_size();
    void set_size(int new_size) { size = new_size; }
  private:
    DL_List* data;
    int size;
};

#endif
