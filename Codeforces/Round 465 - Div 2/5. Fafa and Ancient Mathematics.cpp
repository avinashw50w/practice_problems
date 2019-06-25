/*Ancient Egyptians are known to have understood difficult concepts in mathematics. The ancient Egyptian mathematician 
Ahmes liked to write a kind of arithmetic expressions on papyrus paper which he called as Ahmes arithmetic expression.

An Ahmes arithmetic expression can be defined as:

"d" is an Ahmes arithmetic expression, where d is a one-digit positive integer;
"(E1 op E2)" is an Ahmes arithmetic expression, where E1 and E2 are valid Ahmes arithmetic expressions 
(without spaces) and op is either plus ( + ) or minus ( - ).
For example 5, (1-1) and ((1+(2-3))-5) are valid Ahmes arithmetic expressions.
On his trip to Egypt, Fafa found a piece of papyrus paper having one of these Ahmes 
arithmetic expressions written on it. Being very ancient, the papyrus piece was very worn out. 
As a result, all the operators were erased, keeping only the numbers and the brackets. 
Since Fafa loves mathematics, he decided to challenge himself with the following task:

Given the number of plus and minus operators in the original expression, 
find out the maximum possible value for the expression on the papyrus paper after putting 
the plus and minus operators in the place of the original erased operators.

Input
The first line contains a string E (1 ≤ |E| ≤ 104) — a valid Ahmes arithmetic expression. 
All operators are erased and replaced with '?'.

The second line contains two space-separated integers P and M (0 ≤ min(P, M) ≤ 100) — 
the number of plus and minus operators, respectively.

It is guaranteed that P + M =  the number of erased operators.

Output
Print one line containing the answer to the problem.

Examples
inputCopy
(1?1)
1 0
output
2
inputCopy
(2?(1?2))
1 1
output
1*/

#include <bits/stdc++.h>
// #include "stdafx.h"
// #pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];
string s;
int p, m;

struct tree{
	int max[104], min[104], cnt;
}node[30003];

void MAX(int &x, int y){
	if(x < y) x = y;
}

void MIN(int &x, int y){
	if(x > y) x = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,n,k,j,flag(0);
	stack<int> S;
	cin >> s;
	cin >> p >> m;
	
	if(m <= 100) flag = 1;
	
	n = s.size();
	
	//build the tree
	int t = 0;
	for(char c: s){
		if(c >= '1' and c <= '9'){
			t++;
			node[t].max[0] = node[t].min[0] = c-'0';
			node[t].cnt = 0;
			S.push(t);
		}
		else if(c == ')'){
			int r = S.top(); S.pop();
			int l = S.top(); S.pop();
			t++;
			node[t].cnt = node[l].cnt + node[r].cnt + 1;
			S.push(t);
			
			int i_lim = min(100, node[t].cnt);
			
			// taking i no of ? marks as + sign
			fo(i, i_lim+1){
				node[t].max[i] = -mod;
				node[t].min[i] = mod;
				// taking j no of ? marks as + sign out of these i ? marks
				int j_lim = min(node[l].cnt, i);
				fo(j, j_lim+1){
					if(flag == 0){
						if(i-j-1 <= node[r].cnt and i!=j)
							MAX(node[t].max[i], node[l].max[j] + node[r].max[i-j-1]),
							MIN(node[t].min[i], node[l].min[j] + node[r].min[i-j-1]);
						if(i-j <= node[r].cnt)
							MAX(node[t].max[i], node[l].max[j] - node[r].min[i-j]),
							MIN(node[t].min[i], node[l].min[j] - node[r].max[i-j]);
					}
					else{
						if(i-j <= node[r].cnt)
							MAX(node[t].max[i], node[l].max[j] + node[r].max[i-j]),
							MIN(node[t].min[i], node[l].min[j] + node[r].min[i-j]);
						
						if(i-j-1 <= node[r].cnt and i!=j)
							MAX(node[t].max[i], node[l].max[j] - node[r].min[i-j-1]),
							MIN(node[t].min[i], node[l].min[j] - node[r].max[i-j-1]);
					}
				}
			}			
		}
	}

	int idx = p;
	if(flag) idx = m;
	cout << node[t].max[idx] << endl;

	return 0;
} 