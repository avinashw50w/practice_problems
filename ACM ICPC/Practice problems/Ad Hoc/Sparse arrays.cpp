/*There are N strings. Each string's length is no more than 20 characters. There are also Q queries. 
For each query, you are given a string, and you need 
to find out how many times this string occurred previously.

Input Format

The first line contains N, the number of strings.
The next N lines each contain a string.
The N+2nd line contains Q, the number of queries.
The following Q lines each contain a query string.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    map<string, int> m;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        m[s]++;
    }
    
    cin>>q;
    while(q--) {
        cin>>s;
        cout<<m[s]<<endl;
    }
}