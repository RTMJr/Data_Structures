#include <iostream>
#include "stack.hpp"

int main(int argc, char* argv[])
{
  Stack my_stack;

  my_stack.push(5);
  my_stack.push(10);
  my_stack.push(20);

 // my_stack.view_stack();

  Stack new_stack(my_stack);
  
  new_stack.view_stack();
  std::cout << "Here is the top of the stack " << new_stack.top() << std::endl;
  std::cout << new_stack.get_size() << std::endl;

  std::cout << "popping top of stack..." << std::endl << std::endl;

  new_stack.pop();
  new_stack.pop();
  new_stack.pop();

  new_stack.view_stack();

  std::cout << "Size of the stack is " << new_stack.get_size() << std::endl;

  /*Doubly_Linked_List my_list;

  my_list.insert_at_head(5);
  my_list.insert_at_head(10);
  my_list.insert_at_head(20);

  my_list.print_list_head();

  my_list.remove_at_head();

  std::cout << std::endl; 

  my_list.print_list_head();*/


  return 0;
}
