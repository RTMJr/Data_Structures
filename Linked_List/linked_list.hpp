/* API for linked list */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

struct Node {
  int value;
  Node* next;
};

class Linked_List {
  public:
    Linked_List();
    ~Linked_List();
    Linked_List(const Linked_List& list_head);
    void insert_node(int node_value);
    void print_list(const Linked_List& list_head);
  private:
    Node* head;
    int size;
};

#endif // LINKED_LIST_HPP
