/*Chandu is a very strict mentor. He always gives a lot of work to his interns. So his interns decided to kill him. There is a party in the office on Saturday Night, and the interns decided to kill him on the same day. In the party, there are N beer bottles. Each bottle has a integer X written on it. Interns decided to mix poison in some of the beer bottles. They made a plan that they will add poison into a bottle only if the integer on the beer bottle has number of divisors strictly less than 4. Chandu came to know about the plan of the interns. So he needs to your help to save his life. Tell Chandu if he can drink the beer or not.

Input:
First line of contains an integer N, denoting the number of bottles.
Each test case contains an integer X, denoting the number on the beer bottle.

Output:
For each beer bottle, print YES if Chandu can drink that beer, otherwise print NO.

Constraints:
1 <= N <= 105
1 <= X <= 107  */

bool prime[MAXN+1];
void seive(){
	ll i,j;
	memset(prime,1,sizeof prime);
	prime[0] = prime[1] = false;
	for(i=2;i*i<=MAXN;++i){
		if(prime[i]){
			for(j=i*i;j<=MAXN;j+=i) prime[j] = false;
		}
 	}
}
int main() {
	seive();
	caset{
		ll n; sl(n);
		ll sq = sqrt(n);
		if(prime[n]) puts("NO");
		else if(n == sq*sq && prime[sq]) puts("NO");
		else puts("YES");
	}
	return 0;
}
