#include "graph.hpp"


int main(int argc, char* argv[])
{
  Graph my_graph(6);

  my_graph.add_edge(0,1);  
  my_graph.add_edge(2,3);
  my_graph.add_edge(4,5);
  my_graph.add_edge(0,5);
  my_graph.add_edge(2,4);
  my_graph.add_edge(5,1);
  my_graph.add_edge(0,3);

  my_graph.BFS(0);

  

  return 0;
}
