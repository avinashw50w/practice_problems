#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long int T;
    cin>>T;
    while(T--){
        long int N, C=0, NC=0;
        cin>>N;
        long int arr[N],sub[N];
        bool positive = false;
         
        for(long int i=0;i<N;i++){
            cin>>arr[i];
         
            if(arr[i]>0){
                NC+=arr[i];
                positive = true;
            }
             
            //generating subsequence array
            if(i==0){                
                sub[i]=arr[i];
            }else{
                sub[i] = max(sub[i-1]+arr[i],arr[i]);
            } 
        }
         
        C = *(max_element(sub,sub+N));
         
        //fix if all are negative
        if(!positive){
            NC = *(max_element(arr,arr+N));
        }
         
        cout<<C<<" "<<NC<<endl;
    }
    return 0;
}
// another way to solve without using dp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define oo (1<<30)
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n],maxx=-oo,prefix=0,sum=0,f=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            prefix+=a[i];
            maxx=max(maxx,prefix);
            if(prefix<0) prefix=0;
            if(a[i]>0){sum+=a[i];f=1;}
        }
        if(!f)sum=*(max_element(a,a+n));
        cout<<maxx<<" "<<sum<<endl;
    }
    return 0;
}


