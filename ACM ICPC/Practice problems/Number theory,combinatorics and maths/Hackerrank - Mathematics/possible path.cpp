#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
ll gcd(ll a,ll b){return (b==0)?a:gcd(b,a%b);}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    ll a,b,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b>>x>>y;
        if(gcd(a,b)==gcd(x,y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

