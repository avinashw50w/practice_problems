#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),greater<int>());
	cout<<v[0]<<" ";
	for(int i=1;i<v.size();i++){
		if(v[i]!=v[0]){
			cout<<v[i]<<endl;
			break;
		}
	}
	return 0;
}
