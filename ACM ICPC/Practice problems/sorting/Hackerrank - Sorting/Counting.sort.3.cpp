#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define SIZE 1010101
using namespace std;
int a[SIZE],b[SIZE],c[101]={0};
string s[SIZE];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];cin>>s[i] ;c[a[i]]++;}
    for(int i=1;i<101;i++) c[i]+=c[i-1];

    for(int i=0;i<100;i++) cout<<c[i]<<" ";
    
    return 0;
}
