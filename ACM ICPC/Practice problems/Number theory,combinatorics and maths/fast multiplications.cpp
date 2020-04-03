#include <iostream>
using namespace std;

int main() {
	
	// your code here
	int t;
	cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		if(a==0 || b==0){ cout<<0<<endl;continue;}
		int arr[100000],arr_sz=0;
		int i=0;
		while(a){
			arr[i]=a%10;
			a/=10;
			i++; arr_sz++;
		}
		int carry=0;
		for(int i=0;i<arr_sz;i++){
			int p=arr[i]*b + carry;
			arr[i]=p%10;
			carry=p/10;
		}
		while(carry){
			arr[arr_sz]=carry%10;
			carry/=10;
			arr_sz++;
		}
		for(int i=arr_sz-1;i>=0;i--) cout<<arr[i];
		cout<<endl;
	}

	return 0;
}
