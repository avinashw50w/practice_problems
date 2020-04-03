/*Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.*/

/*Solution

This is a basic graph problem. It can be solved via either DFS or BFS.
One thing need to pay attention is that this is a graph not a tree, which mean it is possible to contain cycles. 
If cycles are not handled properly, it could result in infinite loops.

Implementation with DFS */

struct Node {
	int label;
	vector<Node*> neighbors;

	Node(int x) { label = x; }
};


Node* cloneGraph(Node *root, map<Node*, Node*> &vis) {
	if(root == NULL) return root;

	Node *node = new Node(root->label);

	vis[root] = node;

	// DFS
	for(auto nb: root->neighbors) {
		// if the neighbors have been visited
		if(vis.count(nb) != 0)
			node->neighbors.push_back(vis[nb]);

		else // otherwise visit them
			node->neighbors.push_back(cloneGraph(nb, vis));
	}

	return node;
}

