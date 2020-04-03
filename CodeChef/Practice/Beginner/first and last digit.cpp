#include <iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string n; cin>>n;
		cout<<(n[0]-'0')+(n[n.size()-1]-'0')<<endl;
	}
}
