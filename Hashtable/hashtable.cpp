#include "hashtable.hpp"


Hashtable::Hashtable()
{
  h_table = new Hash_Entry*[TABLE_SIZE];

  for (int i = 0; i < TABLE_SIZE; i++) {
    h_table[i] = NULL;
  }
}

Hashtable::~Hashtable()
{
  for (int i = 0; i < TABLE_SIZE; ++i) {
    delete h_table[i];
  }
  delete [] h_table;
}

void Hashtable::insert(int key, int value)
{
  int hash = _hash_func(key);

  while ((h_table[hash] != NULL) && (h_table[hash]->key != key)) {
    hash = _hash_func(hash + 1);
  }

  if (h_table[hash] != NULL) 
    delete h_table[hash];

  Hash_Entry* new_entry = new Hash_Entry;
  new_entry->key = key;
  new_entry->value = value;
  h_table[hash] = new_entry;
}


int Hashtable::search(int key)
{
  int hash = _hash_func(key);
  
  while ((h_table[hash] != NULL) && (h_table[hash]->key != key)) {
    hash = _hash_func(hash + 1);
  }

  if (h_table[hash] == NULL) { 
    return -1;
  } else {
      return h_table[hash]->value;
  }
}

void Hashtable::remove(int key)
{
  int hash = _hash_func(key);

  while ((h_table[hash] != NULL) && (h_table[hash]->key != key)) {
    hash = _hash_func(hash + 1);
  }

  if (h_table[hash] != NULL) {
    delete h_table[hash];
  } else {
      std::cout << "Element not found." << std::endl;
  }
}

int Hashtable::_hash_func(int key)
{
  return (key % TABLE_SIZE);
}

void Hashtable::print_table()
{
  for (int i = 0; i < TABLE_SIZE; ++i) {
    std::cout << "Hashtable index [" << i << "] key = ";
    std::cout << h_table[i]->key << " and value = " << h_table[i]->value;
    std::cout << std::endl;
  }
}
