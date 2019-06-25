#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int r;
		cin>>r;
		string s; cin>>s;
		int Y=0,I=0;
		for(int i=0;s[i];++i){
			if(s[i]=='Y') {
				Y=1;break;
			}
			if(s[i]=='I') {
				I=1;break;
			}
		}
		if(Y) cout<<"NOT INDIAN\n";
		else if(I) cout<<"INDIAN\n";
		else cout<<"NOT SURE\n";
	}
}
