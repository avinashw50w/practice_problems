/*The marketing and public-relations department of the Czech Technical University has designed a new reconfigurable mechanical Flip-Flop 
Bill-Board (FFBB). The billboard is a regular two- dimensional grid of R × C square tiles made of plastic. Each plastic tile is white on one 
side and black on the other. The idea of the billboard is that you can create various pictures by flipping individual tiles over. Such 
billboards will hang above all entrances to the university and will be used to display simple pictures and advertise upcoming academic events. 
To change pictures, each billboard is equipped with a "reconfiguration device". The device is just an ordinary long wooden stick that is used 
to tap the tiles. If you tap a tile, it flips over to the other side, i.e., it changes from white to black or vice versa. Do you agree this 
idea is very clever?

Unfortunately, the billboard makers did not realize one thing. The tiles are very close to each other and their sides touch. Whenever a tile 
is tapped, it takes all neighboring tiles with it and all of them flip over together. Therefore, if you want to change the color of a tile, 
all neighboring tiles change their color too. Neighboring tiles are those that touch each other with the whole side. All inner tiles have 4 
neighbors, which means 5 tiles are flipped over when tapped. Border tiles have less neighbors, of course.

example
For example, if you have the billboard configuration shown in the left picture above and tap the tile marked with the cross, you will get the 
picture on the right. As you can see, the billboard reconfiguration is not so easy under these conditions. Your task is to find the fastest way 
to "clear" the billboard, i.e., to flip all tiles to their white side.

Input

The input consists of several billboard descriptions. Each description begins with a line containing two integer numbers R and C (1 <= R,C <= 16)
specifying the billboard size. Then there are R lines, each containing C characters. The characters can be either an uppercase letter "X" 
(black) or a dot "." (white). There is one empty line after each map. The input is terminated by two zeros in place of the board size.

Output

For each billboard, print one line containing the sentence "You have to tap T tiles.", where T is the minimal possible number of taps needed 
to make all squares white. If the situation cannot be solved, output the string "Damaged billboard."instead.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, C;
	int prev, curr, state, flips;
	string G[20];

	while(scanf("%d%d", &R, &C) and R and C) {
		for(int i=0; i<R; ++i) 
			cin >> G[i];

		int ans = -1;
		int S = (1<<C) - 1;

		// for each pattern on the first row
		for(int mask=S; mask>=0; --mask) {
			flips = __builtin_popcount(mask);
			prev = mask;
			state = (mask ^ (mask<<1) ^ (mask>>1)) & S;

			for(int i=0; i<C; ++i) {
				if(G[0][i] == 'X')
					state ^= (1<<i);
			}
			// change the pattern on other rows based on result of the first row
			for(int i=1; i<R; ++i) {
				flips = flips + __builtin_popcount(state);
				curr = state;
				state = (state ^ (state<<1) ^ (state>>1) ^ prev) & S;
				prev = curr;

				for(int j=0; j<C; ++j) {
					if(G[i][j] == 'X')
						state ^= (1<<j);
				}
			}
			if(state == 0) {
				if(ans == -1 or ans > flips) ans = flips;
			}
		}
		if(ans == -1) printf("Damaged billboard.\n");
		else printf("You have to tap %d tiles.\n", ans);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////

int x,y;
bool    MAP[20][20];
int solve(vector<int>steps)
{
    bool temp[x+1][y+1];
    memset(temp,0,sizeof temp);
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            temp[i][j]=MAP[i][j];
    int ans=0;
    for(int i=0; i<steps.size(); i++)
    {
        int t=steps[i];
        temp[0][t]=!temp[0][t];
        ans++;
        if(t+1<y)temp[0][t+1]=!temp[0][t+1];
        if(t>=1)temp[0][t-1]=!temp[0][t-1];
        if(1<x)temp[1][t]=!temp[1][t];
    }
    for(int i=1; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(temp[i-1][j]==1)
            {
                temp[i][j]=!temp[i][j],ans++;
                if(i-1>=0)
                    temp[i-1][j]=!temp[i-1][j];
 
                if(i+1<x)
                    temp[i+1][j]=!temp[i+1][j];
 
                if(j+1<y)
                    temp[i][j+1]=!temp[i][j+1];
 
                if(j-1>=0) temp[i][j-1]=!temp[i][j-1];
 				
 				ans++;
            }
        }
    }
 
    bool W=0;
    for(int i=0; i<x && !W; i++)
        for(int j=0; j<y; j++)
        {
            if(temp[i][j]==1)
            {
                W=1;
                break;
            }
        }
 
    if(W)
        return INT_MAX;
 
 
    else
        return ans;
 
}
int main()
{
 
 
    char C;
    while(scanf("%d %d",&x,&y)!=EOF)
    {
        if(x==0 && y==0)
            break;
        memset(MAP,0,sizeof MAP);
 
        for(int i=0; i<x; i++)
            for(int j=0; j<y; j++)
            {
 
                cin>>C;
                if(C=='X')
                    MAP[i][j]=true;
                else
                    MAP[i][j]=false ;
 
 
            }
 
        int ans=INT_MAX;
        for(int i=0; i<(1<<y); i++)
        {
            vector<int >steps;
            for(int j=0; j<y; j++)
                if(i &(1<<j))
                    steps.push_back(j);
 
            ans=min(solve(steps),ans);
 
        }
        if(ans<INT_MAX)
            printf("You have to tap %d tiles.\n",ans);
 
        else
            printf("Damaged billboard.\n");
 
 
    }
    
   return 0;
}

/////////////////////////////////////////////////////////////////////

const int N = 17;
char x[N][N];
int ar[N];
int temp[N];
 
 
int main()
{
      int n,m;
       
      while(scanf("%d%d",&n,&m)==2 ){
            if(n+m==0) return 0;
            forn(i,n) scanf("%s",x[i]);
            forn(i,n){
                  int o = 0;
                  forn(j,m) if(x[i][j]=='X') o |= (1<<j);
                  ar[i] = o;
            }
            int iM = 1e8;
            bool flag = 0;
            forn(i,1<< m ) {
                  forn(k,n) temp[k]= ar[k];
                  int cnt = 0;
                  forn(j,m) {
                        if(i & (1<<j)){
                              temp[0] ^= (1<<j);
                              if(j+1<m) temp[0] ^= (1<<(j+1));
                              if(j-1>=0) temp[0] ^= (1<<(j-1));
                              temp[1] ^= (1<<j);
                              cnt ++;
                        }
                  }
                  for(int i = 1; i< n; i ++ ){
                        for(int j = 0; j< m ;j ++ ) {
                              if(temp[i-1] & 1<<j ) {
                                    temp[i] ^= (1<<j);
                                    if(j+1<m) temp[i] ^= (1<<(j+1));
                                    if(j-1>=0) temp[i] ^= (1<<(j-1));
                                    temp[i+1] ^= (1<<j);
                                    cnt ++;
                              }
                        }
                  }
                  if(temp[n-1] == 0 ) {
                        iM = min(iM, cnt );
                        flag = 1;
                  }
            }
            if(flag) printf("You have to tap %d tiles.\n",iM);
            else printf("Damaged billboard.\n");
             
      }
       
      return 0;
}