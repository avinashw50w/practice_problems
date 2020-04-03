/*Given a string , find the number of "unordered anagrammatic pairs" of substrings.

Input Format 
First line contains , the number of testcases. Each testcase consists of string  in one line.

Constraints 
 
 
String  contains only the lowercase letters of the English alphabet.

Output Format 
For each testcase, print the required answer in one line.

Sample Input#00

2
abba
abcd
Sample Output#00

4
0
Sample Input#01

5
ifailuhkqq
hucpoltgty
ovarjsnrbf
pvmupwjjjf
iwwhrlkpek
Sample Output#01

3
2
2
6
3
Explanation

Sample00 
Let's say  denotes the substring .

testcase 1: 
For S=abba, anagrammatic pairs are: , ,  and .

testcase 2: 
No anagrammatic pairs.  */

#include <map>
#define ll long long unsigned int
using namespace std;

ll hash_key(int *f){
    ll key = 0, x = 1;
    for(int i=0;i<26;++i){
        key += x*f[i];
        x *= (ll)1000003;
    }
    return key;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        map<ll,int> m;
        for(int i=0;i<n;++i){
            int f[26] = {};
            for(int j=i;j<n;++j){
                f[s[j]-'a']++;
                m[hash_key(f)]++;
            }
        }
        ll ans = 0;
        for(auto it: m)
            ans += (it.second*(it.second-1))/2;
      
        cout << ans << endl;
    }
    
    return 0;
}
