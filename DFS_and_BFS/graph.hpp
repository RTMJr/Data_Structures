#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

struct Node {
  int dest;
  bool is_visited;
  Node* next;
};

struct List {
  Node* head;
};

class Graph {
  public:
    Graph(int vertices);
    ~Graph();
    Node* create_node(int dest);
    void add_edge(int src, int dest);
    void print_graph();
    void DFS(int src);
    void BFS(int src);
  private:
    List* array;
    int v;
};
#endif
