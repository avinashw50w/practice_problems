/*A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.*/

class Solution {
    static const int maxn = 5001;
    vector<int> g[maxn];
public:
    
    bool isAdjacent(string a, string b) {
        if (a.length() != b.length()) return false;
        int cnt = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 1;
    }
    
    int bfs(vector<string> words, int st, string end) {
        queue<array<int, 2>> q;
        q.push({st, 1});
        vector<bool> vis(maxn + 1);
        
        while (q.size()) {
            int u = q.front()[0];
            int t = q.front()[1];
            q.pop();
            vis[u] = true;

            if (words[u] == end) return t;
            
            for(int v: g[u]) {
                if (!vis[v]) {
                    q.push({ v, t + 1 });
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> words;
        words.push_back(beginWord);
        for (string w: wordList) words.push_back(w);
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isAdjacent(words[i], words[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
    
        return bfs(words, 0, endWord);
    }
};