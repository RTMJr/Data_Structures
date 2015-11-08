#include <iostream>
#include "doubly_linked_list.hpp"


int main(int argc, char* argv[])
{
  
  Doubly_Linked_List my_list;

  my_list.insert_after(100, 0);
  my_list.insert_at_head(4);
  my_list.insert_at_head(20);
  my_list.insert_at_head(40);

  my_list.print_list_head();

  std::cout << std::endl << std::endl; //<< "Removing head node" << std::endl << std::endl;

  my_list.reverse_list();

  my_list.insert_at_tail(200);

  my_list.print_list_head();

  my_list.remove_at_tail();

  std::cout << std::endl << std::endl;

  my_list.print_list_head();

  std::cout << std::endl << "Calling copy constructor..." << std::endl << std::endl;  

//  Doubly_Linked_List other_list;

 // other_list.insert_at_head(55);

  Doubly_Linked_List new_list(my_list); 

  new_list.print_list_head();

  return 0;
}
