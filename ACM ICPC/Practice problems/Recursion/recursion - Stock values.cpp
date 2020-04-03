#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[25], maxi, n;

void solve(int idx) {
    if(idx == n) {
        int sum = 0;
        for(int i=1; i<=floor(n/2); ++i)
            sum += abs(a[i] - a[n-i+1]);
        maxi = max(maxi, sum);
        return;
    }
    
    int tmp = a[idx];
    if(!(a[idx-1]&1)&& !(a[idx+1]&1)) {
        a[idx] = (a[idx-1] + a[idx+1])>>1;
        solve(idx+1);
    }
    
    a[idx] = tmp;
    solve(idx+1);
    return;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        maxi = -100000000;
        solve(2);
        
        cout<<maxi<<"\n";
    }
    return 0;
}
