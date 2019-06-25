#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		string n;
		cin>>n;
		int i = n.size()-1;
		int ans = 0;
		while(i>=0){
			if(n[i]=='4') ans++;
			i--;
		}
		cout<<ans<<endl;
	}
}
