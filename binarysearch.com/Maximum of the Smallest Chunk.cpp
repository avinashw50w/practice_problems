/*You are given a list of positive integers nums and an integer k. You must split the list into 
k contiguous chunks. The smallest chunk is the one whose sum is the smallest out of all the 
chunks. Return the maximum possible value of the smallest chunk.

Constraints

1 ≤ k ≤ n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [1, 5, 3, 4, 7]
k = 3
Output
6*/
// binary search the ans, for a particular sum = mid, count the chunks required,
// if chunks required are more than k, then search the right half, else the left half
typedef long long ll;

int solve(vector<int>& a, int k) {
    int n = a.size();
    ll l = 0, r = 1e15, ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        ll sum = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + a[i] >= mid) {
                sum = 0;
                cnt++;
            }
            sum += a[i];
        }
        cnt++;
        
        if (cnt >= k) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    return ans;
}