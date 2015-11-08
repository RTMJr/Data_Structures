/* Implementation for doubly_linked_list.hpp */

#include "doubly_linked_list.hpp"
#include <iostream>

/* Default constructor */

Doubly_Linked_List::Doubly_Linked_List()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

/* Destructor */

Doubly_Linked_List::~Doubly_Linked_List()
{
  Node* current;
  Node* temp;

  if (this->get_size() == 0)
    return;

  current = this->get_head();

  while (current != NULL) {
    temp = current;
    current = current->next;
    delete temp;
  }

}

/* copy constructor */

Doubly_Linked_List::Doubly_Linked_List(const Doubly_Linked_List& list) 
                                      : size(list.get_size())
{
  head = NULL; 
  tail = NULL;

  Node* current;
  Node* copy_current; 
  current = list.get_head();
  copy_current = new Node;

  if (list.get_size() == 0) 
    return;

  if (list.get_size() == 1) {
    copy_current->prev = head;
    copy_current->next = tail;
    copy_current->value = current->value;
    head = tail = copy_current;
    return;
  }

  copy_current->prev = head;
  head = copy_current;

  while (current != NULL) {
    copy_current->value = current->value;
    if (current->next != NULL) {
      Node* new_node;
      new_node = new Node;
      new_node->prev = copy_current;
      copy_current->next = new_node;
      copy_current = new_node;
    }
    current = current->next;
  }

  tail = copy_current;
  copy_current->next = NULL;
} 

/*  insert_at_head
    parameters: new int value
    precondition: linked list does not have new int value
    postconditoin: linked list contains new int value
*/

void Doubly_Linked_List::insert_at_head(int new_value)
{
  Node* new_node;  
  new_node = new Node;

  if (this->get_size() == 0) {
    new_node->value = new_value;
    new_node->next = this->tail;
    this->tail = new_node;
    new_node->prev = this->head;
    this->head = new_node;
    size++;
    return;
  }
    
  new_node->value = new_value;
  new_node->next = this->head;
  new_node->prev = this->head->prev;
  this->head->prev = new_node; 
  this->head = new_node;
  size++;
}

/*  insert_after
    parameters: new int value, previous node index
    precondition: linked list does not have new int value
    postconditoin: linked list contains new int value
*/

void Doubly_Linked_List::insert_after(int new_value, int previous_node)
{ 
  int node_index = 0;
  Node* new_node;
  Node* current;
  new_node = new Node;
  new_node->value = new_value;
  current = this->head;

  if (this->get_size() == 0) {
    this->insert_at_head(new_value);
    return;
  }

  while (node_index != previous_node) {
    current = current->next;
    node_index++;
  }
  
  new_node->next = current->next;
  current->next->prev = new_node;
  current->next = new_node;
  new_node->prev = current;
  size++;
}

/*  insert_at_tail
    parameters: new int value
    precondition: linked list does not have new int value at tail
    postconditoin: linked list contains new int value at tail
*/

void Doubly_Linked_List::insert_at_tail(int new_value)
{
  Node* current;
  Node* new_node;
  new_node = new Node;
  current = this->head;
  new_node->value = new_value;

  while (current->next != NULL) {
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
  new_node->prev = current;
  size++;
}

/*  remove_at_head
    parameters: none     
    precondition: linked list has original head
    postconditoin: linked list no longer has original head
*/

void Doubly_Linked_List::remove_at_head()
{
  if (this->get_size() == 0) 
    return;

  if (this->get_size() == 1) {
    delete this->head;
    this->head = NULL;
    this->tail = this->head;
    size--;
    return;
  }

  Node* old_node;
  old_node = this->head;
  this->head = this->head->next;
  this->head->prev = old_node->prev;
  delete old_node;
  size--;

}

void Doubly_Linked_List::remove_at_tail()
{
  Node* current;
  Node* old_node;
    
  if (this->get_size() == 0)
    return;

  if (this->get_size() == 1) {
    current = this->tail;
    delete this->tail;
    this->tail = NULL;
    this->head = NULL;
    size--;
    return;
  }

  current = this->head;

  while (current->next != NULL) {
    current = current->next;
  }

  old_node = current;
  current->prev->next = current->next;
  delete old_node;
  size--;
}

/*  remove_after
    parameters: none     
    precondition: linked list has original head
    postconditoin: linked list no longer has original head
*/

void Doubly_Linked_List::remove_after(int previous_node)  
{
  int node_index = 0;
  Node* current;
  current = this->head;

  if (previous_node == 0) {
    this->remove_at_head();
    return;
  }

  while (node_index != previous_node) {
    current = current->next;
    node_index++;
  }

  Node* old_node;
  old_node = current;

  if (current->next == NULL) {
    current->prev->next = current->next;
    delete old_node;
  } else {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete old_node;
  }
  size--;
}

/*  reverse_list
    parameters: none     
    precondition: linked list in original order
    postconditoin: linked list in reverse order
*/

void Doubly_Linked_List::reverse_list()
{
  Node* current;
  Node* temp;
  current = this->head;

  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != NULL)
    this->head = temp->prev;
}

/*  print_list
    parameters: none     
    precondition: linked list in original order
    postconditoin: none 
*/

void Doubly_Linked_List::print_list_head()
{
  Node* current = this->head;

  while (current != NULL) {
    std::cout << current->value << std::endl;
    current = current->next;
  }
}

/*  print_list
    parameters: none     
    precondition: linked list in reverse order
    postconditoin: none 
*/

void Doubly_Linked_List::print_list_tail()
{
  Node* current = this->tail;

  while (current != NULL) {
    std::cout << current->value << std::endl;
    current = current->prev;
  }
}
