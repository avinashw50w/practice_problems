/*Given an integer k and a list of integers nums, return the length of the longest sublist that 
contains at most k distinct integers.

Constraints

0 ≤ k ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
k = 2
nums = [0, 1, 2, 1, 0]
Output
3*/
int solve(int k, vector<int>& a) {
    int n = a.size(), ans = 0;
    unordered_map<int,int> mp;
    for (int start = 0, end = 0; end < n; ++end) {
        mp[a[end]]++;
        while (start <= end and mp.size() > k) {
            if (--mp[a[start]] == 0) mp.erase(a[start]);
            start++;            
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}