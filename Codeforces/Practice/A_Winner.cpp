#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
	unordered_map<string,int> m;
	int t;cin>>t;
	string winner;
	int maxx = 0;
	while(t--){
		string s;
		cin>>s;
		int n; cin>>n;
		if(m.find(s)!=m.end()) m[s] += n;
		else m[s] = n;
		
		if(m[s] > maxx) maxx = m[s];
	}
	for(auto &x : m){
		if(x.second == maxx){
			winner = x.first;
			break;
		}
	}
	cout<<winner<<endl;
}
