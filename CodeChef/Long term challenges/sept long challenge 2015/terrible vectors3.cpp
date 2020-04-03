#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 
 
using namespace std; 
 
typedef unsigned int uint; 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef unsigned short ushort; 
typedef unsigned char uchar; 
typedef pair<int,int> ipair; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<double> VD; 
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi=acos(-1.0); 
const double eps=1e-11; 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()
 
template<class T> T sqr(const T &x) { return x*x; } 
template<class T> T lowbit(const T &x) { return (x^(x-1))&x; } 
template<class T> int countbit(const T &n) { return (n==0)?0:(1+countbit(n&(n-1))); } 
template<class T> void ckmin(T &a,const T &b) { if (b<a) a=b; } 
template<class T> void ckmax(T &a,const T &b) { if (b>a) a=b; } 
#define P2(x) (((int64)1)<<(x))
 
int s[128][128][128];
 
bool ck(int n)
{
	REP(i,n) FOR(j,i+1,n)
	{
		int d=0;
		REP(k,n) d+=s[n][i][k]*s[n][j][k];
		if (d!=0) return false;
	}
	return true;
}
int isprime(int n)
{
	for (int m=2;m*m<=n;m++) if (n%m==0) return false;
	return true;
}
void construct(int n,int a[],int b[],int c[],int d[])
{
	int m=n/4;
	REP(i,m) REP(j,m)
	{
		int a0=a[((j-i)%m+m)%m],b0=b[(i+j)%m],c0=c[(i+j)%m],d0=d[(i+j)%m];
		s[n][i][j]    = a0; s[n][i][j+m]    = b0; s[n][i][j+m*2]    = c0; s[n][i][j+m*3]    = d0;
		s[n][i+m][j]  =-b0; s[n][i+m][j+m]  = a0; s[n][i+m][j+m*2]  = d0; s[n][i+m][j+m*3]  =-c0;
		s[n][i+m*2][j]=-c0; s[n][i+m*2][j+m]=-d0; s[n][i+m*2][j+m*2]= a0; s[n][i+m*2][j+m*3]= b0;
		s[n][i+m*3][j]=-d0; s[n][i+m*3][j+m]= c0; s[n][i+m*3][j+m*2]=-b0; s[n][i+m*3][j+m*3]= a0;
	}
}
 
void preprocess()
{
	s[1][0][0]=1;	
	s[2][0][0]=1;
	s[2][0][1]=1;
	s[2][1][0]=1;
	s[2][1][1]=-1;
	int e[128];
	for (int n=3;n<=100;n++) if (n%4==0)
	{
		bool done=false;
		for (int m=2;m*m<=n;m++) if (n%m==0 && s[m][0][0]!=0 && s[n/m][0][0]!=0)
		{
			REP(i,n) REP(j,n) s[n][i][j]=s[m][i%m][j%m]*s[n/m][i/m][j/m];
			done=true;
			if (ck(n)) break;
			printf("ERROR1 %d\n",n); exit(0);
		}
		if (done) continue;
		if (isprime(n-1)==1)
		{
			int m=n-1;
			REP(i,n) s[n][i][i]=1;
			REP(i,m) e[i]=-1;
			REP(i,m) e[(i*i)%m]=1;
			FOR(i,1,n) s[n][0][i]=1,s[n][i][0]=-1;
			FOR(i,1,n) FOR(j,1,n) s[n][i][j]=e[((i-j)%m+m)%m];
			if (ck(n)) continue;
			printf("ERROR2 %d\n",n); exit(0);
		}
		if (isprime(n/2-1) && (n/2-1)%4==1)
		{
			int m=n/2-1;
			REP(i,m) e[i]=-1;
			REP(i,m) e[(i*i)%m]=1;
			REP(i,n/2) REP(j,n/2) 
			{
				int c=(i==j?0:((i==0 || j==0)?1:e[((i-j)%m+m)%m]));
				if (c==0)
				{
					s[n][i*2][j*2]=1;
					s[n][i*2][j*2+1]=s[n][i*2+1][j*2]=s[n][i*2+1][j*2+1]=-1;
				}
				else
				{
					s[n][i*2][j*2]=s[n][i*2][j*2+1]=s[n][i*2+1][j*2]=c;
					s[n][i*2+1][j*2+1]=-c;
				}
			}
			if (ck(n)) continue;
			printf("ERROR3 %d\n",n); exit(0);
		}
		if (n==52)
		{
			int a[13]={1, 1,-1,-1,-1,-1,-1, 1, 1, 1, 1, 1,-1};
			int b[13]={1,-1,-1, 1, 1, 1,-1,-1, 1, 1, 1,-1,-1};
			int c[13]={1, 1, 1,-1, 1,-1, 1, 1,-1, 1,-1, 1, 1};
			int d[13]={1,-1, 1, 1, 1,-1, 1, 1,-1, 1, 1, 1,-1};
			construct(n,a,b,c,d);
			if (ck(n)) continue;
			printf("ERROR4 %d\n",n); exit(0);
		}
		if (n==92)
		{
			int a[23]={1,-1,-1,-1,-1,-1,-1,-1, 1, 1,-1, 1,-1, 1,-1,-1, 1, 1, 1, 1, 1, 1, 1};
			int b[23]={1, 1,-1,-1, 1,-1,-1, 1, 1, 1, 1,-1,-1, 1, 1, 1, 1,-1,-1, 1,-1,-1, 1};
			int c[23]={1, 1,-1,-1,-1, 1,-1, 1,-1, 1,-1, 1, 1,-1, 1,-1, 1,-1, 1,-1,-1,-1, 1};
			int d[23]={1,-1,-1,-1,-1, 1,-1,-1, 1,-1,-1, 1, 1,-1,-1, 1,-1,-1, 1,-1,-1,-1,-1};
			construct(n,a,b,c,d);
			if (ck(n)) continue;
			printf("ERROR4 %d\n",n); exit(0);
		}
		if (n==100)
		{
			int a[25]={1,-1,-1, 1, 1,-1, 1,-1, 1,-1,-1,-1,-1,-1,-1,-1,-1, 1,-1, 1,-1, 1, 1,-1,-1};
			int b[25]={1,-1, 1, 1,-1, 1, 1, 1,-1, 1, 1,-1,-1,-1,-1, 1, 1,-1, 1, 1, 1,-1, 1, 1,-1};
			int c[25]={1, 1, 1,-1, 1, 1, 1,-1,-1,-1, 1,-1, 1, 1,-1, 1,-1,-1,-1, 1, 1, 1,-1, 1, 1};
			int d[25]={1,-1, 1, 1, 1, 1,-1,-1,-1,-1, 1, 1,-1,-1, 1, 1,-1,-1,-1,-1, 1, 1, 1, 1,-1};
			construct(n,a,b,c,d);
			if (ck(n)) continue;
			printf("ERROR4 %d\n",n); exit(0);
		}
		printf("ERROR0 %d\n",n); //exit(0);
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	memset(s,0,sizeof(s));
	preprocess();
	int testcase;
	for (cin>>testcase;testcase>0;testcase--)
	{
		int n;
		cin>>n;
		if (s[n][0][0]==0)
			printf("NO\n");
		else
		{
			printf("YES\n");
			REP(i,n) REP(j,n) { if (i+j>0) printf(" "); printf("%d",s[n][i][j]); }
			printf("\n");
		}
	}
	return 0;
}
