#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int L,S1,S2,Q,q;
    cin>>L>>S1>>S2;
    cin>>Q;
    long long int s=abs(S1-S2);
    while(Q--){
        cin>>q; 
        double t = (sqrt(2)*L-sqrt(2)*sqrt(q))/s;
            printf("%lf\n",t);
        
    }
    return 0;
}

