/*Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


Note:

There are at least two nodes in this BST.*/

class Solution {
public:
    void solve(TreeNode *root, vector<int> &v) {
        if (!root) return;
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> a;
        solve(root, a);
        int ans = INT_MAX;
        for (int i = 1; i < a.size(); ++i) ans = min(ans, a[i] - a[i - 1]);
        return ans;
    }
};