#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin>>n;
    int a[n+1],swaps=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int j=i-1, k=a[i];
        while(j>=0 && a[j]>k){
            a[j+1]=a[j];
            j--;
            swaps++;
        }
        a[j+1]=k;
    }
    cout<<swaps;
    return 0;
}

