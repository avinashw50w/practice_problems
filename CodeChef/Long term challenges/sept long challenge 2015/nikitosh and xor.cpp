#include<bits/stdc++.h>
using namespace std;

#if defined(_WIN64)

#define gc getchar
#define pc putchar

#else

#define gc getchar_unlocked
#define pc putchar_unlocked

#endif

#ifdef __LONG
typedef long long int ll;

#else
typedef int ll;

#endif

inline int sscan()
    {
       int n=0;
       int ch=gc();
       while( ch < '0' || ch > '9' )
            ch=gc();
       while(  ch >= '0' && ch <= '9' )
        {
            n = (n<<3)+(n<<1) + ch-'0';
            ch=gc();
        }
     
       return n;
    }

ll gcd(ll a,ll b){ return (b==0)?a:gcd(b,a%b); }
ll lcm(ll a, ll b) { return (a*b)/gcd(a,b); }
ll modpow(ll a, ll n, ll mod){ ll res=1; while(n){ if(n&1)res=(res*a)%mod; a=(a*a)%mod; n>>=1; } return res; }
 
inline int max(int a,int b)
{
  if(a>=b)
      return a;
    else
      return b;
}
 
const int SIZE = 40000005;
 
class trie
{
    int n;
    int nodes[SIZE][2];
  public:
  void init(){
    n=1;
    nodes[0][0]=nodes[0][1]=-1;               // -1 indicates the end
  }
 
  void insert(int x)
   {
    int node=0;
    for (int i=31;i>= 0;i--)
     {
      int next=(x&(1<<i))!=0;
      if (nodes[node][next]==-1)
       {
        nodes[node][next]=n;
        nodes[n][0]=nodes[n][1]=-1;
        n++;
      }
      node=nodes[node][next];
    }
  }
 
  int query(int x)
   {
    int node=0;
    int ans=0;
    for (int i=31;i>=0;i--)
     {
      int next=((x & (1<<i)) != 0);
      bool flag = 1;
      if (nodes[node][next^1]==-1)
       {
        next^=1;
        flag=0;
      }
      if (flag)
        ans+=(1 << i);
 
      node=nodes[node][next ^ 1];
    }
    return ans;
  }
};
 
 
trie tree1,tree2;
 
int main()
{
 
 
    int a[400002],t1[400002],t2[400002],n,curr_best1=0,curr_best2=0,prefix=0,suffix=0,ans=0;
    cin >> n;
    
    tree1.init();
    tree2.init();
    tree1.insert(0);
    tree2.insert(0);
 
    for (int i=0;i<n;i++)
    {
      a[i]=sscan();
    }
  
  for(int i=0;i<n;i++)
  {
      prefix^= a[i];
      suffix^=a[n-i-1];
      curr_best1=max(curr_best1,tree1.query(prefix));
      t1[i]=curr_best1;
      curr_best2=max(curr_best2,tree2.query(suffix));
      t2[n-i-1]=curr_best2;
      tree1.insert(prefix);
      tree2.insert(suffix);
  }
//  int length=((n/2)+1);
    for(int i=0;i<(n-1);i++)
    	ans=max(ans,t1[i]+t2[i+1]);
    
    cout << ans << endl;
 
  return 0;
} 
