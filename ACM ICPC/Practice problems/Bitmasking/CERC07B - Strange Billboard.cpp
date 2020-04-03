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