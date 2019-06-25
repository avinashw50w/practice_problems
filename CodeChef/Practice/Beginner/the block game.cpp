#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int n=s.size();
		int f=0;
		for(int i=0;i<n/2;i++){
			if(s[i]!=s[n-i-1]){
				f=1; break;
			}
		}
		if(f==0) cout<<"wins\n";
		else cout<<"losses\n";
	}
}
