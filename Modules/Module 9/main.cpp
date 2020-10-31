#include "BST.h"

BST::BST() { root = NULL; } //constructor

void BST::insert(int val) { root = insert(root, val); } //insert val

BSTNode* BST::insert(BSTNode *node, int val)
{
  if (node == NULL)
  {
    node = new BSTNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
  }
  else
  {
    if (value < node->value)
    {
      node->left = insert(node->left, val);
    }
    else
    {
      node->right = insert(node->right, val);
    }
  }
  return node;
}

void BST::remove(int val)
{
  if (root != NULL)
  {
    if (root->value == value)
    {
      if(root->left == NULL && root->right == NULL) root = NULL;
      else if (root->left == NULL) root = root->right;
      else if (root->right == NULL) root = root->left;
      else
      {
        BSTNode * p = root->right;
        while (p->left != NULL)
        {
          p = p->left;
        }
        p->left = root->left;
        root = root->right;
      }
      return;
    }
    BSTNode *node = root;
    BSTNode *parent = NULL;
    bool found = false;
    while (node != NULL && !found)
    {
      if (node->value == value)
      {
        found = true;
        break;
      }
      parent = node;
      if (value < node->value)
      {
        node = node->left;
      }
      else
      {
        node = node->right;
      }
    }
    if (found)
    {
      if (node->left == NULL && node->right == NULL)
      {
        if (parent->left == node)
        {
          parent->left = NULL;
        }
        else
        {
          parent->right = NULL;
        }
      }
      else if (node->left == NULL)
      {
        if(parent->left == node)
        {
          parent->left = node->right;
        }
        else
        {
          parent->right = node->right;
        }
      }
      else if (node->right == NULL)
      {
        if(parent->left == node)
        {
          parent->left = node->left;
        }
        else
        {
          parent->right = node->left;
        }
      }
      else
      {
        BTSNode *p = node->right;
        while(p->left != NULL)
        {
          p = p->left;
        }
        p->left = node->left;
        if (parent->left == node)
        {
          parent->left = node->right;
        }
        else
        {
          parent->right = node->right;
        }
      }
      delete node;
    }
    }
  }
}
