   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//

#include <bits/stdc++.h>
using namespace std;
#define oo (int)1e9
#define eps 1e-9
#define mod 1000000007
#define ri(o) scanf("%d",&(o))
#define pi(o) printf("%d\n",(o))
#define rl(o) scanf("%lld",&(o))
#define pl(o) printf("%lld\n",(o))
#define rf(o) scanf("%f",&(o))
#define rc(o) scanf("%c",&(o))
#define rs(o) scanf("%s",(o))
#define rii(a,b) scanf("%d%d",&(a),&(b))
#define riii(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define dri(o) int o; scanf("%d",&(o))
#define drii(a,b) int a,b; scanf("%d%d",&(a),&(b))
#define driii(a,b,c) int a,b,c; scanf("%d%d%d",&(a),&(b),&(c))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define CASET dri(__T);int case_n=1;while(__T--)
#define runtime printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
#define debug(args...) {dbg,args; cerr<<endl;}
struct debugger{
    template<typename T>debugger& operator ,(const T& v) { cerr<<v<<" ";return *this; }
}dbg;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef map<int,int> mii;

inline ll inp(){ll n = 0;register int c=getchar_unlocked();while(c==' ' or c=='\n')c=getchar_unlocked();
while(c>='0' and c<='9'){n = (n<<3) + (n<<1) + c-48;c = getchar_unlocked();}return n;}
/* The Little Elephant likes permutations. This time he has a permutation A[1], A[2], ..., A[N] of numbers 1, 2, ..., N.
He calls a permutation A good, if the number of its inversions is equal to the number of its local inversions. The number of inversions is equal to the number of pairs of integers (i; j) such that 1 ≤ i < j ≤ N and A[i] > A[j], and the number of local inversions is the number of integers i such that 1 ≤ i < N and A[i] > A[i+1].
The Little Elephant has several such permutations. Help him to find for each permutation whether it is good or not. Print YES for a corresponding test case if it is good and NO otherwise.
Input

The first line of the input contains a single integer T, the number of test cases. T test cases follow. The first line of each test case contains a single integer N, the size of a permutation. The next line contains N space separated integers A[1], A[2], ..., A[N].
Output

For each test case output a single line containing the answer for the corresponding test case. It should be YES if the corresponding permutation is good and NO otherwise.*/
int main() {
	int a[102],n;
	CASET{
		int inv=0, linv=0;
		rii(n,a[0]);
		if(n==1) {puts("YES"); continue;}
		rep(i,1,n){
			ri(a[i]);
			if(a[i-1]>a[i]) linv++;
		}
		rep(i,0,n-1){
			rep(j,i+1,n){
				if(a[i]>a[j]) inv++;
			}
		}
		if(inv==linv) puts("YES");
		else puts("NO");

	}
	return 0;
}
