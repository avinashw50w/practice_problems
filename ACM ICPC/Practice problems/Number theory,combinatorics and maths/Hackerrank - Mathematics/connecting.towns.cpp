#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        long long int paths=1;
        int n,a;
        cin>>n;
        for(int i=0;i<n-1;i++){
            cin>>a;
            paths=(paths*a)%1234567;
        }
       
        cout<<paths<<endl;
    }
    return 0;
}

