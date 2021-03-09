/*Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.



Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n, INT_MIN);
        int mx = INT_MIN;
        for (int i = 0; i < k; ++i) {
            mx = max(mx, a[i]);
            dp[i] = mx * (i + 1);
        }

        for (int i = k; i < n; ++i) {
            mx = a[i];
            // find the maximum of the subarray [i-j + 1, i]
            for (int j = 1; j <= k; ++j) {
                mx = max(mx, a[i - j + 1]);
                dp[i] = max(dp[i], mx * j + dp[i - j]);
            }
        }

        return dp[n - 1];
    }
};