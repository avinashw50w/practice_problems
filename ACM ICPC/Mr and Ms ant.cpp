/*
Mr. and Mrs. Ant are very hungry. So, they want to collect food as much as they can. They can search for foods simultaneously.
 To do so, they start from their house and collect all foods together and meet in some place (not necessarily their house).
  Finally, they eat together.
The world of Mr. and Mrs. Ant is a two dimensional grid. Each cell is either the home, or free, or blocked, or contains a food.
 Two cells are adjacent if they share an edge. In each second, they can move from one cell to another cell simultaneously. 
 One can decide to not to move in some step, while other may move. One cell can be visited many times. Both of them can move 
 into the same cell also.
In this problem, the grid is given by an R x C matrix represented by following characters:
Character	Meaning							Remarks
H			Home of Mr. and Mrs. Ant		Occurs exactly once
F			A food item						Occurs at least once, at most 8 times
. (dot)		Free (passable) cell			-
# (hash)	Blocked Cell					-


Given the grid information, give the minimum amount of time that must be needed for them to collect all the foods and then meet.

Input
The first line of input will contain T (T <= 30) denoting the number of cases. Each case starts with two integers R and C (2 <= R, C <= 12).
 Then, R lines follow giving the grid.

 Output
For each case, print the case number, the minimum amount of time (in seconds) that must be needed for them to collect all the foods and meet.
 If it is impossible to collect all the food items, output -1 (negative one) instead.
Example

Input:
2
2 3
H#.
.#F
2 6
F#F..#
..H#.F
Output:
Case 1: -1
Case 2: 8
*/

# include <cstdio>
# include <algorithm>
 
using namespace std;
 
char maze[12][13];
int dist[12][12][12][12];
int neigh[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int arr[8];
int coord[9][2];        // for storing the location of home and food
 
int main()
{
	int T;
	scanf("%d",&T);
	
	for(int t=0;t<T;t++)
	{
		int R,C;
		scanf("%d%d",&R,&C);
		
		for(int i=0;i<R;i++)
			scanf("%s",maze[i]);
		
		int cnt=1;
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
			{
				for(int k=0;k<R;k++)
					for(int l=0;l<C;l++)
						dist[i][j][k][l]=1000000;
				if(maze[i][j]!='#')	  dist[i][j][i][j]=0;
				if(maze[i][j]=='H')	  {coord[0][0]=i;coord[0][1]=j;}
				else if(maze[i][j]=='F')	{coord[cnt][0]=i;coord[cnt++][1]=j;}
			}
		
		for(int chaathu=0;chaathu<(12*12);chaathu++)
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
				{
					for(int q=0;q<4;q++)
					{
						int k=i+neigh[q][0],l=j+neigh[q][1];
						if(k>=0 && k<R && l>=0 && l<C && maze[k][l]!='#')
							for(int m=0;m<R;m++)
								for(int n=0;n<C;n++)
									if(dist[m][n][k][l]>dist[m][n][i][j]+1)
										dist[m][n][k][l]=dist[m][n][i][j]+1;
					}
				}
		
		cnt--;
		for(int i=0;i<cnt;i++)
			arr[i]=i+1;
		
		int mindist=1000000;
		do
		{
			int start=0,disttot=0;
			for(int i=0;i<cnt;start=arr[i++])
				disttot+=dist[coord[start][0]] [coord[start][1]] [coord[arr[i]][0]] [coord[arr[i]][1]];
			disttot+=dist[coord[start][0]] [coord[start][1]] [coord[0][0]] [coord[0][1]];
			disttot>>=1;
			if(mindist>disttot)mindist=disttot;
		}while(next_permutation(arr,arr+cnt));
		
		printf("Case %d: %d\n",t+1,mindist>10000?-1:mindist);
	}
	return 0;
}