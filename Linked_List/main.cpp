#include <iostream>
#include "linked_list.hpp"


int main(int argc, char* argv[])
{
  Linked_List my_list;

  std::cout << std::endl << "my list size = " << my_list.get_size() << std::endl;

  std::cout << std::endl;
  
  my_list.insert_at_head(10);
  my_list.insert_at_head(25);
  my_list.insert_at_head(11);
  my_list.insert_at_head(7);

  my_list.print_list();
  std::cout << std::endl;

  my_list.reverse_list();
  my_list.print_list();


  return 0;
}
