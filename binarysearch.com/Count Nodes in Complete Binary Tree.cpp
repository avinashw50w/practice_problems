/*Given a complete binary tree root, return the number of nodes in the tree.

This should be done in O((logn)^2).

Constraints

n ≤ 100,000 where n is the number of nodes in root
*/
int solve(Tree* root) {
    // get left and right heights of the substrees
    int left_height = 0, right_height = 0;
    Tree* curr = root;
    while (curr) left_height++, curr = curr->left;
    curr = root;
    while (curr) right_height++, curr = curr->right;
    // if left_height = right_height, then it is a full binary tree 
    // with 2^left_height - 1 # of nodes
    if (left_height == right_height) return (1<<left_height) - 1;
    return solve(root->left) + solve(root->right) + 1;
}