#include<iostream>
using namespace std;
void solve(int n){
	int ans = 0;
	if(n>=100) { ans += n/100; n %= 100; }
	if(n>=50) { ans += n/50; n %= 50; }
	if(n>=10) { ans += n/10; n %= 10; }
	if(n>=5) { ans += n/5; n %= 5; }
	if(n>=2) { ans += n/2; n %= 2; }
	ans += n;
	cout<< ans <<endl;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		solve(n);
	}
}
