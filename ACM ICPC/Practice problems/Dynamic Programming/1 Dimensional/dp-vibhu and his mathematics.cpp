/*In code world all genders are considered equal ( It means their is nothing like male or female). Now their are N distinct persons living in this hypothetical 
world. Each person can pair up with any other person or can even remain single. 
One day Vbhu planned to visit code world. Being a maths guy , he always try to be mathematical. So he started counting the ways in which N persons living in 
code world can make pairs or remain single. A single person can make pair with at most one other person.
Seeing that N can be large , Vibhu ask you for help. Now being a great programmer you need to help Vbhu count the number of ways in which N persons living 
in code world can make pairs or remain single.

Note : Its not necessary that everyone is required to make pair with someone. Person can remain single also.

Input Format : 
First line contain number of test cases T. Then next T lines contain a single integer N , denoting the number of persons living in code world.

Output Format : 
You need to print the number of ways in which N different persons can make their pairs or stay single. As answer can be large so print it modulo 109+7.

Constraints :
1 <= T <=105 
1 <= N <=106*/

const int mod = 1000000007;
const int MAXN = 1000001;

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