#include "hashtable.hpp"



int main(int argc, char* argv[])
{
  Hashtable my_hashtable;
  
  my_hashtable.insert(0, 5);
  my_hashtable.insert(1, 100);
  my_hashtable.insert(2, 45);
  my_hashtable.insert(3, 26);
  my_hashtable.insert(4, 300);

  my_hashtable.print_table();


  return 0;
}
