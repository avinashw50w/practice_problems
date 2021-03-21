/*Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.

Input

The first input line has an integer n: the size of the array.

The second line has n integers x1,x2,…,xn: the array values.

Output

Print n integers: for each array position the nearest position with a smaller value. If there is no such position, print 0.

Constraints
1≤n≤2⋅105
1≤xi≤109
Example

Input:
8
2 5 1 4 8 3 2 5

Output:
0 1 0 3 4 3 3 7*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

int n, a[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // finding the previous lesser element
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() and a[i] < a[st.top()]) {
            res[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }

    for (int e : res) cout << e << " ";
}

/////////////////////////////////////
// another simple solution without stack
int n, a[maxn], nl[maxn];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nl[i] = i-1;
        // while nl[i] != -1 and a[nl[i]] >= a[i]
        while (~nl[i] and a[nl[i]] >= a[i])
            nl[i] = nl[nl[i]];
        cout << nl[i] + 1 << " ";
    }    
}