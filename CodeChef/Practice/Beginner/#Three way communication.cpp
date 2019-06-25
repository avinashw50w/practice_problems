#include <iostream>
#include <cmath>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int t;cin>>t;
	while(t--){
		int r,coord[3][2];
		cin>>r;
		cin>>coord[0][0]>>coord[0][1];
		cin>>coord[1][0]>>coord[1][1];
		cin>>coord[2][0]>>coord[2][1];
		int cnt = 0;
		if(pow(coord[1][0]-coord[0][0], 2) + pow(coord[1][1]-coord[0][1], 2) <= r*r) cnt++;
		if(pow(coord[2][0]-coord[1][0], 2) + pow(coord[2][1]-coord[1][1], 2) <= r*r) cnt++;
		if(pow(coord[2][0]-coord[0][0], 2) + pow(coord[2][1]-coord[0][1], 2) <= r*r) cnt++;
		
		if(cnt>=2) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
