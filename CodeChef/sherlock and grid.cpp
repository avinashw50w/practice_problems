/*Sherlock is stuck. There is a N X N grid in which some cells are empty (denoted by ‘.’), while some cells have rocks in them
 (denoted by ‘#’). Sherlock is on the South of the grid. He has to watch what is happening on the East of the grid. He can place
  a mirror at 45 degrees on an empty cell in the grid, so that he'll see what is happening on East side by reflection from the mirror.

But, if there's a rock in his line of sight, he won't be able to see what's happening on East side. For example, 
following image shows all possible cells in which he can place the mirror. 

You have to tell Sherlock in how many possible cells he can place the mirror and see what's happening on East side.
Input

First line, T, the number of testcases. Each testcase will consist of N in one line. Next N lines each contain N characters.
Output

For each testcase, print the number of possible options where mirror can be placed to see on the East side.
Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 1000
 
Example

Input:
2
3
#..
#..
#..
3
#.#
#.#
#.#

Output:
6
0
*/

#include <iostream>
#include <string>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n; cin>>n;
		string grid[n+1];
		int rayX[n+1][n+1],rayY[n+1][n+1];
		for(int i=0;i<n;i++) cin>>grid[i];

		for(int i=0;i<n;i++){
			int blocked=0;
			for(int j=n-1;j>=0;j--){
				if(grid[i][j]=='#') blocked=1;
				rayX[i][j]=blocked;
			}		
		}
		for(int j=0;j<n;j++){
			int blocked=0;
			for(int i=n-1;i>=0;i--){
				if(grid[i][j]=='#') blocked=1;
				rayY[i][j]=blocked;
			}		
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(rayX[i][j]==0 && rayY[i][j]==0)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//  another simple way

int hor[n],vet[n];
memset(hor,-1,n);
memset(vet,-1,n);

for(int i=0;i<n;i++){
	for(int j=n-1;j>=0;j--){
		if(grid[i][j]=='#'){ 
			hor[i]=j;             // mark the rightmost column of row i which has an obstacle
			break;
		}
	}
}

for(int j=0;j<n;j++){
	for(int i=n-1;i>=0;i--){
		if(grid[i][j]=='#'){
			vet[j]=i;            // mark the bottom most row of column j which has an obstacle
			break;
		}
	}
}
int ans=0;
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(i>vet[j] && j>hor[i]) ans++;        // if there is not obstacle on right or below, then a mirror can be placed there
	}
}

cout<<ans;
