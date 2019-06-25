#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <ctype.h>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <string.h>
#include <time.h>
#include <utility>
#include <vector>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef vector<int> vi;
 
#define MAX 1000000007
#define MOD 1000000007
#define FT first
#define SE second
#define SZ size()
#define BG begin()
#define EN end()
#define SP system("pause")
#define PB(a) push_back(a)
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define PT(a) printf("%d\n",a)
#define GT(a) int a;scanf("%d",&a)
#define MS(a,b) memset(a,b,sizeof(a))
#define FI freopen("I.txt","r",stdin)
#define FO freopen("O.txt","w",stdout)
#define rev(i,n) for(int i=n;i>=0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define take(ar,n) int ar[n]; rep(i,n) cin>>ar[i]
#define foreach(V,it) for(typeof((V).BG)it=(V.BG);it!=V.EN;it++)
#define show(ar,n) rep(i,n+1) printf("%d%c",ar[i],(i == n)?'\n':' ');
 
const int maxn = 100007;
 
int lastpos[maxn],lastpair=-1,posofk=-1;
int n,k,foo,mx,pos;
long long res;
int inp(int &n)
{
    n=0;
    char ch=getchar();
    while(!isdigit(ch)) ch = getchar();
    do
    {
        n=(n<<1)+(n<<3)+ch-'0';
        ch=getchar();
    } while(isdigit(ch));
    return n;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("I.in","r",stdin);
    #endif
    memset(lastpos,255,sizeof(lastpos));
    inp(n),inp(k);
    for(int i=0;i<n;i++)
    {
        inp(foo);
        pos=-1;
        if(foo>k) 
        {
            for(int i=foo;i<=mx;i+=foo) if(lastpos[i]!=-1) 
            {
                pos=max(pos,lastpos[i]);
            }
            pos=max(pos,posofk);
        }
        else pos=lastpair;
        pos=max(pos,lastpair);
        res+=i-pos;
        lastpair=max(pos,lastpair);
        if(foo==k) posofk=i;
        if(foo>k) lastpos[foo-k]=i;
        mx=max(mx,foo-k);
    }
    printf("%lld\n",res);
    return 0;
} 
