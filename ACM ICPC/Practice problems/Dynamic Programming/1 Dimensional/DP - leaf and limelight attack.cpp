/*The Leaf village is build in the shape of Spiral of integers. Spiral of integers, of an integer N, 
is an interesting NxN spiral matrix which starts with 1 at the center. For example, for N=4, the spiral of integers is

16  15  14  13

5   4   3   12

6   1   2   11

7   8   9   10

Calculate the sum of the four corners of the square ie for N = 4, sum = 16 + 13 + 10 + 7 */

/*We will divide the queries into 2 part. Even and Odd.

Lets consider Odd queries.
Spiral of integers of 1 will contain only one integer i.e. DP[1]=1

When i is an Odd Number, we have to add only 4 corner elements in 
DP[i]=DP[i−2]+(i−2)^2+(i−1)+(i−2)^2+2*(i−1)+(i−2)2+3*(i−1)+(i−2)^2 
DP[i]=DP[i−2]+4*(i−2)^2+10*(i−1) 
DP[i]=DP[i−2]+4*i^2−6*(i−1)
Similarly we can check that the above formula is true when 
i is an Even Number.*/

#include <iostream>
using namespace std;
const int mod = 1e9+9;
const int maxn = 1e7+5;
typedef long long ll;

ll dp[maxn];

void prec() {
	dp[0] = 0;
	dp[1] = 1;
	
	for(ll i=2; i<maxn; ++i){
		ll n = (i*i) % mod;
		dp[i] = dp[i-2] + 4*n - 6*(i-1);
		dp[i] %= mod;
		
		if(dp[i] < 0) dp[i] += mod;
	}
}

int main()
{
    int t; cin>>t;
    int n; 
    
	prec();
    while(t--) {
    	cin>>n;
    	cout << dp[n] << endl;
    }
}
