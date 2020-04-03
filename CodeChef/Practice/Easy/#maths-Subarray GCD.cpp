#include<iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
	int t ,i;cin>>t;
	int a[100000+5];
	while(t--){
		int n; cin>>n;
		cin>>a[0];
		int g = a[0];
		for(i=1;i<n;i++) {
			cin>>a[i];
			g = __gcd(g,a[i]);
			if(g==1) break;
		}
		for(i++;i<n;i++) cin>>a[i];
		if(g==1) cout<<n<<endl;
		else cout<<-1<<endl;
	}
}

/* Given an array A1,A2...AN, you have to print the size of the largest contiguous subarray such that
GCD of all integers in that subarray is 1.

Formally,
For a subarray Ai,Ai+1...Aj where 1 = i < j = N to be valid: GCD(Ai,Ai+1...Aj) should be 1. You have to print the size of the largest valid subarray.

If no valid subarray exists, output -1.
Note:A single element is not considered as a subarray according to the definition of this problem. 

explanation : if the gcd of any two numbers comes 1 , then the gcd of all the numbers with 1 is 1. so the ans is n if gcd of the consecutive nos is 1.*/
