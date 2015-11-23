#include "graph.hpp"


int main(int argc, char* argv[])
{
  Vertex *v1, *v2, *v3, *v4;

  v1 = new Vertex;
  v2 = new Vertex;
  v3 = new Vertex;
  v4 = new Vertex;

  v1->name = "a";
  v2->name = "b";
  v3->name = "c";
  v4->name = "d";

  v1->value = 5;
  v2->value = 6;
  v3->value = 3;
  v4->value = 9;

  v1->neighbors.push_back(v1);
  v1->neighbors.push_back(v3);
  v1->neighbors.push_back(v4);

  v2->neighbors.push_back(v2);
  v2->neighbors.push_back(v3);

  v3->neighbors.push_back(v3);
  v3->neighbors.push_back(v4);

  v4->neighbors.push_back(v4);
  v4->neighbors.push_back(v1);

  Graph my_graph;

  my_graph.add_vertex(v1);
  my_graph.add_vertex(v2);
  my_graph.add_vertex(v3);
  my_graph.add_vertex(v4);

  std::cout << "Graph size: " << my_graph.get_size() << std::endl;
  std::cout << "Is v1 adjacent to v2: " << my_graph.adjacent(v1, v2) << std::endl;
  std::cout << "Is v1 adjacent to v3: " << my_graph.adjacent(v1, v3) << std::endl;
  std::cout << "Is v1 adjacent to v4: " << my_graph.adjacent(v1, v4) << std::endl;

  std::cout << "V1's neighbors: ";
  my_graph.neighbors(v1);

  my_graph.remove_vertex(v4);

  std::cout << "Removing V4. V1's neighbors: ";
  my_graph.neighbors(v1);

  my_graph.add_edge(v1, v4);

  std::cout << "Adding V4 back to V1 neighbors: ";
  my_graph.neighbors(v1);

  std::cout << "Removing the edge V4 from V1: ";
  my_graph.remove_edge(v1, v4);

  my_graph.neighbors(v1);

  std::cout << "Add loop to v1: ";
  my_graph.add_edge(v1, v1);
  my_graph.neighbors(v1);

  delete v1;
  delete v2;
  delete v3;
  delete v4;
      
  return 0;
}
