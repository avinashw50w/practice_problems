/*In a rectangular field of size n by m squares there is a mouse and two cats. The mouse is the first to make a move, then each of the cats makes a move, 
then again its the mouse's turn, and so on. In each move both the mouse and the cats can move exactly one square vertically or horizontally.
 If the mouse is standing at the edge of the field then in its next move it can jump off the field and is saved from the cats. If in the next move one of the 
 cats moves to the field with the mouse then there is no escape for the mouse ... =(

You are to write a program which, knowing the initial positions of mouse and the two cats, will find out if there is any way for the mouse to escape from the cats, 
assuming of course that each cat will do its best to catch the mouse.
Input

In the first line of input two integers n and m are given, not exceeding 100, where n is the number of rows, and m - the number of columns. 
The second line contains a number k [k <= 10], which defines the number of test cases for the given field. In the next k lines the initial positions of the mouse 
and the cats are given. The position in the field is given by two numbers: the first is the number of the row, the second is the number of the column. 
The first two integers are the coordinates of the mouse, the next four integers are the coordinates of the cats.

Output

You must output k lines with answers for each test case. The answer is YES, if the mouse can escape or NO otherwise.

Example

Input:
5 3
3
2 2 1 1 3 3
2 3 1 3 5 2
3 2 1 2 4 3

Output:
NO
YES
YES
*/

int main()
{
    int  mx,my,ax,ay,bx,by,mt,ct,ml,mr,cr,cl,mb,cb;
    int t,r,c;
    scanf("%d",&r);
    scanf("%d",&c);
    scanf("%d",&t);
    
    while(t--)
    {
        cin>>mx>>my>>ax>>ay>>bx>>by;
        if((mx>=ax&&mx>=bx)||(mx<=ax&&mx<=bx)||(my>=ay&&my>=by)||(my<=ay&&my<=by))
             printf("YES\n");
        else
        {
            mt=abs(1-mx);
            ct=min(abs(1-ax)+abs(ay-my),abs(1-bx)+abs(by-my));
            mb=abs(r-mx);
            cb=min(abs(r-ax)+abs(ay-my),abs(r-bx)+abs(by-my));

            mr=abs(1-my);
            cr=min(abs(1-ay)+abs(ax-mx),abs(1-by)+abs(bx-mx));
            ml=abs(c-my);
            cl=min(abs(c-ay)+abs(ax-mx),abs(c-by)+abs(bx-mx));
            if(mt<ct||mb<cb||mr<cr||ml<cl)
                 printf("YES\n");
            else
                 printf("NO\n");
        }
    }
    return 0;
}

//  using bfs
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int mdist[ 100 ][ 100 ];
int cdist[ 100 ][ 100 ];
int n, m;

struct cord {
	int x;
	int y;
};

void cbfs( cord cat ) {
	bool visited[ n ][ m ];
	int i, j;
	memset(visited,false,sizeof visited);
	cat.x -= 1;
	cat.y -= 1;
	queue< cord > q;
	q.push( cat );
	cdist[ cat.x ][ cat.y ] = 0;
	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		if ( !visited[ p.x ][ p.y ] ) {
			visited[ p.x ][ p. y ] = true;
			for(int i=0; i<4; ++i){
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if(!valid(nx,ny)) continue;
				if(cdist[nx][ny] > cdist[p.x][p.y] + 1){
					cdist[nx][ny] = cdist[p.x][p.y] + 1;
					q.push( ( cord ) { nx,ny } );
				}
			}
		}
	}
}

void mbfs( cord mouse ) {
	bool visited[ n ][ m ];
	int i, j;
	memset(visited,false,sizeof visited);

	queue< cord > q;
	mouse.x -= 1;
	mouse.y -= 1;
	q.push( mouse );
	mdist[ mouse.x ][ mouse.y ] = 0;
	while ( !q.empty() ) {
		cord p = q.front();
		q.pop();
		if ( !visited[ p.x ][ p.y ] ) {
			visited[ p.x ][ p. y ] = true;
			for(int i=0; i<4; ++i){
				int nx = p.x + dx[i];
				int ny = p.y + dy[i];
				if(!valid(nx,ny)) continue;
				if(cdist[nx][ny] > cdist[p.x][p.y] + 1){
					cdist[nx][ny] = cdist[p.x][p.y] + 1;
					q.push( ( cord ) { nx,ny } );
				}
			}
		}
	}
}

int main() {
	scanf( "%d%d", &n, &m );
	int t;
	scanf( "%d", &t );
	int i, j;
	cord cat1, cat2, mouse;
	bool found;

	while ( t-- ) {
		found = false;
		for ( i = 0; i < n; ++i ) {
			for ( j = 0; j < m; ++j ) {
				mdist[ i ][ j ] = cdist[ i ][ j ] = 1000000;
			}
		}
		scanf( "%d%d%d%d%d%d", &mouse.x, &mouse.y, &cat1.x, &cat1.y, &cat2.x, &cat2.y );
		cbfs( cat1 );
		cbfs( cat2 );
		mbfs( mouse );
		if ( !found ) {
			for ( i = 0; i < n; ++i ) {
				if ( mdist[ i ][ 0 ] < cdist[ i ][ 0 ] || mdist[ i ][ m - 1 ] < cdist[ i ][ m - 1 ] ) {
					printf( "YES\n" );
					found = true;
					break;
				}
			}
		}
		if ( !found ) {
			for ( j = 0; j < m; ++j ) {
				if ( mdist[ 0 ][ j ] < cdist[ 0 ][ j ] || mdist[ n - 1 ][ j ] < cdist[ n - 1 ][ j ] ) {
					printf( "YES\n" );
					found = true;
					break;
				}
			}
		}
		if ( !found ) {
			printf( "NO\n" );
		}
	}

	return 0;
}
