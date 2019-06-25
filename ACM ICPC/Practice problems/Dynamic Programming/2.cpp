/*The problem boils down to finding the number of ways such that N distinct persons can form couples out of which some can remain alone.

Let F(X) denote the number of ways for the above problem, meaning we have X number of people. So, Lets tak about Xth person, he might like to remain single or he can pair up with some person from [1,X-1].

So, considering and adding both the cases to the final answer, we get the recurrence:-
F(X) = F(X-1) + (X-1)*F(X-2). Lets look at the pseudo code for the implementation of recursive approach.

F(X) {
    if X is 0
       return 1
    if X is 1
       return 1
    return F(X-1) + (X-1)*F(X-2)
}
*/
#define oo 0x3f3f3f3f
const int mod = 1000000007;
const int MAXN = 1000001;
/*========================================================================================*/
ll dp[MAXN+2];

void prec(){
    dp[0] = dp[1] = 1;
    rep(i,2,MAXN+1){
    	dp[i] = dp[i-1] + (i-1)*dp[i-2];
    	dp[i] %= mod;
    }
}
int main() {
    prec();
    int n;
    caset{
    	si(n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
