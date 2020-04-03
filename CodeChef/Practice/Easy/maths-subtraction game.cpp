/*All submissions for this problem are available.

Chef is playing a game on a sequence of N positive integers, say A1, A2, ... AN. The game is played as follows.
If all the numbers are equal, the game ends.
Otherwise
Select two numbers which are unequal
Subtract the smaller number from the larger number
Replace the larger number with the result from above (see the explanation section for clarity)
Chef has already figured out that the game always terminates. He also knows, for a given sequence of integers, the game will always terminate 
on the same value, no matter how the game is played. Chef wants you to simulate the game for him and tell him on which value will the game 
terminate for a given sequence of integers.
Input

The first line of the input contains an integer T, the number of test cases. Then follow the description of T test cases. 
The first line of each test case contains a single integer N, the length of the sequence. The second line contains N positive integers, e
ach separated by a single space.
Output

For each test case, output a single integer - the value of all the numbers when they are equal (and the game terminates), on a line by itself.
Constraints

1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 109
Sample

Input
3
2
10 12
2
5 9
3
6 10 15

Output
2
1
1*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int g , ans=0;
		for(int i=0;i<n;++i){
			scanf("%d",&g);
			ans = __gcd(ans,g);
		}
		printf("%d\n",ans);
	}
}