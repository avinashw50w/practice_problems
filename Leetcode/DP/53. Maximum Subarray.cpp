/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.*/

class Solution {
    typedef long long ll;
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        ll prefix = nums[0];
        ll ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefix = max((ll)nums[i], prefix + nums[i]);
            ans = max(ans, prefix);
        }
        
        return ans;
    }
};


//////////////////////////////////////////
class Solution {
    typedef long long ll;
    const ll INF = 1e18;
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> dp(n, -INF);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
            dp[i] = max((ll)nums[i], nums[i] + dp[i-1]);
        
        return *max_element(dp.begin(), dp.end());
    }
};