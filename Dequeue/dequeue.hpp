#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP

#include "queue.hpp"

class Dequeue : public Queue {
  public:
    Dequeue();
    int back();
    int front();
    void push_back(int new_value);
    void push_front(int new_value);
    void pop_front();
    void pop_back();
    void view_dequeue(); 
    int get_size();
  private:
    Queue* data; 
    int size;
};

#endif
