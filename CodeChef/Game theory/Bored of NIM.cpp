/* Rahul and Rashi are bored of playing the game of Nim all day. More so, Rahul has been losing all the games. Actually, the array of stone piles for a game is always selected by Rashi from a huge N-length array A. This selected array is always a subarray of A.
Rahul, now frustrated by his losing streak, insists that he would play the next game only if she chooses a game array of length m.
Can you find the number of such subarrays that Rashi can choose so that Rahul still loses? Moreover, since the value of m is decided by Rahul, can you do this for all possible values of m?
Please note that Rahul is always the first player.
Input:

The first line contains an integer T, the number of test cases to follow.
In each of the test cases, the first line contains a single integer N, and the next line contains N integers, representing the array A.
Output:

Output the results of each test case on a new line. For each test case, output the results for all values of m, that is, m = 1, m = 2 ... m = N, separated by a single space.
Constraints:

1 = T = 3
1 = N = 105
0 = A[i] = 109
1 = m = N
Example:

Sample Input:
2
6
1 2 3 2 1 3
4
1 1 1 1

Sample Output:
0 0 3 0 0 1
0 3 0 1

Explanation
For the first test case and m = 3, required sub-arrays are [1,2,3], [3,2,1] and [2,1,3].

Solution:
DIFFICULTY:
Medium

PREREQUISITES:
Fast Fourier Transform.

PROBLEM:
Given an array of N integers. You have to find count of all subarrays of size m, such that if a Nim Game is played on the subarray, second player will win. Do it for all possible values of m, 1=m=N.

EXPLANATION:
It can be claimed using Nim Game theory that second player will win the game if XOR of the selected subarray is 0. We can find XOR of any subarray in O(1) time by creating a prefix XOR array.

preXOR[0]=0&preXOR[i]=A[0]?A[1]???A[i-1]
A[i]?A[i+1]??A[j]=preXOR[i-1]?preXOR[j]
.

Now, let me present an O(N2) solution for the problem.

answer[n] = 0;
for i in range(0,n):
    for j in range(i+1,n):
        if preXOR[i] == preXOR[j]:      //subarray having size (j-i) has XOR 0.
            answer[j-i]++;
Consider a number k. If it appears l times in the preXOR array, then there will be lC2 subarrays in array A whose XOR is zero. We can create an array 
corresponding to indices of k in preXOR array, and call it S. It means preXOR[S[i]]=k for all i<l.

      for i = 0 to l-1:
          for j= i+1 to l-1:
             ans[j-i]++;       // there is a subarray of size (j-i) having XOR 0.
It can be explained further,Consider that preXOR array is [1,2,3,1,1,4,1], then the array S for k=1 will be [0,3,4,6](0 based indexing).

The above solution can take up to O(N2) time in the worst case, as size of S can be O(N). To improve it, we can do the following modifications:

1) If size of the array S is lesser than N--v, then we can use brute force as given above.

2) If size of the array S is greater than N--v, then the above solution will take more time. So, we can use the FFT to optimize the solution to time Nlog(N).

Number of sub-arrays of size K having XOR 0, will be coefficient of xK in following polynomial:

(xS[0]+xS[1]+?+xS[L-1])(x-S[0]+x-S[1]+?+x-S[L-1])
The powers of x in the above polynomial are negative as well, therefore we do a small modification in above polynomial to make all the powers positive. 
It will be equivalent to the coefficient of xN+K in the following polynomial:

(xS[0]+xS[1]+?+xS[L-1])(xN-S[0]+xN-S[1]+?+xN-S[L-1])
Which can be done in O(Nlog(N)) time using Fast Fourier transform. The FFT will give answer corresponding to all possible value of m altogether.

We can repeat the above procedure for each distinct element k of preXOR array. The total count of subarrays corresponding to each value of m will be 
the count of subarrays of size m for each distinct value of k.

Worst case complexity of the above procedure will be O(NN--vlog(N)).*/

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
 
inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }
 
 
 
