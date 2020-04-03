#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll pre_sum=0,maxx=0,a;
        set<ll> s;
        s.insert(0);
        for(int i=0;i<n;i++){
            cin>>a;
            pre_sum=(pre_sum+a)%m;
            maxx=max(maxx,pre_sum);   // if S[j]==0
            set<ll>::iterator it=s.lower_bound(pre_sum+1);
            if(it!=s.end()) maxx=max(maxx,m+pre_sum-(*it));
            s.insert(pre_sum);
        }
        cout<<maxx<<endl;
    }
    return 0;
}

