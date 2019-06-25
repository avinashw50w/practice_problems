#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//  total no of handshakes = (n-1) + (n-2) + (n-3) + .......+ 1
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int ans = (long long int)(n*(n-1))/2;
        cout<<ans<<endl;
    }
    return 0;
}

