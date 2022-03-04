/*Given a list of integers pushes, and another list of integers pops, return whether this is a 
valid sequence of stack push and pop actions.

Constraints

n ≤ 100,000 where n is the length of pushes
m ≤ 100,000 where m is the length of pops
Example 1
Input
pushes = [0, 1, 4, 6, 8]
pops = [1, 0, 8, 6, 4]*/

bool solve(vector<int>& pushes, vector<int>& pops) {
    int n = pushes.size();
    stack<int> st;

    for (int i = 0, j = 0; i < n; ++i) {
        st.push(pushes[i]);

        while (st.size() and j < n and st.top() == pops[j]) {
            cout<<"popped: "<<st.top()<<endl;
            st.pop();
            j++;
        }
    }
    
    return j == n;
}