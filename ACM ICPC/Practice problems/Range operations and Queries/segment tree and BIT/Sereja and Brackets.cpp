/*Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the 
length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

You can find the definitions for a subsequence and a correct bracket sequence in the notes.

Input
The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". 
The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line 
contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.

Output
Print the answer to each question on a single line. Print the answers in the order they go in the input.

Examples
input
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10
output
0
0
2
10
4
6
6
Note
A subsequence of length |x| of string s = s1s2... s|s| (where |s| is the length of string s) is string x = sk1sk2... sk|x| (1 ≤ k1 < k2 < ... < k|x| ≤ |s|).

A correct bracket sequence is a bracket sequence that can be transformed into a correct aryphmetic expression by inserting characters "1" and 
"+" between the characters of the string. For example, bracket sequences "()()", "(())" are correct (the resulting expressions "(1)+(1)", 
"((1+1)+1)"), and ")(" and "(" are not.

For the third query required sequence will be «()».

For the fourth query required sequence will be «()(())(())».*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define pii pair<int, int>
#define MAXN 1000010

int fen[MAXN];
int ans[MAXN];
void add(int i)
{
    for (i++; i < MAXN; i += i & (-i))
        fen[i]++;
}
int get(int i)
{
    int ans = 0;
    for (i++; i > 0; i -= i & (-i))
        ans += fen[i];
    return ans;
}
vector<pii> q[MAXN];
stack<int> st;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        q[l].push_back(pii(r, i));
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            st.push(i);
        else if (!st.empty())
        {
            add(st.top());
            st.pop();
        }
        for (auto c: q[i])
            ans[c.second] = get(c.first);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] * 2 << endl;
}

//////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
string s;
int q[21][1123456];
int main() {
    cin>>s;
    int l=s.length();
    for (int i=0;i<l;i++) q[0][i+1]=q[0][i]+(s[i]=='('?1:-1);
    for (int j=0;j<20;j++) for (int i=0;i<=l;i++)
        q[j+1][i]=min(q[j][i],q[j][i+(1<<j)]);
    int m,L,R;
    scanf("%d",&m);
    for (int i=0;i<m;i++) {
        scanf("%d %d",&L,&R);L--;
        int j=0;
        while ((1<<(j+1))<=R-L) j++;
        int qq=min(q[j][L],q[j][R-(1<<j)+1]);
        printf("%d\n",R-L-(q[0][L]+q[0][R]-2*qq));
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

/*For each node (for example x), we keep three integers : 1.t[x] = Answer for it's interval. 2. o[x] = The number of $($s after deleting the brackets who belong to the correct bracket sequence in this interval whit length t[x]. 3. c[x] = The number of $)$s after deleting the brackets who belong to the correct bracket sequence in this interval whit length t[x].
Lemma : For merging to nodes 2x and 2x + 1 (children of node 2x + 1) all we need to do is this :
tmp = min(o[2 * x], c[2 * x + 1])
t[x] = t[2 * x] + t[2 * x + 1] + tmp
o[x] = o[2 * x] + o[2 * x + 1] - tmp
c[x] = c[2 * x] + c[2 * x + 1] - tmp
So, as you know, first of all we need a build function which would be this : (as above) (C++ and [l, r) is inclusive-outclusive ) */
void build(int id = 1,int l = 0,int r = n){
    if(r - l < 2){
        if(s[l] == '(')
            o[id] = 1;
        else
            c[id] = 1;
        return ;
    }
    int mid = (l+r)/2;
    build(2 * id,l,mid);
    build(2 * id + 1,mid,r);
    int tmp = min(o[2 * id],c[2 * id + 1]);
    t[id] = t[2 * id] + t[2 * id + 1] + tmp;
    o[id] = o[2 * id] + o[2 * id + 1] - tmp;
    c[id] = c[2 * id] + c[2 * id + 1] - tmp;
}
/*
For queries, return value of the function should be 3 values : t, o, c which is the values I said above for the intersection of the node's 
interval and the query's interval (we consider query's interval is [x, y) ), so in C++ code, return value is a pair<int,pair<int,int> > 
(pair<t, pair<o,c> >) :  */
typedef pair<int,int>pii;
typedef pair<int,pii>   node;
node segment(int x,int y,int id = 1,int l = 0,int r = n){
    if(l >= y || x >= r)   return node(0,pii(0,0));
    if(x <= l && r <= y)
        return node(t[id],pii(o[id],c[id]));
    int mid = (l+r)/2;
    node a = segment(x,y,2 * id,l,mid), b = segment(x,y,2 * id + 1,mid,r);
    int T, temp, O, C;
    temp = min(a.y.x , b.y.y);
    T = a.x + b.x + temp;
    O = a.y.x + b.y.x - temp;
        C = a.y.y + b.y.y - temp;
    return node(T,pii(O,C));    
}