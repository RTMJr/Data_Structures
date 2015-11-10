#include <iostream>
#include "queue.hpp"

Queue::Queue()
{
  data = new DL_List;
  data->set_head(new Node);
  data->set_tail(new Node);
  data->get_head()->next = data->get_tail();
  data->get_tail()->prev = data->get_head();
  size = 0;
}

/*  push_back()
    parameters: new int value
    precondition: queue does not contain new int value
    postcondition: queue contains new int value, queue size increases +1
*/

void Queue::push_back(int new_value)
{
  Node* new_node;
  new_node = new Node;

  if (size == 0) {
    new_node->prev = data->get_head();
    data->get_head()->next = new_node;
    new_node->next = data->get_tail();
    data->get_tail()->prev = new_node;
    new_node->value = new_value;
    size++;
    return;
  }

  new_node->prev = data->get_head();
  new_node->next = data->get_head()->next;
  data->get_head()->next->prev = new_node;
  data->get_head()->next = new_node;
  new_node->value = new_value;
  size++;
}

/*void Queue::push_front(int new_value)
{                                                   
  Node* new_node;
  new_node = new Node;

  if (size == 0) {
    data->get_head()->next = new_node;
    new_node->prev = data->get_head();
    data->get_tail()->prev = new_node;
    new_node->next = data->get_tail();
    new_node->value = new_value;
    size++;
  }

  new_node->prev = data->get_tail()->prev;
  new_node->next = data->get_tail();
  data->get_tail()->prev->next = new_node;
  data->get_tail()->prev = new_node;
  new_node->value = new_value;
  size++;
}*/

/*
  back()
  parameters: none
  precondition: none
  postcondition: none
*/

int Queue::back()
{
  return data->get_head()->next->value;  
}

/*  front()
    parameters: none
    precondition: none
    postcondtion: none
*/

int Queue::front()
{
  return data->get_tail()->prev->value; 
}

/*
  pop_front()
  parameters: none
  precondition: front element of queue is present
  postcondtion: front element of queue is removed, queue size is -1
*/

void Queue::pop_front()
{
  Node* temp;

  if (size == 0)
    return;

  if (size == 1) {
    temp = data->get_head()->next;
    data->get_head()->next = data->get_tail();
    data->get_tail()->prev = data->get_head();
    delete temp;
    size--;
    return;
  }

  temp = data->get_tail()->prev;
  data->get_tail()->prev = data->get_tail()->prev->prev;
  data->get_tail()->prev->prev->next = data->get_tail();
  delete temp;
  size--;
}

/* 
  view_queue()
  parameters: none
  precondition: none
  postcondition: none
*/

void Queue::view_queue()
{
  Node* current = data->get_head()->next;

  while (current != data->get_tail()) {
    std::cout << current->value << std::endl;
    current = current->next;
  }
}

/*
  size()
  parameters: none
  precondtion: none
  postcondition: none
*/

int Queue::get_size()
{
  return size;
}
