#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int count=0;
		for(int i=1;i*i<=n;i++){
			if(n%i==0){
				if(i%2==0) count++;
				if(i!=n/i){
					if((n/i)%2==0)
					count++;
				}
			}
		}
		cout<<count<<"\n";
	}	
	return 0;
}
