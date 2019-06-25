/* Ramesh, Suresh, Mahesh, and Mukesh are moving to a new city and are looking for apartments to live.
Now this city is not like any other city. This city is a matrix of apartments and there are no roads. The only way to commute is to go through apartments.
If any of the friends go through an apartment even once, the group will have to pay its full rent. From an apartment, you can go to the apartments to its
 North, South, East, or West.
Since Ramesh, Suresh, Mahesh, and Mukesh are best friends, they want to meet each other at least once a month. Also, all four are highly superstitious, 
so Ramesh only goes West, Suresh only goes North, Mahesh only goes East, and Mukesh only goes South.
Any number of people can live in any of the apartments. Cost of all the apartments in the city is given, some of which may be negative. Negative cost means 
if any of the friend lives in or goes through this apartment, the group will get paid an amount equal to the negation of the cost. Now the aim of the four friends is to find the minimum cost for which all of them can live in the city and meet each other at least once a month.
Note: The four friends can meet in an apartment where none of them actually lives as well.

Input

First line contains T, the number of test cases to follow.
First line of each test case contains two integers: N and M, where N denotes the number of rows in the matrix and M denotes number of columns in the matrix.
Next N lines describe the rows of the matrix follow, one row per line. Each row contains M space-separated integers denoting the cost of the apartment.
Output

For each test cases, output the minimum cost as asked in the problem.
Constraints

1 = T = 4*104
1 = N = 103
1 = M = 103
-104 = Cost of any apartment = 104
1 = Sum of N*M over all test cases = 106
Example

Input:
4
3 3
1 2 3
4 -10 5
6 7 8
3 3
1 -10 3
-13 -12 -11
7 8 9
3 3
1 -2 3
-4 5 -6
7 -8 9
4 4
1 2 3 4
5 6 -7 8
-9 -10 -11 -12
13 14 -15 16

Output:
-10
-46
-15
-64
Explanation

Example case 1.All 4 friends stay at the apartment which has rent -10.
Example case 2.Mukesh lives in the apartment with rent -10, Mahesh lives in the apartment with rent -13, Suresh lives in the apartment with rent -12,
 and Ramesh lives in the apartment with rent -11
Example case 3.Mukesh lives in the apartment with rent -2, Mahesh lives in the apartment with rent -4, Suresh lives in the apartment with rent -8, 
and Ramesh lives in apartment with rent -6. They all meet at the apartment with rent 5. 
So the total cost becomes (-2) + (-6) + (-4) + (-8) + (5) = -15
Example case 4.Mukesh lives in the apartment with rent -7, Mahesh lives in the apartment with rent -9, Suresh lives in the apartment with rent -15, 
and Ramesh lives in the apartment with rent -12. They all meet at the apartment with rent -11. So the total cost becomes -7-9-10-11-12-15 = -64  */ 

using namespace std;
#define left le
#define right ri
int a[1007][1007];
int up[1007][1007], down[1007][1007], left[1007][1007], right[1007][1007];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= m + 1; j++)
			{
				a[i][j] = 0;
				up[i][j] = 0;
				down[i][j] = 0;
				left[i][j] = 0;
				right[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				up[i][j] = min(0, up[i - 1][j] + a[i][j]);
				left[i][j] = min(0, left[i][j - 1] + a[i][j]);
			}
		}
		for (int i = n; i >= 1; i--)
		{
			for (int j = m; j >= 1; j--)
			{
				down[i][j] = min(0, down[i + 1][j] + a[i][j]);
				right[i][j] = min(0, right[i][j + 1] + a[i][j]);
			}
		}
		int ans = 1000 * 1000 * 1000 + 7;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				ans = min(ans, up[i - 1][j] + left[i][j - 1] + down[i + 1][j] + right[i][j + 1] + a[i][j]);
			}
		}
		printf("%d\n", ans);
	}
} 
