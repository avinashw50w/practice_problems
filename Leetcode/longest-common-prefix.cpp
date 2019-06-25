

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int node = 0, sz = 1;
        unordered_map<char,int> trie[(int)1e4];
        int minlen = 1e5;
        string minWord;
        
        for (int i = 0; i < s.size(); ++i) {
            node = 0;
            string word = s[i];
            
            if (word.size() < minlen) {
                minlen = word.size();
                minWord = word;
            }
            
            for (int j = 0; j < word.size(); ++j) {
                if (trie[node].count(word[j]) == 0)
                    trie[node][word[j]] = sz++;
                node = trie[node][word[j]];
            }
        }
       
        string res = "";
        node = 0;
        
        for(int i = 0; i < minWord.size(); ++i) {
            if(trie[node].size() > 1) break;
            res += minWord[i];
            node = trie[node][minWord[i]];
        }
        
        return res;
    }
};

// simple approach

string longestCommonPrefix(vector<string>& strs) {
	string ret;
	if (strs.empty())
		return ret;
	if (strs.size() == 1)
		return strs[0];
	int minLen = INT_MAX;
	for (auto&& s : strs) {
		if (s.size() < minLen)
			minLen = s.size();
	}
	if (minLen == 0)
		return ret;
	for (int i = 0; i < minLen; i++) {
		for (auto&& s : strs) {
			if (s[i] != strs[0][i]) {
				return ret;
			}
		}
		ret += strs[0][i];
	}
	return ret;
}

// python solution

class Solution(object):
    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        
        shortest_len = min([len(i) for i in strs])
        
        for i in range(shortest_len, -1, -1):
            if len(set([j[0:i] for j in strs])) == 1:
                return strs[0][0:i]
        
        return ""