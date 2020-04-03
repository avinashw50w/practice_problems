#include <iostream>
#include <cmath>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int b,l;
		float rmin,rmax;
		cin>>b>>l;
		rmin = sqrt(abs(b*b-l*l));
		rmax = sqrt(b*b+l*l);
		cout<<rmin<<" "<<rmax<<"\n";
	}
	return 0;
}