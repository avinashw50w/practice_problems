/* Chef's love for symmetry is well-known. This love is especially expressed for palindromic strings. Today, he has a triplet of strings, <A, B, C>, where each string is consisting of lowercase characters. He is interested in counting the number of ordered triplet of strings <S1, S2, S3> such that S1, S2, and S3 are non-empty substrings of A, B, and C, respectively, and S1 + S2 + S3 is a palindromic string, with '+' denoting the string concatenation operator.
Note that 2 triplets are considered to be different if any substring chosen from a string in 1 triplet is different from the substring chosen from the same string in other triplet. You can check the definition of a substring here.
Note:
A string S is palindromic if it reads the same both forward as well as backward. To know more about palindromes, click here.
Input

The first line of input contains a single integer T denoting the number of test cases. First line of each test case contains the string A, second line contains the string B, and the third contains the string C.
Output

For each test case, output the required answer.
Constraints

1 ≤ T ≤ 20

1 ≤ |A|, |B|, |C| ≤ 1000

A, B & C consist of lowercase characters only.
Example

Input
4
a
b
c
ab
ba
ab
ab
ab
ab
aa
aa
aa
Output
0
6
8
27
Explanation

Test 1: No such palindromic string is possible.
Test 2: "aaa", "bbb", "aba", "bab", "abba", "baab" are all possible palindromic strings.
Test 3: "aaa", "bbb", "aba", "bab", "abba", "baab", "babab", "ababa" are all possible palindromic strings. 

DIFFICULTY:
Medium-Hard

PREREQUISITES:
String Matching, Z-Algorithm, DP, Palindromes

PROBLEM:
Given three strings S1S1, S2S2 and S3S3, find the number of palindromic strings such that they are formed by concatenation of a substring of S1S1, a substring of S2S2 and a substring of S3S3.

EXPLANATION:
This problem is implementation heavy and requires certain reductions. Let's try to simplify what the question asks for. We have to give the number of strings that we can form from substrings of S1S1, S2S2 and S3S3 such that they are palindromic. To explain better, let xx be a substring of S1S1, yy be a substring of S2S2 and zz be a substring of S3S3. Then x+y+zx+y+z should be palindromic ('+' denotes concatenation operator).

To make the analysis of the problem a bit simpler, let's divide the problem into following three cases:

Case 1: ∣x∣=∣z∣∣x∣=∣z∣, where ∣x∣∣x∣ denotes length of xx.
Case 2: ∣x∣>∣z∣∣x∣>∣z∣.
Case 3: ∣x∣<∣z∣∣x∣<∣z∣.
Case 1
What the first case tells us is that we take a substring from xx from S1S1, and equally sized substring zz from S3S3 and concatenate them with some substring yy from S2S2 in the order x+y+zx+y+z. For x+y+zx+y+z to be a palindrome, there there are certain conditions that need to be met. These are:

xx = reverse(z)reverse(z).
yy is a palindrome in itself.
How can we get the number of possible combinations of xx, yy and zz that fall under this case? First, let us determine how many substrings yy of S2S2 are palindromic. This can be done in O(N2)O(N2) using the standard DP approach used for finding the longest palindromic substring of a string. Once this is done, we need to calculate then number of substrings xx of S1S1 such that reverse(x)reverse(x) is a substring of S3S3. To do this, we take the following steps:

We take a string S′3S3′ = reverse(S3)reverse(S3).
Next, we consider all the suffixes of S1S1.
For a particular suffix sufsuf, we form a new string SzSz = suf+$+S′3suf+$+S3′ ('+' denotes concatenation and $$ is a random character which doesn't appear in text).
We run the Z-Algorithm on SzSz. The sum of values of the ZZ array obtained from the running of this algorithm gives us the number of substrings xx of S1S1 such that reverse(x)reverse(x) = zz.
Repeat for all suffixes of S1S1.
The running time of this part of the algorithm is also O(N2)O(N2) since we have to consider NN suffixes and for each one, the Z-Algorithm takes O(N)O(N) time. Once we have the count of required substrings xx of S1S1, we can multiply this with the number of palindromic substrings yy of S2S2 to get the number of strings x+y+zx+y+z that fall under this case.

**Case 2 and 3**
The key here is to reduce this case to Case 1. Let us assume without loss of generality that ∣x∣<∣z∣∣x∣<∣z∣. The other case is symmetrical.

For x+y+zx+y+z to be a palindrome, the following conditions must hold:

xx = a prefix of reverse(z)reverse(z).
(yy + remaining part of zz) forms a palindrome.
To make this clear, let's take a case. Let xx = abab, yy = cdacda and zz = dcbadcba. We see that xx is a prefix of reverse(z)reverse(z). Also, (yy + remaining part of zz), i.e., (yy + dcdc) = cdadccdadc forms a palindrome. Thus, x+y+zx+y+z = abcdadcbaabcdadcba is palindromic.

How do we count all such x+y+zx+y+z that fall under this case? For this we first count the number of ways such that (yy + a substring of pp of S3S3) form a palindrome (note we have taken variable pp here in order to avoid confusion with zz that we want in the final count). How do we go about it?

For pp, we find the number of substrings yy of S2S2 such that yy+pp is a palindrome. To do this, we take S′3S3′ = reverse(S3)reverse(S3). For every suffix sufsuf of S2S2, we run the Z-Algorithm on suf+$+S′3suf+$+S3′. Let us say that the Z value for some index ii after the $$ character is kk. This means that pp = S3[i−k+1..i]S3[i−k+1..i]. The number of required substrings yy for this pp is given by the number of palidromic substrings of sufsuf such that they begin at index k+1k+1 of the sufsuf. How to do this?

This can be found from the same DP table as we built in Case 1. Once we have the number of yy for a particular pp which is equal to S3[i−k+1..i]S3[i−k+1..i], we store this value in an array temp_count[i]temp_count[i]. Basically, temp_count[i]temp_count[i] stores the number of palindromic strings yy + pp where pp is a substring of S3S3 that end at ithith position in S3S3 and yy is some substring of S2S2. All of this is done in O(N2)O(N2).

The remaning part is to calculate for each index ii in S3S3, the number of substrings xx of S1S1 such that xx is also a substring of S3S3 which begins at ii. The count when multiplied with temp_count[i]temp_count[i] gives the number of palindromic strings x+y+zx+y+z which fall under this case. The count can be easily calculated using Z-Algorithm in the same way as in Case 1. The complexity of this part is again O(N2)O(N2). Case 3 is symmetrical to Case 2.

All in all, we have O(N2)O(N2) algorithm for all cases. The overall complexity of the program is hence O(N2)O(N2).

COMPLEXITY:
O(N2)O(N2) per test case.  */

typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
const double EPS = 1e-8;
const int mod = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;
 
//#define DEBUG
ll power(ll x,ll y){
  ll t=1;
  while(y>0){
    if(y%2) y-=1,t=t*x%mod;
    else y/=2,x=x*x%mod;
  }
  return t;
}
#ifdef DEBUG
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define dprintf(fmt,...)
#endif
 
char s[3][2000];
int n[3];
int ispali[1005][1005][3];
int cali(int i,int j,int k){
  if(i>j) return 1;
  if(ispali[i][j][k]!=-1) return ispali[i][j][k];
  if(i==j) ispali[i][j][k]=1;
  else{
    if(s[k][i]!=s[k][j]) ispali[i][j][k]=0; else ispali[i][j][k]=cali(i+1,j-1,k);
  }
 
  return ispali[i][j][k];
}
ll fwd[2000][3],bck[2000][3];
ll fdp[1005][1005],bdp[1005][1005],dn[1005][1005];
ll fs[1005],bs[1005];
int main(){
  int t; scanf("%d",&t);
  while(t--){
    REP(i,3) scanf("%s",s[i]);
    REP(i,3) n[i]=strlen(s[i]);
    FILL(ispali,-1);
    REP(k,3) REP(i,n[k]) REPP(j,i,n[k]) cali(i,j,k);
    ll sum=0;
    REPP(k,1,2) REP(i,n[k]) REPP(j,i,n[k]) sum+=cali(i,j,k);
    FILL(fwd,0); FILL(bck,0);
    REP(k,3) {
      fwd[0][k]=ispali[0][0][k];
      REPP(i,1,n[k]) {
      //  fwd[i][k]=fwd[i-1][k];
        REP(j,i+1) fwd[i][k]+=ispali[j][i][k];
      }
      for(int i=n[k]-1;i>=0;i--){
        //bck[i][k]=bck[i+1][k];
        REPP(j,i,n[k]) bck[i][k]+=ispali[i][j][k];
      }
    }
    FILL(fs,0); FILL(bs,0);
    FILL(fdp,0); FILL(bdp,0); FILL(dn,0);
    for(int i=n[0]-1;i>=0;i--) REP(j,n[1]){
      if(j==0){
        if(s[0][i]!=s[1][j]) fdp[i][j]=0; else fdp[i][j]=1+bck[i+1][0];
      }else if(s[0][i]==s[1][j]){
        fdp[i][j]=fdp[i+1][j-1]+1+bck[i+1][0]+fwd[j-1][1];
    //    printf("%d %d %lld %lld\n",i,j,bck[i+1][0],fwd[j-1][1]);
      }
  //    printf("%d %d %lld\n",i,j,fdp[i][j]);
    }
    for(int i=n[0]-1;i>=0;i--){
  //    fs[i]=fs[i+1];
      REP(j,n[1]) fs[i]+=fdp[i][j];
    //  printf("zz %lld\n",fs[i]);
    }
    for(int i=n[1]-1;i>=0;i--) REP(j,n[2]){
      if(j==0){
        if(s[1][i]!=s[2][j]) bdp[i][j]=0; else bdp[i][j]=1+bck[i+1][1];
      }else if(s[1][i]==s[2][j]){
        bdp[i][j]=bdp[i+1][j-1]+1+bck[i+1][1]+fwd[j-1][2];
      }
    }
    REP(i,n[2]) {
    //  if(i>0) bs[i]=bs[i-1];
      REP(j,n[1]) bs[i]+=bdp[j][i];
  //    printf("za %lld\n",bs[i]);
    }
//    printf("%lld\n",sum);
    ll ans=0;
    for(int i=n[0]-1;i>=0;i--) REP(j,n[2]){
      if(j==0){
        if(s[0][i]==s[2][j]) dn[i][j]=sum+fs[i+1];
      }else if(s[0][i]==s[2][j]){
        dn[i][j]=dn[i+1][j-1]+fs[i+1]+bs[j-1]+sum;
      }
      ans+=dn[i][j];
    }
    printf("%lld\n",ans);
  }
  return 0;
}
