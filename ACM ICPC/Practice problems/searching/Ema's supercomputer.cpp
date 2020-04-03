/*Given a grid of size N×MN×M, each cell in the grid is either goodgood or badbad.

A valid plus is defined here as the crossing of two segments (horizontal and vertical) of equal lengths. These lengths must be odd, and the middle cell of its horizontal segment must cross the middle cell of its vertical segment.

In the diagram below, the blue pluses are valid and the orange ones are not valid. pluseses.png

Find the 22 valid pluses that can be drawn on goodgood cells in the grid, and print maximum the product of their areas.

Note: The two pluses cannot overlap, and the product of their areas should be maximum.

Input Format

The first line contains two space-separated integers, NN and MM.
The NN subsequent lines contains MM characters, where each character is either G (goodgood) or B (badbad). If the ythyth character in the xthxth line is G, then (x,y)(x,y) is a goodgood cell (otherwise it's a badbad cell).

Constraints
2≤N≤152≤N≤15
2≤M≤152≤M≤15

Output Format

Find 22 pluses that can be drawn on goodgood cells of the grid, and print maximum the product of their areas as an integer.

Sample Input 1

5 6
GGGGGG
GBBBGB
GGGGGG
GGBBGB
GGGGGG
Sample Output 1

5
Sample Input 2

6 6
BGBBGB
GGGGGG
BGBBGB
GGGGGG
BGBBGB
BGBBGB
Sample Output 2

25  */

#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,ans;
char c[N][N];

int main() {

    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    cin>>c[i][j];

    for (int x=1;x<=n;x++)
    for (int y=1;y<=m;y++){
        int r=0;
        while ( c[x+r][y]=='G' && c[x-r][y]=='G' && 
                c[x][y+r]=='G' && c[x][y-r]=='G'){
            c[x+r][y]=c[x-r][y]=c[x][y+r]=c[x][y-r]='g';
                for (int X=1;X<=n;X++)
                for (int Y=1;Y<=m;Y++){
                    int R=0;
                    while ( c[X+R][Y]=='G' && c[X-R][Y]=='G' && 
                            c[X][Y+R]=='G' && c[X][Y-R]=='G')
                        ans=max(ans,(1+4*r)*(1+4*R)),
                        R++;
                    }
            r++;
        }
        r=0;
        while ( c[x+r][y]=='g' && c[x-r][y]=='g' && 
                c[x][y+r]=='g' && c[x][y-r]=='g')
            c[x+r][y]=c[x-r][y]=c[x][y+r]=c[x][y-r]='G',
            r++;
    }
    cout<<ans<<endl;
    return 0;
}