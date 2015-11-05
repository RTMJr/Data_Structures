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

/*  insert_at_head
    parameters: new int value
    precondition: linked list does not have new int value
    postconditoin: linked list contains new int value
*/

void Linked_List::insert_at_head(int new_value)
{
  Node* new_node;  
  new_node = new Node;
  new_node->value = new_value;
  new_node->next = this->head;
  this->head = new_node;
  size++;
}

/*  insert_after
    parameters: new int value, previous node index
    precondition: linked list does not have new int value
    postconditoin: linked list contains new int value
*/

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
  size++;
}

/*  remove_at_head
    parameters: none     
    precondition: linked list has original head
    postconditoin: linked list no longer has original head
*/

void Linked_List::remove_at_head()
{
  Node* old_node; 
  old_node = this->head;

  this->head = this->head->next;
  delete old_node;
  size--;
}

/*  remove_after
    parameters: none     
    precondition: linked list has original head
    postconditoin: linked list no longer has original head
*/

void Linked_List::remove_after(int previous_node)  
{
  if (previous_node == 0) {
    this->remove_at_head();
    size--;
    return;
  }

  int node_index = 0; 
  Node* current = this->head;
  Node* previous;

  while (node_index != previous_node) {
    previous = current;
    current = current->next;
    node_index++;
  }

  previous->next = current->next;
  delete current;
  size--;
}

/*  reverse_list
    parameters: none     
    precondition: linked list in original order
    postconditoin: linked list in reverse order
*/

void Linked_List::reverse_list()
{
  Node* current = this->head;
  Node* previous = NULL;
  Node* new_current;

  while (current != NULL) {
    new_current = current->next;
    current->next = previous;
    previous = current;
    current = new_current;
  }

  this->head = previous;
}

/*  print_list
    parameters: none     
    precondition: linked list in original order
    postconditoin: none 
*/

void Linked_List::print_list()
{
  Node* current;
  current = head; 

  while (current != NULL) {
    std::cout << current->value << std::endl; 
    current = current->next;
  }
}
