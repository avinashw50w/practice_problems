/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, ' ');
        for (int i = 1; i <= n; ++i) s[i-1] = i + '0';
        int cnt = 1;
        while (cnt < k) {
            next_permutation(s.begin(), s.end());
            cnt++;
        }
        
        return s;
    }
};