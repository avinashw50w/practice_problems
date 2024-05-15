/*Given two trees root0 and root1, return whether you can transform root0 into root1 by swapping any node's left and right subtrees any number of times.
*/
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root0, Tree* root1) {
    if (!root0 and !root1) return true;
    if ((!root0 or !root1) or root0->val != root1->val) return false;
    // no swapping
    bool op1 = solve(root0->left, root1->left) and solve(root0->right, root1->right);
    // swapping
    bool op2 = solve(root0->left, root1->right) and solve(root0->right, root1->left); 

    return op1 or op2;
}