#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ll n,k,q;
    cin>>n>>k>>q;
    ll a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];
    ll x;
    while(q--){
        cin>>x;
        ll pos=x-k+n;
        while(pos<0) pos+=n;
        cout<<a[pos%n]<<endl;
    }
    return 0;
}

