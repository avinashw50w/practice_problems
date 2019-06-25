#include <iostream>
using namespace std;
long long unsigned int fac[19];
int main(){
	int t;cin>>t;
	fac[1] = fac[0] = 1;
	for(int i=2;i<20;++i) fac[i]= i*fac[i-1];
	while(t--){
		int n;cin>>n;
		cout<<fac[n]<<endl;
	}
}
