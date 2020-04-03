/* You are given an array A of N numbers and M queries
of the form L R M and you need to output aL %M +
aL+1 %M + .... + aR %M for each of these queries.
Input

1 st line contains no. of test cases T.

For each test case 

1st line contains an integer N 

Next line contains N integers representing the array A. 

3rd line contains M the no. of queries 

Next M lines contain queries of the form
L R MOD( find answer from L to R with modulo MOD)
Output

For each query of each testcase print the answer in a new line.
Constraints

N <= 10000
For all queries, MOD <= 100000
M <= 10000
1 <= L <= R <= N
T <= 20
A[i] <= 104
 
Example

Input:
1 
4 
100 150 200 300 
1 
1 4 150 

Output:
150
 
Explanation

Example case 1.
Answer for the query is 100 + 0 + 50+ 0 = 150
*/

#include <bits/stdc++.h>
 
using namespace std;
 
#define X first
#define Y second
#define INPUT freopen("MODQ.inp","r",stdin)
#define OUTPUT freopen("MODQ.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1
 
typedef long long ll;
typedef pair<int,int> ii;
 
const int inf=1e9;
const int N=1e4+10,M=1e2+5;
 
int n,m,b[2][N],f[M][N],ans[N],a[N],v[N][3];
vector <int> q[N];
void add(int *b,int x,int v){
    while (x<N){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int *b,int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    REP(MOD,1,M)
        FOR(i,1,n) f[MOD][i]=f[MOD][i-1]+a[i]%MOD;
    memset(ans,0,sizeof(ans));
    int x,y,z;
    FOR(i,0,n) q[i].clear();
    scanf("%d",&m);
    FOR(i,1,m){
        scanf("%d%d%d",&x,&y,&z);
        if (z<M) ans[i]=f[z][y]-f[z][x-1];
        else {
            v[i][0]=x-1;v[i][1]=y;v[i][2]=z;
            q[y].push_back(i);
            q[x-1].push_back(i);
        }
    }
}
void solve(){
    memset(b,0,sizeof(b));
    FOR(i,1,n){
        add(b[0],a[i],1);
        add(b[1],a[i],a[i]);
        for(auto idx:q[i]){
            int sign=(i==v[idx][0]?-1:1),sum=0;
            for(int j=0;j<N;j+=v[idx][2]){
                int en=min(N-1,j+v[idx][2]-1);
                int c=get(b[0],en)-get(b[0],j),v=get(b[1],en)-get(b[1],j);
                sum+=v-c*j;
            }
            ans[idx]+=sign*sum;
        }
    }
    FOR(i,1,m) printf("%d\n",ans[i]);
}
int main(){
    int test;
    scanf("%d",&test);
    while (test--){
        prepare();
        solve();
    }
} 
