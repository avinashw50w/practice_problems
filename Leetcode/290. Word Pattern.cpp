/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false*/

class Solution {
public:
    vector<string> split(string s) {
        vector<string> res;
        stringstream ss;
        ss << s;
        string x;
        while (ss >> x) {
            res.push_back(x);
        }
        return res;
    }

    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        if (pattern.length() != words.size()) return false;

        unordered_map<string, char> mp;
        unordered_set<char> st;
        for (int i = 0; i < words.size(); ++i) {
            if (mp.count(words[i]) == 0) {
                if (st.count(pattern[i])) return false;
                mp[words[i]] = pattern[i];
                st.insert(pattern[i]);
            }
            else if (mp[words[i]] != pattern[i]) return false;
        }

        return true;
    }
};