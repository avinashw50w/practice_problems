#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod int(1e9)
#define ll long long int
using namespace std;
ll memo[1000][1000];
ll mpow(ll a,ll b,ll m){
    if(b==0)return 1;
    ll x=mpow(a,b/2,m);
    x=(x*x)%m;
    if(b&1) x=(x*a)%m;
    return x;
}

ll nCr(ll n,ll r){
    if(memo[n][r]) return memo[n][r];
        if(n==r || r==0) return 1;
    else memo[n][r]=(nCr(n-1,r)%mod+nCr(n-1,r-1)%mod)%mod;
    return memo[n][r];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        for(int i=0;i<=n;i++){
            cout<<nCr(n,i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