namespace FFT {
typedef vector<int> vi;
struct base {
   typedef double T; T re, im;
   base() :re(0), im(0) {}
   base(T re) :re(re), im(0) {}
   base(T re, T im) :re(re), im(im) {}
   base operator + (const base& o) const { return base(re + o.re, im + o.im); }
   base operator - (const base& o) const { return base(re - o.re, im - o.im); }
   base operator * (const base& o) const { return base(re * o.re - im * o.im, re * o.im + im * o.re); }
   base operator * (ld k) const { return base(re * k, im * k) ;}
   base conj() const { return base(re, -im); }
};
const int N = 21;
const int MAXN = (1<<N);
base w[MAXN];
base f1[MAXN];
int rev[MAXN];
void build_rev(int k) {
   static int rk = -1;
   if( k == rk )return ; rk = k;
   for (int i = 1; i <= (1<<k); ++i) {
       int j = rev[i-1], t = k-1;
       while( t >= 0 && ((j>>t)&1) ) { j ^= 1 << t; --t; }
       if( t >= 0 ) { j ^= 1 << t; --t; }
       rev[i] = j;
   }
}
void fft(base *a, int k) {
   build_rev(k); int n = 1 << k;
   for (int i = 0; i < n; ++i) if( rev[i] > i ) swap(a[i], a[rev[i]]);
   for(int l = 2, ll = 1; l <= n; l += l, ll += ll) {
       if( w[ll].re == 0 && w[ll].im == 0 ) {
           ld angle = M_PI / ll;
           base ww( cosl(angle), sinl(angle) );
           if( ll > 1 ) for(int j = 0; j < ll; ++j) {
               if( j & 1 ) w[ll + j] = w[(ll+j)/2] * ww;
               else w[ll + j] = w[(ll+j)/2];
           } else w[ll] = base(1, 0);
       }
       for(int i = 0; i < n; i += l) for (int j = 0; j < ll; ++j) {
           base v = a[i + j], u = a[i + j + ll] * w[ll + j];
           a[i + j] = v + u; a[i + j + ll] = v - u;
       }
   }
}
vi mul(const vi& a, const vi& b) {
   int k = 1;
   while( (1<<k) < ((int)a.size() + (int)b.size()) ) ++k;
   int n = (1<<k);
   for (int i = 0; i < n; ++i) f1[i] = base(0,0);
   for (int i = 0; i < (int)a.size(); ++i) f1[i] = f1[i] + base(a[i], 0);
   for (int i = 0; i < (int)b.size(); ++i) f1[i] = f1[i] + base(0, b[i]);
   fft(f1, k);
	for (int i = 0; i < 1 + n/2; ++i) {
       base p = f1[i] + f1[(n-i)%n].conj();
       base _q = f1[(n-i)%n] - f1[i].conj();
       base q(_q.im, _q.re);
       f1[i] = (p * q) * 0.25;
       if( i > 0 ) f1[(n - i)] = f1[i].conj();
   }
   for (int i = 0; i < n; ++i) f1[i] = f1[i].conj();
   fft(f1, k);
   vi r((int)a.size() + (int)b.size());
   for (int i = 0; i < (int)r.size(); ++i) {
       r[i] = (ll) (f1[i].re / n + 0.5);
   }
   return r;
}
}
 
 
const int MAX_N = 1e5 + 5;
 
 
int n, limit;
ll ans[MAX_N];
pii a[MAX_N];
 
 
void solve(int l, int r) {
	int len = r-l+1;
	if (len <= limit) {
		for (int i = l; i <= r; ++i)
			for (int j = i+1; j <= r; ++j)
				++ans[a[j].second - a[i].second];
		return;
	}
	int mx = a[r].second + 1;
	int my = n - a[l].second + 1;
	vector<int> x(mx, 0), y(my, 0);
	for (int i = l; i <= r; ++i) {
		x[a[i].second] = 1;
		y[n-a[i].second] = 1;
	}
	vector<int> t = FFT::mul(x, y);
	int m = (int)t.size();
	for (int i = n+1; i < m; ++i)
		ans[i-n] += t[i];
}
 
 
int main() {
#ifdef DEBUG
	freopen("ANKNIM2.in", "r", stdin);
	freopen("ANKNIM2.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		int s = 0;
		a[0] = pii(0, 0);
		for (int i = 0; i < n; ++i) {
			int x = read();
			s ^= x;
			a[i+1] = pii(s, i+1);
		}
		sort(a, a+n+1);
		// limit = sqrt(n);
		limit = 2000-1;
 
		filla(ans, 0);
		for (int l = 0, r = 0; l <= n; l = r) {
			while (r <= n && a[r].first == a[l].first)
				++r;
			solve(l, r-1);
		}
		for (int i = 1; i <= n; ++i)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
} 
Comments 

