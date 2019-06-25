/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int cnt = 1, mx = 1, prev;
        int f[255] = {};
        memset(f, -1, sizeof(f));
        f[s[0]] = 0;
        
        for (int i = 1; i < s.size(); ++i) {
        
            prev = f[s[i]];
            
            if (prev == -1 or i-cnt > prev) cnt++;
            else {
                mx = max(mx, cnt);
                cnt = i-prev;
            }
            
            f[s[i]] = i;
        }
        
        mx = max(mx, cnt);
        
        return mx;
    }
};