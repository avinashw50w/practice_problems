// finding maximum sum of subarray not greater than M.

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	ll n,m,a; cin>>n>>m;
	deque<ll> v;
	ll prefix=0,ans=0;
	for(int i=0;i<n;i++){
		cin>>a;
		prefix+=a;
		v.push_back(a);
		while(prefix>m){
			prefix-=v[0];
			v.pop_front();
		}
		ans = max(ans,prefix);
	}

	cout<<ans<<endl;
	return 0;
}
