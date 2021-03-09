/*Recently, Norge found a string 𝑠=𝑠1𝑠2…𝑠𝑛 consisting of 𝑛 lowercase Latin letters. As an exercise to improve his typing speed, he decided to type all substrings of the string 𝑠. Yes, all 𝑛(𝑛+1)2 of them!

A substring of 𝑠 is a non-empty string 𝑥=𝑠[𝑎…𝑏]=𝑠𝑎𝑠𝑎+1…𝑠𝑏 (1≤𝑎≤𝑏≤𝑛). For example, "auto" and "ton" are substrings of "automaton".

Shortly after the start of the exercise, Norge realized that his keyboard was broken, namely, he could use only 𝑘 Latin letters 𝑐1,𝑐2,…,𝑐𝑘 out of 26.

After that, Norge became interested in how many substrings of the string 𝑠 he could still type using his broken keyboard. Help him to find this number.

Input
The first line contains two space-separated integers 𝑛 and 𝑘 (1≤𝑛≤2⋅105, 1≤𝑘≤26) — the length of the string 𝑠 and the number of Latin letters still available on the keyboard.

The second line contains the string 𝑠 consisting of exactly 𝑛 lowercase Latin letters.

The third line contains 𝑘 space-separated distinct lowercase Latin letters 𝑐1,𝑐2,…,𝑐𝑘 — the letters still available on the keyboard.

Output
Print a single number — the number of substrings of 𝑠 that can be typed using only available letters 𝑐1,𝑐2,…,𝑐𝑘.
eg. 7 2
abacaba
a b
output: 12
IDEA: represent the string in binary such that if the letter is present then it is 1 otherwise 0
in the above eg. string will become 1110111. Now find the no of substring containing only 1's
*/

ll solve() {
    int n, k; 
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> f;
    for (int i = 0; i < k; ++i) {
        char c; cin >> c;
        f[c] = 1;
    }

    for (char &c: s) {
        if (f.count(c)) c = '1';
        else c = '0';
    }

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') cnt++, ans += cnt;
        else cnt = 0;
    }

    return ans;
}