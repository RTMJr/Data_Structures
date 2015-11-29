// API for graph abstract data type -- adjacency matrix

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream> // for std::cout, std::endl
#include <cstdlib> // for std::exit

class Graph {
  public:
    Graph(int vertex_count);
    ~Graph();
    void add_edge(int origin, int destination);
    void remove_edge(int origin, int destination);
    bool is_adjacent(int origin, int destination);
    void print_graph();
  private:
    int** adj_matrix;
    int vertex_count;
};

#endif
