/*
  Author: Richard Mitchell
  Date: 10/2/15  
  Description: This .cpp file contains the implementation for the class Dynamic_Array

*/

#include "dynamic_array.hpp"


Dynamic_Array::Dynamic_Array()
{
  capacity = 5;
  size = 0;
  data = new int[capacity];
}

Dynamic_Array::Dynamic_Array(int the_capacity)
{
  capacity = the_capacity;
  size = 0;
  data = new int[capacity];
}

Dynamic_Array::~Dynamic_Array()
{
  delete [] data;
}

Dynamic_Array::Dynamic_Array(const Dynamic_Array &original)
{
  size = original.size;
  data = new int[original.capacity];
  for (int i = 0; i < size; ++i)
    data[i] = original.data[i];
}

void Dynamic_Array::push_back(int element)
{
  if (size == capacity) {
    int* new_data;
    new_data = new int[2 * capacity];

    for (int i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }
  
    new_data[size] = element;
    ++size;
    capacity = 2 * capacity;
    delete [] data;
    data = new_data; 

  } else {
      data[size] = element;
      ++size;
  }
}

int Dynamic_Array::at(int index)
{
  return data[index];
}

int Dynamic_Array::front()
{
  return data[0];
}

int Dynamic_Array::back()
{
  return data[size - 1];
}

void Dynamic_Array::remove(int index)
{
  for (int i = index; i < size - 1; ++i) {
    data[i] = data[i + 1];
  }
  --size;
}


int Dynamic_Array::get_size()
{
  return size;
}

int Dynamic_Array::get_capacity()
{
  return capacity;
}
