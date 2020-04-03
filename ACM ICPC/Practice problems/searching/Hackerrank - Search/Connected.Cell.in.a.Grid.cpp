/* You are given a matrix with m rows and n columns of cells, each of which contains either 1 or 0. Two cells are said to be connected 
if they are adjacent to each other horizontally, vertically, or diagonally. The connected and filled (i.e. cells that contain a 1) 
cells form a region. There may be several regions in the matrix. Find the number of cells in the largest region in the matrix.

Input Format
There will be three parts of t input:
The first line will contain m, the number of rows in the matrix.
The second line will contain n, the number of columns in the matrix.
This will be followed by the matrix grid: the list of numbers that make up the matrix.

Output Format
Print the length of the largest region in the given matrix.

Constraints
0<m<10
0<n<10

Sample Input:

4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
Sample Output:
5                                      */

#include <iostream>
#include <vector>
using namespace std;
int ans;
int px[8]={0,0,1,-1,1,-1,1,-1};
int py[8]={1,-1,0,0,1,-1,-1,1};
int num;
void rec(vector<vector<int>>& a,int x, int y)
{
 
	ans=max(ans,num);
	for(int i=0;i<8;++i)
	{
		if( a[x+px[i]][y+py[i]]==1)
		{
			a[x+px[i]][y+py[i]]=0;
			++num;
			rec(a,x+px[i],y+py[i]);
		}
	}
 
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int>> a( n+2, vector<int>(m+2,0));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]==1)
			{
				a[i][j]=0;
				num=1;
				rec(a,i,j);
			}
	cout<<ans;
	return 0;
}
