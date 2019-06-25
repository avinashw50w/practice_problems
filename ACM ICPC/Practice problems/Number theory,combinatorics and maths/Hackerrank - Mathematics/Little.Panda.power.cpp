#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
ll phi(ll n){
    ll res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) res-=res/i;
        while(n%i==0) n/=i;
    }
    if(n>1) res-=res/n;
    return res;
}
ll modpow(ll a,ll b,ll m){
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return res;
}
ll mmi(ll a,ll m){
    ll phi_m = phi(m);
    return modpow(a,phi_m-1,m);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    while(t--){
        ll A,B,X,ans=0;
        cin>>A>>B>>X;
        if(B>=0){
            ans = modpow(A,B,X);
        }
        else{
            ll mmi_A = mmi(A,X);
            ans = modpow(mmi_A,abs(B),X);
        }
        cout<<ans<<"\n";
    }
    return 0;
}

