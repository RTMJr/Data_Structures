#include <iostream>
#include "queue.hpp"

int main(int argc, char* argv[])
{

  Queue my_queue;

  my_queue.push_back(5);
  my_queue.push_back(10);
  my_queue.push_back(20);

  /*std::cout << my_queue.back() << std::endl;
  std::cout << my_queue.front() << std::endl;*/

  my_queue.view_queue();
  std::cout << my_queue.get_size() << std::endl;
  return 0;
}
