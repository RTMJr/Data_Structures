#include "stack.hpp"

/* constructor */

Stack::Stack() : size(0) 
{
  data = new Doubly_Linked_List;
}

/* destructor */

Stack::~Stack()
{
  delete data;
}

/* copy constructor */

Stack::Stack(const Stack& the_stack) 
{
  data = new Doubly_Linked_List;
  size = the_stack.data->get_size();

  data->set_head(NULL);
  data->set_tail(NULL);

  Node* current;
  Node* copy_current; 
  current = the_stack.data->get_head();
  copy_current = new Node;

  if (the_stack.data->get_size() == 0) 
    return;
  
  if (the_stack.data->get_size() == 1) {
    copy_current->prev = data->get_head();
    copy_current->next = data->get_tail();
    copy_current->value = current->value;
    data->set_head(copy_current);
    data->set_tail(copy_current);
    return;
  }

  copy_current->prev = data->get_head();
  data->set_head(copy_current);

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

  data->set_tail(copy_current);
  copy_current->next = NULL;

} 

/*  top
    parameters: none
    precondition: none
    postcondtion: none

    returns top int value on stack
*/

int Stack::top()
{
  return data->get_head()->value;
}

/*  push
    parameters: new int value
    precondition: stack does not contain new int value
    postcondition: stack now contains new int value, stack size +1
*/

void Stack::push(int new_value)
{
  data->insert_at_head(new_value);
  size++;
}

/*
    pop
    parameters: none
    precondition: top value on stack is present
    postcondtion: top value on stack is removed
*/

/*  pop
    parameter: none
    precondition: the stack is of length N
    postcondition: the top value is removed, and the stack is of length N - 1
*/

void Stack::pop()
{
  Node* temp;
  temp = data->get_head();
  data->set_head(data->get_head()->next);
  delete temp;
  size--;
}

/*
  get_size
  parameters: none
  precondition: none
  postcondition: none

  prints the size of the stack
*/

int Stack::get_size()
{
  return size;
}

/*
  view_stack
  parameters: none
  precondition: none
  postcondition: none

  prints the stack out
*/

void Stack::view_stack()
{
  data->print_list_head();
}
