#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)

// a codechef problem on :find the no of ways to reach (m,n) from (1,1) if some coordinates are blocked
using namespace std;
	ll grid[1002][1002]={0};
	int blocked[1002][1002]={0};
int main(){
	int m,n,p,x,y; cin>>m>>n>>p;
	rep(i,0,p-1){
		cin>>x>>y;
		blocked[x][y]=1;
	}
	if(blocked[1][1]) {cout<<"0\n"; return 0;}

	grid[1][1] =1;
	rep(i,1,m){
		rep(j,1,n){
			if(i==1 && j==1) continue;
			if(!blocked[i][j]) 
			grid[i][j] = (grid[i-1][j] + grid[i][j-1])%mod;
		}
	}
	 cout<<grid[m][n]<<"\n";
	return 0;
}

