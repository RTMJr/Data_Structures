#include "bstree.hpp"


// constructor 

BSTree::BSTree()
{
  root = NULL;
  size = 0;
}

// destructor 

BSTree::~BSTree()
{
  _remove(root);

}

void BSTree::add(int value)
{
  root = _add_node(root, value);
  size++;
}

void BSTree::remove(int value)
{

  root = _remove_node(root, value);
  size--;

}

void BSTree::get_values()
{
  _inorder(root);
}

bool BSTree::contains(int value)
{
  return _contains(root, value);
}

int BSTree::get_size()
{
  return size;
}


Node* BSTree::_add_node(Node* current, int value)
{
  if (current == NULL) {
    Node* new_node;
    new_node = new Node;
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
  } else if (value < current->value) {
      current->left_child = _add_node(current->left_child, value);
  } else { // value > current->value
      current->right_child = _add_node(current->right_child, value);
  }
  return current;
}

Node* BSTree::_remove_node(Node* current, int value)
{
  Node* node;
  if (value == current->value) {
    if (current->right_child == NULL) {
      node = current->left_child;
      delete current;
      return node;
    }
    current->value = _left_most(current->right_child);
    current->right_child = _remove_left_most(current->right_child);
  } else if (value < current->value) {
      current->left_child = _remove_node(current->left_child, value);
  } else {
      current->right_child = _remove_node(current->right_child, value);
  }
  return current;
}

int BSTree::_left_most(Node* current)
{ 
  while (current->left_child != NULL) {
     current = current->left_child;
  }
  return current->value;
}

Node* BSTree::_remove_left_most(Node* current)
{
  Node* new_node;

  if (current->left_child == NULL) {
    new_node = current->right_child;
    delete current;
    return new_node;
  }

  current->left_child = _remove_left_most(current->left_child);
  return current;
}

void BSTree::_inorder(Node* current)
{
  if (current == NULL)
    return;
  std::cout << current->value << std::endl;
  _inorder(current->left_child);
  _inorder(current->right_child);
}

bool BSTree::_contains(Node* current, int value)
{
  if (current == NULL)
    return false;
   
  if (current->value == value) {
    return true;
  } else if (value < current->value) {
      return _contains(current->left_child, value);
  } else {
      return _contains(current->right_child, value); 
  }
}

void BSTree::_remove(Node* current)
{
  if (current == NULL) {
    return;
  }
  _remove(current->left_child);
  _remove(current->right_child);
  delete current;
}
