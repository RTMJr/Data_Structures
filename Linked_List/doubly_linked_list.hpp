/* API for doubly linked list */

#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

struct Node {
  int value;
  Node* prev;
  Node* next;
};

class Doubly_Linked_List {
  public:
    Doubly_Linked_List();
    ~Doubly_Linked_List();
    Doubly_Linked_List(const Doubly_Linked_List& list);
    void insert_at_head(int new_value);
    void insert_at_tail(int new_value);
    void insert_after(int new_value, int previous_node);
    void remove_at_head();
    void remove_at_tail();
    void remove_after(int previous_node);
    void reverse_list();
    void print_list_head();
    void print_list_tail();
    int get_size() const { return size; };
    void set_size(int new_size) { size = new_size; };
    Node* get_head() const { return head; };
    Node* get_tail() const { return tail; };
  private:
    Node* head;
    Node* tail;
    int size;
};

#endif // DOUBLY_LINKED_LIST_HPP
