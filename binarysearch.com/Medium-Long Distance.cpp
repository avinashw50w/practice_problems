/*Given a list of integers nums, return a new list where each element in the new list is the 
number of smaller elements to the right of that element in the original input list.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
lst = [3, 4, 9, 6, 1]
Output
[1, 1, 2, 1, 0]*/


const int maxn = 1e5+1;
int bit[maxn];

void update(int i, int val) {
    for (; i < maxn; i += i & -i) bit[i] += val;
}
int query(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += bit[i];
    return res;
}

vector<int> solve(vector<int>& a) {
    int n = a.size();
    memset(bit, 0, sizeof(bit));
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        a[i] = pos + 1;
    }

    vector<int> res(n);
    for (int i = n-1; i >= 0; --i) {
        int t = a[i] > 1 ? query(a[i]-1) : 0;
        res[i] = t;
        update(a[i], 1);
    }
    return res;
}