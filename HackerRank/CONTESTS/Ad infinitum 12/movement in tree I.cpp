#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
#define mod 1000000007
ll modpow(ll a,ll b,ll m){
    if(b==0) return 1;
    ll x=modpow(a,b/2,m);
    x=(x*x)%m;
    if(b&1) x=(x*a)%m;
    return x;
}
ll phi(ll n){
    ll res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) res-=res/i;
        while(n%i==0) n/=i;
    }
    if(n!=1) res-=res/n;
    return res;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        ll d,k,h; cin>>d>>k>>h;
        if(d==1) {cout<<k+1<<"\n";continue;}
        ll a=(modpow(d,(k+1),mod) -1)%mod;
        ll b = modpow((d-1),(mod-2),mod);
        cout<<(a*b)%mod<<endl;
    }
    return 0;
}

