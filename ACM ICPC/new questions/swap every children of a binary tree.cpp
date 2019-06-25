// swap every child of a binary tree

// simply do postorder traversal and swap the children from bottom to top

void swapChild(Node *root) {
	if (!root || (!root->left and !root->right)) return;
	
	swapChild(root->left);
	swapChild(root->right);
	
	if (root->left and root->right)
		swap(root->left, root->right);
}
