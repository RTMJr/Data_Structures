#include "graph.hpp"


int main(int argc, char* argv[])
{
  Graph my_graph(5);

  my_graph.add_edge(1, 5);

  my_graph.print_graph();

  std::cout << std::endl;

  std::cout << "Are vertex 1 and vertex 5 adjacent? : " << my_graph.is_adjacent(2, 5) << std::endl;
  
  return 0;
}
