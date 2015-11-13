#include <iostream>
#include "dequeue.hpp"


int main(int argc, char* argv[])
{
  Dequeue my_dequeue;

  my_dequeue.push_front(5);
  my_dequeue.push_front(10);
  my_dequeue.push_front(20);

  my_dequeue.view_dequeue();
  
  return 0;
}
