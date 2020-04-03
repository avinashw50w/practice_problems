#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        long long int n,ans; cin>>n;
        ans = ((n%mod)*(n%mod))%mod;
        cout<<ans<<endl;
    }
    return 0;
}

