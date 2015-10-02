/*
  Author: Richard Mitchell
  Date: 10/2/15  
  Description: This .hpp file contains the class Dynamic_Array

*/

#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

class Dynamic_Array {
  public:
    Dynamic_Array();
    Dynamic_Array(int the_capacity);
    Dynamic_Array(const Dynamic_Array &original);
    ~Dynamic_Array();
    void push_back(int element);
    int at(int index);
    int front();
    int back();
    void remove(int index);
    int get_capacity();
    int get_size();

  private:
    int* data;
    int size;
    int capacity;
};

#endif
