/*You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        if (N == 0) return res;
        
        unordered_map<int,int> ng;
        stack<int> st;
                
        for (int i = 0; i < N; ++i) {
            if (st.empty()) {
                st.push(nums[i]);
                continue;
            }
            
            while (!st.empty() and st.top() < nums[i]) {
                ng[st.top()] = nums[i];
                st.pop();
            }
            
            st.push(nums[i]);
        }
        
        while (!st.empty()) {
            ng[st.top()] = -1;
            st.pop();
        }
        
        for (int i = 0; i < findNums.size(); ++i) {
            res.push_back(ng[findNums[i]]);
        }
        
        return res;
    }
};