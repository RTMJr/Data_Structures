/* Implementation file for linked_list.hpp */

#include "linked_list.hpp"
#include <iostream>

/* Default constructor */

Linked_List::Linked_List()
{
  head = NULL;
  size = 0;
}

/* Destructor */

Linked_List::~Linked_List()
{
  // empty
}

/* copy constructor */

Linked_List::Linked_List(const Linked_List& list) : size(list.get_size())
{
  head = list.get_head();
  Node* original_current = list.get_head();
  Node* copy_current = head; 

  while (original_current != NULL) {
    copy_current->value = original_current->value;
    copy_current->next = original_current->next;
    original_current = original_current->next;
    copy_current = copy_current->next;
  }
  
} 

void Linked_List::insert_at_head(int new_value)
{
  Node* new_node;  
  new_node = new Node;
  new_node->value = new_value;
  new_node->next = this->head;
  this->head = new_node;
}

void Linked_List::insert_after(int new_value, int previous_node)
{ 
  int node_index = 0;
  Node* current = this->head;
  Node* new_node;
  new_node = new Node;
  new_node->value = new_value;

  while (node_index != previous_node) {
    current = current->next;
    node_index++;
  }

  new_node->next = current->next;
  current->next = new_node;
}
  


  

void Linked_List::print_list()
{
  Node* current;
  current = head; 

  while (current != NULL) {
    std::cout << current->value << std::endl; 
    current = current->next;
  }
}


