#include "graph.hpp"

// constructor 

Graph::Graph(int vertices)
{
  v = vertices;
  array = new List[v];
  for (int i = 0; i < v; i++) {
    array[i].head = NULL;
  }
}

// destructor

Graph::~Graph()
{
  for (int i = 0; i < v; ++i) {
    Node* current = array[i].head;
    Node* temp;
    while (current != NULL) {
      temp = current->next;
      delete current;
      current = temp;
    }
  }
  delete [] array;
}

Node* Graph::create_node(int dest)
{
  Node* new_node; 
  new_node = new Node;
  new_node->dest = dest;
  new_node->is_visited = false;
  new_node->next = NULL;
  return new_node;
}

void Graph::add_edge(int dest, int src)
{
  Node* new_node = create_node(dest);
  new_node->next = array[src].head;
  array[src].head = new_node;
  new_node = create_node(src);
  new_node->next = array[dest].head;
  array[dest].head = new_node;
}

void Graph::print_graph()
{
  for (int i = 0; i < this->v; ++i) {
    Node* current = array[i].head;
    std::cout << "\n Adjacency list of vertex " << i << "\n head ";
    while (current != NULL) {
      std::cout << " -> " << current->dest;
      current = current->next;
    }
    std::cout << std::endl;
  }
}

void Graph::DFS(int src)
{
  std::stack<Node*> s;
  std::vector<int> reachable;
  s.push(array[src].head); 

  while (!s.empty()) {
    Node* vertex = s.top();
    s.pop();
    if (vertex->is_visited == false) {
      vertex->is_visited = true;
      reachable.push_back(vertex->dest);
      vertex = vertex->next;
      while (vertex != NULL) {
        if (vertex->is_visited == false) {
          s.push(vertex);
        }
        vertex = vertex->next;
      }
    }
  }

  // print reachable nodes in graph

  std::cout << "Depth First Search for " << src << ": ";
  for (int i = 0; i < reachable.size(); ++i) {
    if (i == (reachable.size() - 1)) {
      std::cout << reachable[i];
    } else {
        std::cout << reachable[i] << " -> ";
    } 
  }
  std::cout << std::endl << std::endl;
}

void Graph::BFS(int src)
{
  std::queue<Node*> q;
  std::vector<int> reachable;

  q.push(array[src].head);

  while (!q.empty()) {
    Node* vertex = q.front();
    q.pop();
    if (vertex->is_visited == false) {
      vertex->is_visited = true;
      reachable.push_back(vertex->dest);
      while (vertex != NULL) {
        if (vertex->is_visited == false) {
          q.push(vertex);
        }
        vertex = vertex->next;
      }
    }
  }

  // print reachable nodes in graph

  std::cout << "Breadth First Search for " << src << ": ";
  for (int i = 0; i < reachable.size(); ++i) {
    if (i == (reachable.size() - 1)) {
      std::cout << reachable[i];
    } else {
        std::cout << reachable[i] << " -> ";
    } 
  }
  std::cout << std::endl << std::endl;

}
    


