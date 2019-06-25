#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[100000+5];
int main(){
	ios_base::sync_with_stdio(0);
	int t; cin>>t;
	int n;
	while(t--){
		cin>>n;
		ll sum = 0;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			sum += a[i];
		}
		if(sum%n != 0) {
			cout<<"No Treat\n";
			continue;
		}
		ll required = sum/n;
		
		ll ans = 0;
		for(int i=0;i<n;i++){
			if(a[i]<required)
			ans += required-a[i];
		}
		cout << ans << endl;
	}
	return 0;
}
