// Implementation file for graph.hpp

#include "graph.hpp"

// constructor

Graph::Graph(int vertex_count) : vertex_count(vertex_count)
{
  adj_matrix = new int* [vertex_count];
  for (int i = 0; i < vertex_count; i++) {
    adj_matrix[i] = new int [vertex_count];
    for (int j = 0; j < vertex_count; j++) {
      adj_matrix[i][j] = 0;
    }
  }
}
  
  
// destructor

Graph::~Graph()
{
  for (int i = 0; i < vertex_count; i++) 
    delete [] adj_matrix[i];

  delete [] adj_matrix;
}

// add_edge(int origin, int destination) -- 
// places a (1) in the index of the origin and destination
// parameters: int origin, and int destination
// preconditions: origin and destination are within index range of vertex_count
// postconditions: (1) placed in the index of the origin and destination

void Graph::add_edge(int origin, int destination)
{
  if ((origin < 0) || (origin > vertex_count) ||
      (destination < 0) || (destination > vertex_count)) {
      std::cout << "Edge out of range! Exiting from program!" << std::endl;
      std::exit(EXIT_FAILURE);
  } else {
      adj_matrix[origin - 1][destination - 1] = 1;
  }
}

// remove_edge(int origin, int destination) -- 
// places a (0) in the index of the origin and destination
// parameters: int origin, and int destination
// preconditions: origin and destination are within index range of vertex_count
// postconditions: (0) placed in the index of the origin and destination


void Graph::remove_edge(int origin, int destination)
{
  if ((origin < 0) || (origin > vertex_count) ||
      (destination < 0) || (destination > vertex_count)) {
      std::cout << "Edge out of range! Exiting from program!" << std::endl;
      std::exit(EXIT_FAILURE);
  } else {
      adj_matrix[origin - 1][destination - 1] = 0;
  }
}

// is_adjacent(int origin, int destination) -- 
// checks to see if there is an edge between origin and destination 
// parameters: int origin, and int destination
// preconditions: origin and destination are within index range of vertex_count
// postconditions: returns true if edge exists, or false if not


bool Graph::is_adjacent(int origin, int destination)
{
  if ((origin < 0) || (origin > vertex_count) ||  
      (destination < 0) || (destination > vertex_count)) {
      std::cout << "Edge out of range! Exiting from program!" << std::endl;
      std::exit(EXIT_FAILURE);
  }

  if (adj_matrix[origin - 1][destination - 1] == 1) {
    return true;
  } else {
      return false;
  }
}

// print_graph() -- 
// prints the adjacenceny matrix
// parameters: none 
// preconditions: adjacency matrix exists 
// postconditions: prints the adjacency matrix 
      
void Graph::print_graph()
{
  for (int i = 0; i < vertex_count; i++) {
    for (int j = 0; j < vertex_count; j++) {
      std::cout << adj_matrix[i][j] << '\t';
    }
    std::cout << std::endl;
  }
}
