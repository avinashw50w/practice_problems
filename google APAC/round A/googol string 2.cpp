/*
A "0/1 string" is a string in which every character is either 0 or 1. There are two operations that can be performed on a 0/1 string:

switch: Every 0 becomes 1 and every 1 becomes 0. For example, "100" becomes "011".
reverse: The string is reversed. For example, "100" becomes "001".
Consider this infinite sequence of 0/1 strings:

S0 = ""

S1 = "0"

S2 = "001"

S3 = "0010011"

S4 = "001001100011011"

...

SN = SN-1 + "0" + switch(reverse(SN-1)).

You need to figure out the Kth character of Sgoogol, where googol = 10^100.

Input

The first line of the input gives the number of test cases, T. Each of the next T lines contains a number K.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the Kth character of Sgoogol.

Limits

1 = T = 100.
Small dataset

1 = K = 10^5.
Large dataset

1 = K = 1018
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
double A[1000000+5];
lld len[1000000+5];
int rec(lld K){
	int it = 0;
	for(int i=0;i<=60;++i){
		if(len[i]>=K){
			it = i;
			break;
		}
	}
	if(len[it-1]+1==K)
		return 0;
	lld dist = len[it]-K+1;
	return rec(dist)^1;
}
int solve(){
	lld K;
	cin>>K;
	len[0]=0;
	for(int i=1;i<=64;++i){
		len[i] = 2*len[i-1]+1;
	}
	return rec(K);
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d: %d\n",test,solve());
	}
}
///////////////////////////////////////////////////////////////

 private static boolean isone(long l, long k) {
        if (k == l / 2) return false;
        else if (k < l / 2) return isone(l / 2, k);
        else return !isone(l / 2, l - k - 1);
    }
    private static void solve(long K) {
        long l = 0;
        while (l <= K) l = l * 2 + 1;
        System.out.println(isone(l, K) ? "1" : "0");
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 0; t < T; t++) {
            System.out.printf("Case #%d: ", t + 1);
            solve(in.nextLong() - 1);
        }
    }
//////////////////////////////////////////////////////////
/*
Sn has length of 2n – 1 and is composed of Sn-1, 0, and switch(reverse(Sn-1))
If we want to find the Kth character of Sn and we know that K < 2n-1, then we can find the Kth character of Sn-1. If K = 2n-1, 
the Kth character is “0”. How about K > 2n-1.
Let’s try a concrete example. We want to find Kth character on S4 where K > 8. Assume S3 = s1s2s3s4s5s6s7. Then S4 = s1s2s3s4s5s6s7 “0” t7t6t5t4t3t2t1 
where ti is a negation of si. K = 9, the character is t7; K = 10, the character is t6. It turns out that when K > 2n-1, the character is the negation 
of the character (2n – K).th in Sn-1.
Thus we can define the function int getDigit(long n, long K, boolean isNegation) to recursively compute the character (index).th in Sn and 
whether we need to do the negation on the result
Finally, notice that if you call the line 29 instead of 30, you probably will get error. This is very subtle and difficult to find out.*/

public static void main(String[] args) throws IOException {     

    FileInputStream fis = new FileInputStream("input.txt");

    Scanner scanner = new Scanner(fis);

    FileWriter writer = new FileWriter("output.txt");

     

    int T = scanner.nextInt();

    for(int i = 1; i <= T; i++){

        long K = scanner.nextLong();

        long n = (long)Math.floor(Math.log(K) / Math.log(2) + 1);

        int result = getDigit(n, K, false);

        writer.write("Case #" + i + ": " + result + "\n");

    }

    scanner.close();

    writer.close();

}


private static int getDigit(long n, long K, boolean isNegation){

    if(n == 1){

        return (isNegation)? 1: 0;

    }

    else{

        if(K < Math.pow(2, n-1)){

            return getDigit(n-1, K, isNegation);

        }

        else if(K == Math.pow(2, n-1)){

            return (isNegation)? 1: 0;

        }

        else{

//              return getDigit(n-1, (long) (Math.pow(2, n) - index), !reverse);

            return getDigit(n-1, ((long)Math.pow(2, n) - K), !isNegation);

        }

    }

}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
int sol(LL k) {
    if (!(k&(k-1)))
        return 0;
    LL a = 1;
    while (a < k)
        a <<= 1;
    return 1-sol(a-k);
}
