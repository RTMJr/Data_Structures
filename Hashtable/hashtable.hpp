#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

const int TABLE_SIZE = 5;

#include <iostream>

struct Hash_Entry {
  int key;
  int value;
};

class Hashtable {
  public:
    Hashtable();
    ~Hashtable();
    void insert(int key, int value);
    int search(int key);
    void remove(int key);
    void print_table();
  private:
    Hash_Entry** h_table;
    int _hash_func(int key);
};

#endif
