/*We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["babca","bbazb"] and deletion indices {0, 1, 4}, then the final array after deletions is ["bc","az"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has every element (row) in lexicographic order.

For clarity, A[0] is in lexicographic order (ie. A[0][0] <= A[0][1] <= ... <= A[0][A[0].length - 1]), A[1] is in lexicographic order (ie. A[1][0] <= A[1][1] <= ... <= A[1][A[1].length - 1]), and so on.

Return the minimum possible value of D.length.

 

Example 1:

Input: ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is A = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. A[0][0] <= A[0][1] and A[1][0] <= A[1][1]).
Note that A[0] > A[1] - the array A isn't necessarily in lexicographic order.*/

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A[0].size();
        int dp[n];
        fill(dp, dp + n, 1);
        
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                int flag = 0;
                for (string s: A) {
                    if (s[i] > s[j]) {
                        flag = 1;
                        break;
                    }
                }
                
                if (flag) continue;
                
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        
        return n-ans;
    }
};