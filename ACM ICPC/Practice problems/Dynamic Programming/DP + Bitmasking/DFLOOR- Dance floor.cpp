/*You recently watched a video clip in which a singer danced on a grid of colourful tiles enlightened from below. Each step on a tile flipped 
the tile's state, i.e. light on or off. In addition to that, all the neighbouring tiles flipped their states, too. 

In this task, you are supposed to come up with a short program that decides if it is possible for the singer to switch on the lights of all 
the tiles, provided that he dances on the appropriate tiles. 

The dance floor has rectangular shape. At the beginning, some of the tiles are already alight. Your program may temporarily switch off some 
tiles, if it deems that necessary to reach its goal. Stepping on a tile toggles its own state as well as the states of the four neighbouring 
tiles directly above, below, to the left and to the right. Of course, in the case of a peripheral tile, there will be only three or two 
neighbouring tiles. 

Here comes an example: 
 
If the dancer steps on the tile indicated by the brown shoe, all the tiles within the white area change their states. The resulting dance 
floor is depicted on the right. 

You may assume that the singer is fit enough to jump from any tile to any other tile, even if the destination tile lies on the opposite side 
of the dance floor.

Input

There are several test cases. The first line of each case contains two integer numbers x and y, indicating the width and the height of the 
dance floor grid. The numbers are separated by a single space and satisfy 3 ≤ x,y ≤ 15. 

The following y lines containing xcharacters each describe the initial on/off states of the tiles. A zero means "the tile is switched off", 
a one digit means "the tile is alight". 

Input ends with 0 0.

Output

For each test case your program should output the number of steps needed to switch all the lights on, followed by exactly that many lines 
with two space-separated numbers i and j. Each individual line commands the singer to step on the i-th tile of the j-th row. Starting with 
the situation of the input file and executing all the commands in the output file, all the tiles must be switched on. 

If more than one solution exist, your program should output an arbitrary one of them. If, on the other hand, no solution exists, your program 
should write the number "-1".

Example

Sample input


4 3
0111
1010
1000

0 0

Sample output


3
1 2
1 3
4 3*/

int main() {
	int R, C, steps, prev, curr, state, move[15], moveAns[15];
	string G[15];
	while(scanf("%d%d", &C, &R) and C and R) {
		
		rep(i,0,R) cin >> G[i];

		int ans = -1;
		int S = (1<<C) - 1;

		for(int mask = S; mask >= 0; --mask) {
			steps = __builtin_popcount(mask);
			prev = mask;
			move[0] = mask;
			
			state = (mask ^ (mask>>1) ^ (mask<<1)) & S;
			
			rep(i,0,C) if(G[0][i] == '0') state ^= (1<<i);
		
			rep(r,1,R) {
				move[r] = curr = state;
				steps = steps + __builtin_popcount(curr);
				
				state = (state ^ (state>>1) ^ (state<<1) ^ prev) & S;

				rep(i,0,C) if(G[r][i] == '0') state ^= (1<<i);

				prev = curr;
			}
			if(state == 0 and (ans == -1 or ans > steps)) {
				ans = steps;
				rep(i,0,R) moveAns[i] = move[i];
			}
		}

		if(ans == -1) printf("-1\n");

		else {
			printf("%d\n", ans);
			rep(i,0,R)
				rep(j,0,C)
					if(moveAns[i] & (1<<j))
						printf("%d %d\n",j+1, i+1);
		}

	}
	return 0;
}
