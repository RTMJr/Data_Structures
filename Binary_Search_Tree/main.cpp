#include "bstree.hpp"


int main(int argc, char* argv[])
{
  BSTree my_bstree;

  my_bstree.add(5);
  my_bstree.add(1);
  my_bstree.add(6);
  
  my_bstree.get_values();
  std::cout << "size: " << my_bstree.get_size() << std::endl;

  std::cout << std::endl;

  std::cout << "Does the binary search tree contain 6? : ";
  std::cout << my_bstree.contains(5) << std::endl;


  my_bstree.get_values();

  return 0;
}
