#ifndef DEQUEUE_HPP
#define DEQUEUE_HPP

#include "queue.hpp"

class Dequeue : public Queue {
  public:
    Dequeue();
  private:
    DL_List* data;
    int size;
};

#endif
