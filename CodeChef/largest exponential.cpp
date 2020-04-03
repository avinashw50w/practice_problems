/*  AK - 47  aka Avin@sh   */
#include<iostream>
#include<cmath>         
#include<utility>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define lli long long int

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    lli b,e,k,i,j;
    vector<pii> v;
    lli key,p,q;
    for(i=0;i<n;i++){
        cin>>b>>e;
        v.push_back(make_pair(b,e));
    }
    cin>>k;
    for(i=1;i<n;i++){
        key= (v[i].second)*log(v[i].first);
        p=v[i].first;
        q=v[i].second;
        j=i-1;
        while(j>=0 && ((v[j].second)*log(v[j].first))>key){
            v[j+1].first=v[j].first;
            v[j+1].second=v[j].second;
            j--;
        }
        v[j+1].first=p;
        v[j+1].second=q;
    }
    cout<<v[k-1].first<<" "<<v[k-1].second;
    return 0;
}

