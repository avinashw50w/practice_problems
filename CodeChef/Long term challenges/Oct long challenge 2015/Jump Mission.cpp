#include<bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define MAX 300000+2
using namespace std;


void solve(int n,int prev[],ll energy[]){
	int curr = n-1;
	ll min_energy=0;
	while(curr!=0){
		min_energy+=energy[curr];
		curr = prev[curr];
	}
	printf("%lld",min_energy);
}
int main(){
    int N;
	scanf("%d",&N);
	int prev[N+1];
	ll energy[N+1];
	int P[N+1];
	int A[N+1],H[N+1];
	for(int i=0;i<N;i++)
	scanf("%d",&P[i]);
	for(int i=0;i<N;i++)
	scanf("%d",&A[i]);
	for(int i=0;i<N;i++)
	scanf("%d",&H[i]);
	prev[0]=0;
	energy[0]=0;
	ll min;
	for(int i=1;i<N;i++){
		min=100000000000;
		for(int j=i-1;j>=0;j--){
			if(P[i]>P[j]){
				ll t=abs(H[i]-H[j]);
				energy[i] = A[i] + A[j] + (t*t);
				if(energy[i]<=min){
					min=energy[i];
					prev[i] = j;
				}
			}
		}
		energy[i] = min;
	}
	solve(N,prev,energy);
	return 0;
}

