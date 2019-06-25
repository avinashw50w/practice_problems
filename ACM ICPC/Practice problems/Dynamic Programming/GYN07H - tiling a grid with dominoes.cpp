/*We wish to tile a grid 4 units high and N units long with rectangles (dominoes) 2 units by one unit (in either orientation). For example, 
the figure shows the five different ways that a grid 4 units high and 2 units wide may be tiled.

Write a program that takes as input the width, W, of the grid and outputs the number of different ways to tile a 4-by-W grid.

Input

The first line of input contains a single integer N, (1 ≤ N ≤ 1000) which is the number of datasets that follow.

Each dataset contains a single decimal integer, the width, W, of the grid for this problem instance.

Output

For each problem instance, there is one line of output: The problem instance number as a decimal integer (start counting at one), a single 
space and the number of tilings of a 4-by-W grid. The values of W will be chosen so the count will fit in a 32-bit integer.*/

/*Here T[n] denotes the no of ways to tile a 4 x n grid 
  g[n] is the configuration when a vertical tile is put at the middle 
  h[n] is the configuration when a vertical tile is a position other than the middle

  for more details go to : http://stackoverflow.com/questions/16388579/spoj-m3tile-solution-explanation  */

int T[1010], h[1010], g[1010];

void prec() {
	T[0] = 1;
	h[0] = g[0] = 0;
	T[1] = h[1] = g[1] = 1;
	rep(i,2,1010) {
		T[i] = T[i-1] + T[i-2] + g[i-1] + 2*h[i-1];
		g[i] = T[i-1] + g[i-2];
		h[i] = T[i-1] + h[i-1];
	}
}

int main() {

	prec();

	caset{
		int w;
		si(w);
		printf("%d %d\n", case_n++, T[w]);
	}
	return 0;
}


////////////////////////////////////////////////////////////////////

int main(){
    unsigned int dp[1001];
    dp[0] = dp[1] = 1; dp[2] = 5; dp[3] = 11;
    
    for(int i = 4;i <= 1000;++i)
        dp[i] = dp[i-1]+5*dp[i-2]+dp[i-3]-dp[i-4];
    
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        printf("%d %u\n",tc,dp[n]);
    }
    
    return 0;
}