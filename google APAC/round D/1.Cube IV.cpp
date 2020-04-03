/*Vincenzo decides to make cube IV but only has the budget to make a square maze. Its a perfect maze, every room is in the form of a square 
and there are 4 doors (1 on each side of the room). There is a big number written in the room. A person can only move from one room to another 
if the number in the next room is larger than the number in his current room by 1. Now, Vincenzo assigns unique numbers to
 all the rooms (1, 2, 3, .... S2) and then places S2 people in the maze, 1 in each room where S is the side length of the maze. 
 The person who can move maximum number of times will win. Figure out who will emerge as the winner and the number of rooms he will be able
  to move.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of S which is the side length 
of the square maze. Then S2 numbers follow like a maze to give the numbers that have been assigned to the rooms.

1 2 9 
5 3 8 
4 6 7 
Output

For each test case, output one line containing "Case #x: r d", where x is the test case number (starting from 1), r is the room number
 of the person who will win and d is the number of rooms he could move. In case there are multiple such people, the person who is in the
  smallest room will win.

Limits

1 = T = 100.
Small dataset

1 = S = 10
Large dataset

1 = S = 103.
Sample


Input 
 	
Output 
 
2
2
3 4
1 2 


3
1 2 9 
5 3 8 
4 6 7 
*/
#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[1010][1010];
int dp[1010101];
int main(){
    CASET{
        DRI(n);
        MS0(d);
        REPP(i,1,n+1)REPP(j,1,n+1){
            RI(d[i][j]);
        }

        REPP(i,1,n+1)REPP(j,1,n+1){
            dp[d[i][j]]=0;
            REP(k,4){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(d[nx][ny]==d[i][j]+1)dp[d[i][j]]=1;
            }
        }
        int an1,an2=-1;
        dp[n*n+1]=0;
        for(int i=n*n;i>0;i--){
            if(!dp[i]){
                dp[i]=1;
                if(an2<=1){
                    an2=1;
                    an1=i;
                }
            }
            else{
                dp[i]=dp[i+1]+1;
                if(dp[i]>=an2){
                    an2=dp[i];
                    an1=i;
                }
            }
        }
        printf("Case #%d: %d %d\n",case_n++,an1,an2);
    }
    return 0;
}
