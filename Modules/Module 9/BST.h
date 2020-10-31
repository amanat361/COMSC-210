#ifndef BST_H_
#define BST_H_

#include <iostream>
using namespace std;

struct BSTNode //Binary search tree node
{
  int value;
  BSTNode* left = NULL;
  BSTNode* right = NULL;
};

class BST //Binary search tree (class)
{
private:
  BSTNode* root;
public:
  //Constructor
  BST();
  //Insert a new value function
  void insert(int val);
  //Insert new value part two
  BSTNode *insert(BSTNode *node, int value);
  //Remove a value from binary search tree
  void remove(int val);
  //Return min and max nodes
  BSTNode *findMin() const;
  BSTNode *findMax() const;
  //pre-order traversal
  void preOrderTraversal() const;
  void preOrderTraversal(BSTNode* node) const;
  //in-order traversal
  void inOrderTraversal() const;
  void inOrderTraversal(BSTNode* node) const;
  //post-order traversal
  void postOrderTraversal() const;
  void postOrderTraversal(BSTNode* node) const;
};
#endif /* BST_H_ */
