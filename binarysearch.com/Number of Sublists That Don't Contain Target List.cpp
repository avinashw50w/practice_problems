/*You are given a list of integers nums and a list of unique integers target. Return the number 
of non-empty sublists in nums that don't contain every number in target. Mod the result by 
10^9 + 7.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
0 ≤ m ≤ 100,000 where m is the length of target
Example 1
Input
nums = [1, 2, 2]
target = [1, 2]
Output
4*/
const int mod = 1e9 + 7;

int solve(vector<int>& nums, vector<int>& target) {
    unordered_set<int> st;
    for (int e: target) st.insert(e);
    unordered_map<int,int> f;
    int n = nums.size(), cnt = 0, ans = 0;

    for (int end = 0, start = 0; end < n; ++end) {
        if (st.count(nums[end])) f[nums[end]]++;
        while (start <= end and f.size() == target.size()) {
            if (st.count(nums[start])) {
                f[nums[start]]--;
                if (f[nums[start]] == 0) f.erase(nums[start]);
            }
            start++;
        }

        ans += end - start + 1;
        if (ans >= mod) ans -= mod;
    }

    return ans;
}