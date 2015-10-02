#include "dynamic_array.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
  Dynamic_Array array(5);

  std::cout << "This is the array capacity: " << array.get_capacity() 
  << std::endl;

  array.push_back(10);
  array.push_back(15);
  array.push_back(20);
  array.push_back(25);
  array.push_back(30);

  for (int i = 0; i < array.get_size(); ++i) {
    std::cout << "element at index # " << i << ": " << array.at(i) << std::endl;
  } 
  std::cout << std::endl;

  std::cout << "The array's capacity is: " << array.get_capacity() << std::endl;
  std::cout << "The array's size is: " << array.get_size() << std::endl;
  std::cout << std::endl;

  array.push_back(35);

  for (int i = 0; i < array.get_size(); ++i) {
    std::cout << "element at index # " << i << ": " << array.at(i) << std::endl;
  } 
  std::cout << std::endl;

  std::cout << "The array's capacity is: " << array.get_capacity() << std::endl;
  std::cout << "The array's size is: " << array.get_size() << std::endl;
  std::cout << std::endl;

  std::cout << "The array's first element is: " << array.front() << std::endl;
  std::cout << "The array's last element is: " << array.back() << std::endl;
  std::cout << std::endl;

  std::cout << "Removing the first element in array [10][15][20][25][30][35]" << std::endl;
  array.remove(5);
  std::cout << std::endl;

  for (int i = 0; i < array.get_size(); ++i) {
    std::cout << "element at index # " << i << ": " << array.at(i) << std::endl;
  } 
  std::cout << std::endl;



  return 0;
}
