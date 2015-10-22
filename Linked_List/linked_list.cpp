#include "linked_list.hpp"
#include <iostream>

/* Default constructor */

Linked_List::Linked_List()
{
  head->next = NULL;
  size = 0;
}

void Linked_List::print_list(const Linked_List& list_head)
{
  Node* current;
  current = head->next; 

  while (current != NULL) {
    std::cout << current->value << std::endl; 
    current = current->next;
  }
}
