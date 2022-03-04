/*You are given a list of integers nums and integer k. Return the maximum sum of elements that 
you can remove given that you must pop exactly k times, where each pop can be from the left or 
the right end.

Constraints

k ≤ n ≤ 100,000 where n is length of nums.
Example 1
Input
nums = [1, 3, 4, 2, 0]
k = 2
Output
4*/
int solve(vector<int>& a, int k) {
    int n = a.size();
    if (k > n) return 0;
    const int inf = 1e9 + 7;
    int sum = 0, ans = -inf;
    for (int i = 0; i < k; ++i) sum += a[i];
    ans = max(ans, sum);
    for (int i = 0; i < k; ++i) {
        sum -= a[k-1-i];
        sum += a[n-1-i];
        ans = max(ans, sum);
    }
    return ans;
}