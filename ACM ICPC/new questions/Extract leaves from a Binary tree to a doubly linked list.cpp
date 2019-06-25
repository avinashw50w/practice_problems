/*Extract Leaves of a Binary Tree in a Doubly Linked List
Given a Binary Tree, extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. 
Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. 
In DLL, left means previous pointer and right means next pointer.

Let the following be input binary tree
        1
     /     \
    2       3
   / \       \
  4   5       6
 / \         / \
7   8       9   10


Output:
Doubly Linked List
7<->8<->5<->9<->10  */

/*We need to traverse all leaves and connect them by changing their left and right pointers. We also need to remove them from 
Binary Tree by changing left or right pointers in parent nodes. There can be many ways to solve this. In the following implementation, 
we add leaves at the beginning of current linked list and update head of the list using pointer to head pointer. Since we insert at 
the beginning, we need to process leaves in reverse order. For reverse order, we first traverse the right subtree then the left subtree. 
We use return values to update left or right pointers in parent nodes.*/

Node* extractLeaves(Node *root, Node **head) {

	if(root == NULL) return NULL;

	// if it is a leaf node, pushit to the head of the DLL
	if(!root->left and !root->right) {

		root->right = *head;

		if(*head) (*head)->left = root;

		*head = root;

		// make the leaf node NULL and return (ie, extract the leaf node from the tree)
		return NULL;
	}

	root->right = extractLeaves(root->right, head);
	root->left = extractLeaves(root->left, head);

	return root;
}

