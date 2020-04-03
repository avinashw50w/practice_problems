/*Chef and his girlfriend are going to have a promenade. They are walking along the straight road which consists of segments placed one by one. Before walking Chef and his girlfriend 
stay at the beginning of the first segment, they want to achieve the end of the last segment.

There are few problems:

At the beginning Chef should choose constant integer - the velocity of mooving. It can't be changed inside one segment.
The velocity should be decreased by at least 1 after achieving the end of some segment.
There is exactly one shop on each segment. Each shop has an attractiveness. If it's attractiveness is W and Chef and his girlfriend move with velocity V then if V < W girlfriend 
will run away into the shop and the promenade will become ruined.
Chef doesn't want to lose her girl in such a way, but he is an old one, so you should find the minimal possible velocity at the first segment to satisfy all conditions.

 

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of segments. The second line contains N space-separated integers W1, W2, ..., WN denoting the 
attractiveness of shops.
 

Output

For each test case, output a single line containing the minimal possible velocity at the beginning.*/
int n, w;
int main() {
	int t=inp();
	while(t--){
		n=inp();
		int ans=0;
		rep(i,0,n) {
			w=inp();
			ans=max(ans, w+i);
		}

		printf("%d\n", ans);
	}
	return 0;
}
