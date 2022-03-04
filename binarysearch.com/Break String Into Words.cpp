/*Given a list of lowercase alphabet strings words and a lowercase alphabet string s, return 
whether or not the string can be broken down using the list of words. It's not required to use 
all of the words and you can reuse words.

Example 1
Input
words = ["quick", "brown", "the", "fox"]
s = "thequickbrownfox"
Output
true
*/
bool solve(vector<string>& words, string s) {
    unordered_set<string> dict;
    for (string word: words) dict.insert(word);
    int n = s.length();
    // dp[i] - true if s[0..i] can be broken into words
    vector<bool> dp(n);
    for (int i = 0; i < n; ++i){
        string left = s.substr(0, i + 1);
        if (dict.count(left)) dp[i] = true;
        else continue;
        
        for (int j = i + 1; j < n; ++j) {
            string right = s.substr(i+1, j-i);
            if (dict.count(right)) dp[j] = true;
        
            if (dp[n-1]) return true;
        }
    }
    return dp[n-1];
}