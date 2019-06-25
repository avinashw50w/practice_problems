#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define ll long long int
int mark[1000001];
vector<long long int> v;
ll sum=0;
void factors(ll n){
    ll r;
    vector<int> temp;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
                int sz=v.size();
                for(int j=0;j<sz;j++){
                  r=i*v[j]; 
                 if(!mark[r]){
                     temp.push_back(r); 
                     mark[r]=1;
                    sum=(sum+r)%mod;
              	 }
            
            }
        }
        if(i!=(n/i) && n%(n/i)==0){
        
                int sz=v.size();
                for(int j=0;j<sz;j++){
                    r=(n/i)*v[j];
                    if(!mark[r]){
                     temp.push_back(r);
                     mark[r]=1;
                    sum=(sum+r)%mod;
               		}
                }
        }
    }
    int sz1=temp.size();
    for(int i=0;i<sz1;i++) v.push_back(temp[i]);
}
void factorsn(ll n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            sum=(sum+i)%mod;
                v.push_back(i);
            mark[i]=1;
        }
        if(i!=(n/i) && n%(n/i)==0){
            sum=(sum+(n/i))%mod;
            v.push_back(n/i);mark[n/i]=1;
    	}
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ll n,q; cin>>n>>q;
    memset(mark,0,sizeof(mark));
   // vector<int> nfac;
    factorsn(n);
    
    while(q--){
        int x; cin>>x;
        factors(x);
      // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        cout<<sum<<"\n";
     //  memset(mark,0,sizeof(mark));
    }
    
    return 0;
}

