/* Given a string of lowercase letters, where weight of letters are like : a = 1, b = 2, c = 3, ....

A uniform string is a string consisting of a single character repeated zero or more times. For example, ccc and a are 
uniform strings, but bcb and cd are not (i.e., they consist of more than one distinct character).
Given a string, s, let U be the set of weights for all possible uniform substrings (contiguous) of string s. 
You have to answer n queries, where each query i consists of a single integer, xi. For each query, print Yes on a new line 
if xi belongs to U; otherwise, print No instead.

Input Format

The first line contains a string denoting s (the original string). 
The second line contains an integer denoting n (the number of queries). 
Each line i of the n subsequent lines contains an integer denoting  (the weight of a uniform subtring of  
that may or may not exist).

Sample Input 0

abccddde
6
1
3
12
5
9
10
Sample Output 0

Yes
Yes
Yes
Yes
No
No */

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    
    stack<pair<char, int>> sk;
    set<int> st;
    
    sk.push(make_pair(s[0], s[0] - 'a' + 1));
    st.insert(s[0] - 'a' + 1);
    
    for(int i = 1; i < s.length(); ++i) {
        if(s[i] == sk.top().first) {
            sk.top().second += s[i] - 'a' + 1;
            st.insert(sk.top().second);
        }
        else {
            sk.push(make_pair(s[i], s[i] - 'a' + 1));
            st.insert(sk.top().second);
        }
    }
    
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        puts(st.count(x) ? "Yes" : "No");
    }
    
    return 0;
}

//////////////////////////////////////////////////

#!/bin/python
import sys
#sys.stdin = open("in","r")

s = raw_input()
t = int(raw_input())
w = 0
dic = {}
for i in range(0, len(s)):
        if i == 0 or s[i] != s[i-1]:
            w = ord(s[i]) - ord('a') + 1
        else:
            w = w + ord(s[i]) - ord('a') + 1
        dic[w] = 1

for i in range(t):
    x = int(raw_input())
    print 'Yes' if x in dic else 'No'

////////////////////////////////////////////////////////////

    #include <bits/stdc++.h>
#include<assert.h>

using namespace std;

int arr[30];
map<int, bool>mp;

void solution() {

    memset(arr, 0, sizeof(arr));
    mp.clear();

    string str;
    int n, x, len, temp, sum;
    char ch;

    cin>>str;
    len = str.size();
    assert(len>0 && len<=100000);

    for(int i=0, j; i<len; )
    {
       ch = str[i];
       j = i;
       temp = 0;
       while(j<len && str[j] == str[i])
       {
         temp++;
         j++;
       }
       arr[ch-'a'] = max(arr[ch-'a'], temp);
       i = j;
    }

    for(int i=0; i<26; i++)
    {
       sum = 0;
       for(int k=0; k<arr[i]; k++)
       {
         sum = sum+i+1;
         mp[sum] = 1;
       }
    }

    cin>>n;

    for(int i=0; i<n; i++)
    {
       cin>>x;

       if(mp[x])
        printf("Yes\n");
       else
        printf("No\n");
    }
}


int main () {


        solution();


    return 0;
}