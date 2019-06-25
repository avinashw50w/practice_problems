/*Remove edges connected to a node such that the three given nodes are in different trees
Given a binary tree and 3 nodes a, b and c, the task is to find a node in the tree such that 
after removing all the edge connected to that node, a, b and c are in three different trees.

Given below is a tree with input nodes as c, j and o.
Example Tree

In the above tree, if node i gets disconnected from the tree, then the given nodes c, j, and o 
will be in three different trees which have been shown below.

A simple approach is to find LCA of all possible pairs of nodes given.
Let,

lca of ( a, b) = x
lca of (b, c) = y
lca of (c, a) = z
In any case, either of (x, y), (y, z), (z, x) or (x, y, z) will always be the same. In the first three cases, 
return the node which is not the same. In the last case returning any node of x, y or z will give the answer.*/

#include <bits/stdc++.h> 
using namespace std; 
  
// node class 
struct Node { 
    int key; 
    struct Node *left, *right; 
}; 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return (temp); 
} 
  
struct Node* findLCA(struct Node* root, int n1, int n2) 
{ 
    // Base case 
    if (root == NULL) 
        return NULL; 
  
    if (root->key == n1 || root->key == n2) 
        return root; 
  
    Node* left_lca = findLCA(root->left, n1, n2); 
    Node* right_lca = findLCA(root->right, n1, n2); 
  
    if (left_lca && right_lca) 
        return root; 
  
    return (left_lca != NULL) ? left_lca : right_lca; 
} 
  
Node* findNode(Node* root, int a, int b, int c) 
{ 
    Node* x = findLCA(root, a, b); 
  
    Node* y = findLCA(root, b, c); 
  
    Node* z = findLCA(root, c, a); 
  
    if (x->key == y->key) 
        return z; 
    else if (x->key == z->key) 
        return y; 
    else
        return x; 
} 
  
int main() 
{ 
    // Declare tree 
    // Insert elements in the tree 
    Node* root = newNode(1); 
  
    root->left = newNode(2); 
    root->right = newNode(3); 
  
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
  
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(11); 
  
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->left = newNode(12); 
    root->right->left->right = newNode(13); 
    root->right->right->left = newNode(14); 
    root->right->right->right = newNode(15); 
  
    /* 
            1 
        /     \ 
       2       3 
     /  \     /  \ 
    4   5     6    7 
   /\  / \   / \  / \ 
  8 9 10 11 12 13 14 15      
                           */
  
  // here all the edges of 3 has to be removed so that 5, 6, 15 will be in a different tree each
    // update all the suitable_children 
    // keys of all the nodes in O( N ) 
  
    cout << "Disconnect node "
         << findNode(root, 5, 6, 15)->key 
         << " from the tree"; 
  
    return 0; 
} 
