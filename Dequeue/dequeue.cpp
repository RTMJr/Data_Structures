#include "dequeue.hpp"


Dequeue::Dequeue()
{
  data = new Queue;
  size = 0;
}

int Dequeue::back()
{
  return data->back();
}

int Dequeue::front()
{
  return data->front();
}

void Dequeue::push_back(int new_value)
{
  data->push_back(new_value);
  size++;
}

void Dequeue::push_front(int new_value)
{
  Node* new_node;
  new_node = new Node;

  new_node->value = new_value;

  if (size == 0) {
    data->get_head()->next = new_node;
    new_node->prev = data->get_head();
    data->get_tail()->prev = new_node;
    new_node->next = data->get_tail();
    size++;
    return;
  }

  new_node->prev = data->get_tail()->prev;
  new_node->next = data->get_tail();
  data->get_tail()->prev->next = new_node;
  data->get_tail()->prev = new_node;
  size++;
}
  

void Dequeue::view_dequeue()
{
  data->view_queue();
}

void Dequeue::pop_front()
{
  Node* temp; 

  if (size == 0)
    return;

  if (size == 1) {
    temp = data->get_tail()->prev;
    data->get_tail()->prev = data->get_head();
    data->get_head()->next = data->get_tail();
    delete temp;
    size--;
    return;
  }

  temp = data->get_tail()->prev;
  temp->prev->next = data->get_tail();
  data->get_tail()->prev = temp->prev;
  delete temp;
  size--;
}

void Dequeue::pop_back()
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
    data->set_size(size);
    return;
  }
    
  temp = data->get_head()->next;
  data->get_head()->next = temp->next;
  temp->next->prev = data->get_head();
  delete temp;
  size--;
  data->set_size(size);
}

int Dequeue::get_size()
{
  return size;
}

