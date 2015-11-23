// API for graph abstract data type

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <iostream>

struct Vertex {
  std::string name;
  int value;
  std::list<Vertex*> neighbors;
};

class Graph {
  public:
    Graph();
    ~Graph();
    void add_vertex(Vertex* vertex);
    bool adjacent(Vertex* vertex_a, Vertex* vertex_b);
    void neighbors(Vertex* vertex);
    void remove_vertex(Vertex* vertex);
    void add_edge(Vertex* vertex_a, Vertex* vertex_b);
    void remove_edge(Vertex* vertex_a, Vertex* vertex_b);
    int get_vertex_value(Vertex* vertex);
    void set_vertex_value(Vertex* vertex, int the_value);
    std::string get_vertex_name(Vertex* vertex);
    void set_vertex_name(Vertex* vertex, std::string the_name);
    int get_size();
  private:
    int size;
    std::vector<Vertex*> vertex_list;
};

#endif
