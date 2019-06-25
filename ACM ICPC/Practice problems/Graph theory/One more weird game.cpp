/*eha is playing a very interesting game. The game will be played on a rectangular grid consisting of N rows and M columns. Initially all the 
cells of the grid are uncolored.

Leha's initial score is zero. At each turn, he chooses some cell that is yet not colored, and colors that cell. The score obtained in this step 
will be number of neighboring colored cells of the cell that Leha colored in this step. Two cells are neighbors of each other if they share a 
side between them. The game will end when all the cells are colored. Finally, total score obtained at the end of the game will sum of score 
obtained in each turn.

Leha wants to know what maximum score he can get? Can you please help him in finding this out?

Input

The first line contains a single integer T denoting the number of test cases. T test cases follow.

Each of the following T lines contains two space-separated integers N, M denoting the dimensions of the grid.

Output

For each test case, output a single line containing an integer corresponding to the maximal possible score Leha can obtain.

Constraints

1 ≤ T ≤ 100
1 ≤ N, M ≤ 1 000
Subtasks

Subtask #1[30 points]: 1 ≤ N, M ≤ 3
Subtask #2[70 points]: 1 ≤ N, M ≤ 1000*/

/*EXPLANATION:
Let us solve the first subtask before proceeding to the next one. In this subtask, we have 1≤n,m≤31≤n,m≤3. Without loss of generality, we can 
assume that n≤mn≤m, i.e. answer for grid of dimensions n,mn,m where n≤mn≤m, will be same as that of a grid of dimensions m,nm,n where m≤nm≤n,
 because both the grids are essentially the same. You can rotate one to obtain the other.

So, we are now left to deal with following cases.

n=1,m=1n=1,m=1 : You can just colour the current cell. Total score will be obtained will be zero.
n=1,m=2n=1,m=2 : Colour any of the cells first. For colouring the second cell, you will get a score of 1.
n=1,m=3n=1,m=3 : There are three cells. There are total 3! ways of choosing the order of the cells to color. Let us find scores for some of them.
Colour the cells in the order, i.e. first cell will be colored first, then second followed by third. Colouring first cell won't fetch you any 
score, whereas that of second and third cells will fetch you a score of 1 each. Total score obtained will be 2.
Colour the second cell first, then you can choose either to color the first cell or the third cell. Overall you will get a score of 2.
n=2,m=2n=2,m=2 : You will obtain a score of 4.
n=2,m=3n=2,m=3 :
You can color cell (1, 1) first, then cell (2, 1) followed by (1, 2) followed by (2, 2), then (1, 3) followed by (2, 3), i.e. you are colouring 
cells in the column wise order. Your total score will be 0 + 1 + 1 + 2 + 1 + 2 = 7.
Try some other order you will find that your score will always be 7.
n=3,m=3n=3,m=3 : Total score obtained will be 12.
So, for solving the small subtask, you can just find these values manually and solve the problem. Here is one sample code.


    read n, m
    if (n > m):
        swap(n, m)
    if (n == 1):
        if (m == 1): print 0
        if (m == 2) : print 1
        if (m == 3) : print 2
    else if (n == 2):
        if (m == 2) : print 4
        if (m == 3) : print 7
    else if (n == 3):
        if (m == 3) : print 12

Probably a better way of implementing this way would be encode these values in a two dimensional array and output them. It will save you a lot 
of if/else conditions which are prone to missing some cases.


    int ans[3][3] = {
        {0, 1, 2},
        {0, 4, 7},
        {0, 0, 12};
    }
    read n, m
    print ans[n - 1][m - 1]

Now, you might have realized that somehow the order of coloring the vertices does not matter. Let us find a formal proof of this condition, 
and later we will understand how to use this to solve the full subtask.

Consider a graph whose vertices correspond to the cells of the grid. There will be an edge between two vertices if their corresponding cells 
are adjacent.

Now, let us understand the colouring process on this graph instead of the grid. So, colouring a cell is equivalent to colouring a vertex of the 
graph. As score obtained for coloring a cell is equal to number of coloured neighbours of the cell. This means that score obtained will be 
number of edges between the current cell and its adjacent coloured cells. So, we wonder whether we can transform our problem in terms of 
counting edges instead?

Whenever we color an adjacent cell of some already coloured cell, we will mark the edge between those cells. Also marking an edge will give 
you a score of 1. So, our total score will number of times the edges were marked.

Crucial point to note is that after the end of coloring all cells, all the edges of the graph will be marked. This is simply due to that fact 
each of the grid cells are coloured.

One interesting fact is that the each edge of the graph will be marked only onceonce. This is due to the fact that an edge connects two cells. 
We mark the cell when both the cells are coloured. We are not allowed to colour any cell more than once, which guarantees that we will mark 
each cell only once.

So, in whatever order you colour the cells, the number of edges marked are going to remain the same, so your score is also going to be same.

Now we can use this fact to find a solution of the problem. We can just implement this process by iterating over the cells of the matrix in 
any way which want and maintain which of the cells are coloured and count the corresponding score. Pseudo code follows.


    read n, m
    colored[n][m]; // Initially none of the cells are coloured. 
    // We are using row major order. You can however use any order of visiting the cells you want.
    score = 0;
    for i = 1 to n:
        for j = 1 to m:
            for all neighbours of cell (i, j):
                if (colored[i][j]):
                    score += 1
    print score

We can even find a closed form formula for the score. Let us find total number of edges in a n×mn×m dimensional grid. We know that sum of 
degrees of all the vertices of the graph is twice the number of edges. It is easier to find sum of degrees of vertices in our case. All the 
vertices in the inner boundary of the grid have a degree of 4. The corner vertices on the boundary will have a degree of 2, remaining vertices 
on the boundary will have degree of 3.

Hence, sumofdegrees=4(n−2)(m−2)+3*2*(n−2+m−2)+2*4
					=4(n−2)(m−2)+6n+6m−24+8
					=4nm−8n−8m+16+6n+6m−24+8=
					4nm−2n−2m
					
So total number of edges will = 2(nm−n−m)2(nm−n−m).

TIME COMPLEXITY
It will be O(1)O(1) if we just print the answer as 2nm−n−m.
It will be O(nm)O(nm) for the observation based solution that we can colour the grid in any order.*/
#include <stdio.h>

int main() {
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n", (n*(m-1) + m*(n-1)));
	}
	return 0;
}


