/*Given a list of integers nums and integers a and b, return the max sum of two non-overlapping 
sublists in nums which have lengths a and b.

Constraints

n ≤ 100,000 where n is the length of nums
1 ≤ a, b
Example 1
Input
nums = [2, 1, 9, -3, 6, 5]
a = 3
b = 1
Output
18*/
int solve(vector<int>& nums, int a, int b) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) 
        nums[i] += nums[i-1];
    
    int res = nums[a+b-1];
    int amax = nums[a-1];
    int bmax = nums[b-1];

    for (int i = a+b; i < n; ++i) {
        amax = max(amax, nums[i-b] - nums[i - (a+b)]);
        bmax = max(bmax, nums[i-a] - nums[i - (a+b)]);
        res = max(res, max(
            amax + nums[i] - nums[i-b],
            bmax + nums[i] - nums[i-a]
        ));
    }

    return res;
}


/////////////////////////////////////
// when a == b, then it's simple
int solve(vector<int>& nums, int a) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) 
        nums[i] += nums[i-1];
    
    int res = nums[2*a-1];
    int mx = nums[a-1];

    for (int i = a*2; i < n; ++i) {
        mx = max(mx, nums[i-a] - nums[i-a*2]);
        res = max(res, mx + nums[i] - nums[i-a]);
    }

    return res;
}