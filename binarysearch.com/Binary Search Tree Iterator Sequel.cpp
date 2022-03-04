/*Implement a binary search tree iterator with the following methods:

next returns the next smallest element in the tree
hasnext returns whether there is a next element in the iterator
prev returns the next bigger element in the tree
hasprev returns whether there is a previous element in the iterator
For example, given the following tree root

   4
  / \
 2   7
    /
   5
Then we have

it = BSTIterator(root)
it.next() == 2
it.next() == 4
it.hasnext() == True
it.next() == 5
it.next() == 7
it.hasnext() == False
it.hasprev() == True
it.prev() == 5*/
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class BSTIterator {
    stack<Tree*> st;
    vector<int> history;
    int index;
    public:
    BSTIterator(Tree* root) {
        index = -1;
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        if (index + 1 < history.size()) {
            return history[++index];
        }

        Tree *next = st.top(); st.pop();
        int val = next->val;
        next = next->right;
        while (next) {
            st.push(next);
            next = next->left;
        }

        history.push_back(val);
        index++;
        return val;
    }

    bool hasnext() {
        return st.size();
    }

    int prev() {
        --index;
        return history[index];
    }

    bool hasprev() {
        return index > 0;
    }
};