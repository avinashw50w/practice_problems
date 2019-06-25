#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,q;
    cin>>n>>q;
    ll a;
    vector<ll> v;
    for(int i=0;i<n;i++) {cin>>a; v.push_back(a);}
    int sz=v.size();
    while(q--){
        ll x,k,t,l,h;
        cin>>x>>k>>t;
        if(t==0){
            l=upper_bound(v.begin(),v.end(),x)-v.begin();  //cout<<l;
            if(l+k>sz){cout<<-1<<endl;continue;}
            else {cout<<v[l+k-1]<<endl;}
        }
        if(t==1){
            h=lower_bound(v.begin(),v.end(),x)-v.begin();
            if(h-k<0){cout<<-1<<endl;}
            else{ cout<<v[h-k]<<endl;}
        }
    }
    return 0;
}

