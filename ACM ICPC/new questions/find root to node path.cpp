
vector<int> path;

bool findPath(Node *root, Node *dest) {
	if(root == NULL) return false;

	if(root == dest || findPath(root->left, dest) || findPath(root->right, dest)) {
		path.push_back(root->data);
		return true;
	}

	return false;
}