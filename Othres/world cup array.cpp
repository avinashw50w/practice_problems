#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,q,c,l,r,i,j,prod;
    int op;
    scanf("%lld %lld",&n,&q);
    long long int a[n],b[n]; 
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    while(q--){
        scanf("%d",&op);
        if(op==1){
        scanf("%lld %lld %lld",&l,&r,&c);
            for(i=l;i<=r;i++)
                a[i]+=c;
    }
        if(op==2){
            scanf("%lld %lld %lld",&l,&r,&c);
            for(i=l;i<=r;i++)
                b[i]+=c;
        }
        if(op==3){
            prod=0;
            scanf("%lld %lld",&l,&r);
            for(i=l;i<=r;i++)
               prod+= (a[i]*b[i]);
            printf("%lld\n",prod%1000000007);
        }
    }
    return 0;
}

