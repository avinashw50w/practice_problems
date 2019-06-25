/*Reverse alternate levels of a perfect binary tree
Given a Perfect Binary Tree, reverse the alternate level nodes of the binary tree. 

  
Given tree: 
               a
            /     \
           b       c
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
       h  i j  k l  m  n  o 

Modified tree:
  	       a
            /     \
           c       b
         /  \     /  \
        d    e    f    g
       / \  / \  / \  / \
      o  n m  l k  j  i  h 
We strongly recommend to minimize the browser and try this yourself first.


Method 1 (Simple)

A simple solution is to do following steps.
1) Access nodes level by level.
2) If current level is odd, then store nodes of this level in an array.
3) Reverse the array and store elements back in tree.
 

Method 2 (Using Two Traversals)

Another is to do two inorder traversals. Following are steps to be followed.
1) Traverse the given tree in inorder fashion and store all odd level nodes in an auxiliary array. For the above example given tree, 
contents of array become {h, i, b, j, k, l, m, c, n, o}
2) Reverse the array. The array now becomes {o, n, c, m, l, k, j, b, i, h}

3) Traverse the tree again inorder fashion. While traversing the tree, one by one take elements from array and store elements 
from array to every odd level traversed node.For the above example, we traverse ‘h’ first in above array and replace ‘h’ with ‘o’. 
Then we traverse ‘i’ and replace it with n.*/

void reverseAlternate(Node *root) {

	int a[maxn];
	int i = 0;

	store(root, a, i, 0);

	reverse(a, i);

	i = 0;
	modify(root, a, i, 0);
}

void store(Node *root, int a[], int &i, int level) {
	if(root == NULL) return;

	store(root->left, a, i, level+1);

	if(level & 1)
		a[i++] = root->data;

	store(root->right, a, i, level+1);
}

void modify(Node *root, int a[], int i, int level) {
	if(!root) return NULL;

	modify(root->left, a, i, level+1);

	if(level & 1) root->data = a[i++];

	modify(root->right, a, i, level+1);
}