/*Given a list of integers nums, and an integer k, return whether the list can be split into 
lists where each list contains k integers and is consecutively increasing.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [3, 2, 3, 4, 5, 1]
k = 3
Output
true
Explanation
We can split the list into [1, 2, 3] and [3, 4, 5]

Store the frequencies of all array elements in a HashMap
Traverse the HashMap.
For every element present in the HashMap, check if all its occurrences can be grouped in a 
subsets with its next (K – 1) consecutive elements or not. If so, reduce the frequencies of the 
elements included in the subsets accordingly in the HashMap and proceed forward.
If any element is found which cannot be grouped into a subset of K consecutive elements, print 
False. Otherwise print True.*/

bool solve(vector<int>& a, int k) {
    int n = a.size();
    map<int,int> mp;
    for (int e: a) mp[e]++;
    for (auto p: mp) {
        int curr = p.first;
        int cnt = p.second;
        if (cnt) {
            for (int i = 1; i < k; ++i){
                if (mp.count(curr + i) == 0) return false;
                mp[curr + i] -= cnt;
                if (mp[curr + i] < 0) return false;
            }
        }
    }
    return true;
}