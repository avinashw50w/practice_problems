// 101 hack oct //
/**/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 9001
bool mark[MAX],a[MAX],b[MAX];
int primes[MAX],w;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    for(int i=2;i*i<MAX;i++){
        if(!mark[i]){
            for(int j=i*i;j<MAX;j+=i) mark[j]=true;
        }
    }
    for(int i=2;i<MAX;i++){
        if(!mark[i]) primes[++w]=i;
    }
    for(int i=1;i<=w;i++){
        for(int j=1;j<=w;j++)
            a[primes[i]|primes[j]]=true;
    }
    for(int i=1;i<MAX;i++){
        if(a[i]){
            for(int j=i;j<MAX;j++){
                if(a[j])
                    b[i|j] = true;
            }
        }
    }
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(b[n]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

