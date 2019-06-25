/* Hermione Granger is lost in the Forbidden Forest while collecting some herbs for a magical potion. The forest is magical and has only
 one exit point, which magically transports her back to the Hogwarts School of Witchcraft and Wizardry. 
The forest can be considered as a grid of N×M size. Each cell in the forest is either empty (represented by '.') or has a tree 

(represented by 'X'). Hermione can move through empty cells, but not through cells with a tree in it. She can only travel LEFT, RIGHT, UP, 
and DOWN. Her position in the forest is indicated by the marker 'M' and the location of the exit point is indicated by '*'. Top-left corner 
is indexed (0, 0).

.X.X......X
.X*.X.XXX.X
.XX.X.XM...
......XXXX.
In the above forest, Hermione is located at index (2, 7) and the exit is at (1, 2). Each cell is indexed according to Matrix Convention

She starts her commute back to the exit, and every time she encounters more than one option to move, she waves her wand and the correct path
 is illuminated and she proceeds in that way. It is guaranteed that there is only one path to each reachable cell from the starting cell.
  Can you tell us if she waved her wand exactly K times or not? Ron will be impressed if she is able to do so.

Input Format 
The first line contains an integer T; T test cases follow. 
Each test case starts with two space-separated integers, N and M. 
The next N lines contain a string, each having a length of M, which represents the forest. 
The last line of each single test case contains integer K.

Output Format 
For each test case, if she could impress Ron then print Impressed, otherwise print Oops!.

Constraints 
1≤T≤10 
1≤N,M≤100 
0≤K≤10000 
There is exactly one 'M' and one '*' in the graph. 
Exactly one path exists between 'M' and '*.'    

Explanation: 
This is a good exercise for the graph theory, as the problem statement states we are dealing with a tree. This can be realized out of the
 sentence “It is guaranteed that there is only one path to each reachable cell from the starting cell.” So simply you have to count branches 
 on the path from “M” to “*” and check if it is equal to K. This can be done by DFS or BFS in linear time. 
Counting the branches is the tricky part. One way is to:
As we traverse through the maze, on path from "M" to "*", lets count number of “.” which leaves current node with more depth and then
 if that number is more than or equal to 2 then we are at a branch and increase answer by one.          

//The key here is to find the ONLY path from M to *, then trace it back, and count the point where Hermione has multiple choices.  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long int
using namespace std;
char grid[101][101];
int n,m,wands;
bool inside(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='X');
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool dfs(int x,int y,int px=-1,int py=-1){
    if(grid[x][y]=='*') return 1;
    int f=0 , c=0;
    for(int i=0;i<4;i++){
        int k=x+dx[i];
        int l=y+dy[i];
        if(!inside(k,l)) continue;
        if(k==px && l==py) continue;
        if(dfs(k,l,x,y)) f=1;
        c++;
    }
    if(f && c>1) wands++;   // if there is a path from M to * ,and if she encounters more than one option to move to ,then increment  
    return f;                //  the no of wand moves by one .
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int t;cin>>t;
    while(t--){
    cin>>n>>m; 
    int mx,my;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
           cin>>grid[i][j];
            if(grid[i][j]=='M'){
                mx=i; my=j;
            }
    }
    int k;
    cin>>k;
    wands=0;
        dfs(mx,my);
        if(wands==k) cout<<"Impressed\n";
        else cout<<"Oops!\n";
       
    }
    return 0;
}
