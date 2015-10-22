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
    Linked_List(const Linked_List& list);
    void insert_at_head(int new_value);
    void print_list(const Linked_List& list);
    int get_size() const { return size; };
    Node* get_head() const { return head; };
  private:
    Node* head;
    int size;
};

#endif // LINKED_LIST_HPP
