#include<iostream>
#include<cstdio>
#include<vector>
#define size 160

using namespace std;
void factorial(int);

int main(){
	//ios_base::sync_with_stdio(false);
	int t,n;
	scanf("%d",&t);
	while(t--){
		cin>>n;
		factorial(n);
		cout<<"\n";
	}
	return 0;
}

void factorial(int n){
	int arr[size];
	arr[0] = 1;
	int arr_size=1;
	for(int x=2;x<=n;x++){
			int carry=0;
			for(int i=0;i<arr_size;i++){
			int prod = arr[i]*x + carry;
			arr[i] = prod%10;
			carry = prod/10;
		}
		while(carry){
		arr[arr_size] = carry%10;
		carry = carry/10;
		arr_size++;
		}
	}
	for(int i=arr_size-1;i>=0;i--)
	cout<<arr[i];
}
