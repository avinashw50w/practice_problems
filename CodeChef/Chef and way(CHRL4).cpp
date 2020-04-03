/*
After visiting a childhood friend, Chef wants to get back to his home. Friend lives at the first street, and Chef himself lives at the N-th (and the last) 
street. Their city is a bit special: you can move from the X-th street to the Y-th street if and only if 1 <= Y - X <= K, where K is the integer value that is 
given to you. Chef wants to get to home in such a way that the product of all the visited streets' special numbers is minimal (including the first and the N-th street). Please, help him to find such a product.
Input
The first line of input consists of two integer numbers - N and K - the number of streets and the value of K respectively. The second line consist of N numbers
 - A1, A2, ..., AN respectively, where Ai equals to the special number of the i-th street.

Output
Please output the value of the minimal possible product, modulo 1000000007.
Constraints

1 = N = 10^5
1 = Ai = 10^5
1 = K = N
Example

Input:
4 2
1 2 3 4.

Output:
8
*/

#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;        //defining the  data type
typedef pair<double,int> pdi;
ll prod[100010];
double dp[100010];
int a,k;
deque<pdi> win;
void slide(int i)
{
	cin>>a;
	int j=win.front().ss;      // j is assigned the second element of the pair in front position of the deque named win
	dp[i]=dp[j]+log(a);
	prod[i]=(prod[j]*a)%M;
	while(!win.empty() && win.back().ff > dp[i])
		win.pop_back();
	win.push_back(mp(dp[i],i));
	while(win.front().ss <= i-k)
		win.pop_front();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i;
	cin>>n>>k;
	cin>>a;
	prod[0]=a%M;
	dp[0]=log(a);
	win.push_back(mp(dp[0],0));
	for(i=1;i<n;i++)
		slide(i);
	cout<<prod[n-1]<<'\n';
	return 0;
} 
