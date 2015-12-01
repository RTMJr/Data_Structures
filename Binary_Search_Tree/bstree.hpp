#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>


struct Node {
  int value;
  Node* left_child;
  Node* right_child;
};

class BSTree {
  public:
    BSTree();
    ~BSTree();
    void add(int value);
    bool contains(int value);
    void remove(int value);
    void get_values(); // in-order
    int get_size();
  private:
    Node* root;
    Node* _add_node(Node* current, int value);
    Node* _remove_node(Node* current, int value);
    int _left_most(Node* current);
    Node* _remove_left_most(Node* current);
    void _inorder(Node* current);
    bool _contains(Node* current, int value);
    void _remove(Node* current);
    int size;
};



#endif // BST_HPP
