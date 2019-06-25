#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {

    int t,n,k,p=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n,greater<int>());
        sort(b,b+n);
        p=0;
        for(int i=0;i<n;i++)
        {
            if((a[i]+b[i])>=k)
                p++;
        }
        if(p==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
