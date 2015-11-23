// Implementation file for graph.hpp

#include "graph.hpp"

// constructor

Graph::Graph()
{
  size = 0;
  vertex_list = {};
}
  
  
// destructor

Graph::~Graph()
{
  // empty 
}

// add_vertex(Vertex* vertex): adds a vertex to the Graph
// Parameters: a vertex
// Precondition: the vertex is not null
// Postcondition: the vertex is included in the vertex list set for the Graph

void Graph::add_vertex(Vertex* vertex)
{
  vertex_list.push_back(vertex);
  size++;
}

// adjacent(Vertex* vertex_a, Vertex* vertex_b): checks to see if vertex_a is adjacent to vertex_b
// Parameters: vertex_a, and vertex_b
// Precondition: vertex_a and vertex_b are not null
// Postcondition: none

bool Graph::adjacent(Vertex* vertex_a, Vertex* vertex_b)
{
  std::list<Vertex*>::iterator iter;

  iter = vertex_a->neighbors.begin();

  while (iter != vertex_a->neighbors.end()) {
    if ((*iter) == vertex_b) 
      return true;
    iter++;
  }
  return false;
}

// neighbors(Vertex* vertex): prints out all adjacent vertices to the vertex
// Parameters: vertex
// Precondtion: vertex is not null
// Postcondition: none 

void Graph::neighbors(Vertex* vertex)
{
  std::list<Vertex*>::iterator iter;
  iter = vertex->neighbors.begin();

  while (iter != vertex->neighbors.end()) {
    if (iter == --vertex->neighbors.end()) {
      std::cout << (*iter)->name << std::endl;
    } else {
        std::cout << (*iter)->name << " -> ";
    }
    iter++;
  }
}

// remove_vertex(Vertex* vertex): removes vertex from graph vertex list, and subsequent 
// adjacent vertices lists
// Parameters: vertex
// Precondition: vertex is not null
// postcondition: the vertex is no longer in the graph vertex list, and subsequent adjacent
// vertices lists

void Graph::remove_vertex(Vertex* vertex)
{
  std::vector<Vertex*>::iterator v_iter;

  for (v_iter = vertex_list.begin(); v_iter != vertex_list.end(); v_iter++) {
    if ((*v_iter) == vertex) {
      vertex_list.erase(v_iter);
      if (v_iter++ == vertex_list.end()) {
        break;
      }
    }
  }

  for (v_iter = vertex_list.begin(); v_iter != vertex_list.end(); v_iter++) {
    std::list<Vertex*>::iterator n_iter; 
    n_iter = (*v_iter)->neighbors.begin();
    while (n_iter != (*v_iter)->neighbors.end()) {
      if ((*n_iter) == vertex) {
        (*v_iter)->neighbors.erase(n_iter);
        break;
      }
      n_iter++;
    }
  }
  size--;
}

// add_edge(Vertex* vertex_a, Vertex* vertex_b): adds an edge between vertex_a and vertex_b
// parameters: vertex_a, vertex_b
// Precondition: vertex_a and vertex_b are not null
// Postcondition: an edge connects vertex_a to vertex_b

void Graph::add_edge(Vertex* vertex_a, Vertex* vertex_b)
{
  vertex_a->neighbors.push_back(vertex_b);
}

// remove_edge(Vertex* vertex_a, Vertex* vertex_b): removes the edge between vertex_a and
// vertex_b
// Parameters: vertex_a, and vertex_b
// Precondition: vertex_a, and vertex_b are not null, and connect by an edge
// Postcondition: vertex_a and vertex_b are no longer connected to each other

void Graph::remove_edge(Vertex* vertex_a, Vertex* vertex_b)
{
  std::list<Vertex*>::iterator iter;
  iter = vertex_a->neighbors.begin();

  while (iter != vertex_a->neighbors.end()) {
    if ((*iter) == vertex_b) { 
      vertex_a->neighbors.erase(iter);
      break;
    }
    iter++;
  }
}

// get_vertex_value(Vertex* vertex): returns the numerical value of the vertex
// Parameters: vertex 
// Precondition: vertex is not null
// Postcondition: none

int Graph::get_vertex_value(Vertex* vertex)
{
  return vertex->value;
}

// set_vertex_value(Vertex* vertex, int the_value): sets an int value to vertex
// Parameters: vertex, and the int value
// Precondition: vertex is not null
// Postcondition: vertex's new value is the int value

void Graph::set_vertex_value(Vertex* vertex, int the_value)
{
  vertex->value = the_value;
}

// get_vertex_name(Vertex* vertex): retrieves the vertex name from the vertex
// Parameters: vertex
// Precondition: vertex is not null
// Postcondition: none

std::string Graph::get_vertex_name(Vertex* vertex)
{
  return vertex->name;
}

// set_vertex_name(Vertex* vertex, std::string the_name): sets the vertex to the string name
// Parameters: vertex, and the string name
// Precondition: vertex is not null
// Postcondition: the vertex's name is the string name

void Graph::set_vertex_name(Vertex* vertex, std::string the_name)
{
  vertex->name = the_name;
}

// get_size(): returns the size of the graph (total vertices)
// parameters: none
// precondition: none
// postcondtion: none

int Graph::get_size()
{
  return size;
}
