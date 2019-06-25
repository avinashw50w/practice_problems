#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,l,b;
    cin>>t;
    while(t--){
        cin>>l>>b;
        int g=gcd(l,b);
        int ans = (l/g)*(b/g);
        cout<<ans<<endl;
    }
    return 0;
}

