/* Chef and his best friend Aleksa are into mathematical games these days. Today, they have some ( = 0 ) black cells represented as B, and a white cell represented as W,
 lying randomly in a straight line.
They have decided to play with these cells. In a move, a player chooses some ( > 0 ) black cells lying on any one side of the white cell and remove them. It should be 
noted that a player is not allowed to choose black cells from both side of the given white cell. Both the players alternate their moves, and play optimally. 
The player who is unable to move in his respective turn will lose the game.
Aleksa, being a girl, has a habit of playing first. But Chef is fairly smart himself, and will not play the game if he is going to lose it. 
Therefore, he wants to know the winner beforehand. Can you tell him who is going to win the game for the given configuration of cells?
Input

First line of input contains a single integer T denoting the number of test cases. First and the only line of each test case contains a string S 
consisting of the characters 'B' and 'W', denoting black and white cells, respectively.
Output

For each test case, output "Chef" if chef wins the game for the given configuration. Else print "Aleksa". (quotes for clarity only).
Constraints

1 = T = 10

1 = |S| = 10000

S contains exactly 1 white cell.
Scoring

Subtask 1: 1 = T = 10, 1 = |S| = 10 : ( 30 pts )

Subtask 2: 1 = T = 10, 1 = |S| = 100 : ( 30 pts )

Subtask 3: 1 = T = 10, 1 = |S| = 10000 : ( 40 pts )
Example

Input
3
W
BW
BWBB

Output
Chef
Aleksa
Aleksa
Explanation

Test 1 : Aleksa cannot make a move in her first turn as there is no black cell in the given configuration.
Test 2 : Aleksa can remove 1 black cell lying on the left of white cell in her turn. But then, Chef cannot make a move in his turn as there will be no black cells left.
Test 3 : Figure out yourself. 

Solution:
DIFFICULTY:
Easy

PREREQUISITES:
Game Theory

PROBLEM:
Given a string of length N which contains exactly one 'W' character and rest of the characters as 'B'. The only operation allowed per turn is to remove non-empty set of 'B' characters from either side of 'W' character. Both the players play optimally. The one who is not able to move in his turn ends up loosing. Predict the winner of the game.

EXPLANATION
The two groups of black characters can be understood as two piles of coins such that each player in his turn can take any number of non-empty coins from either of the pile. So, the one who is not able to move in his respective turn looses the game.

Solution for Subtask 1 & 2:

Constraints for these subtasks allow us to use a simple DP.

Approach

Let us say that the count of coins in both the piles be x and y respectively. We can now apply DP to decide the winner by taking into account every possibility at each stage. At any particular instant, current player can take any number of coins from either of the piles. Hence, he will choose the move in which the next player will be at a loosing position from whatever he tries. This move will be winning move for the current player. If he does not find any move for which the next player can be at a loosing position, that means it is a loosing position for the current player. The pseudo code below will help you to explain the recurrence better.

Pseudo Code

bool F(x,y) {
     bool ans = false;
     for ( int i = 1; i &le; x; i++ ) ans |= (!F(x-i,y));
     for ( int i = 1; i &le; y; i++ ) ans |= (!F(x,y-i)); 
     return ans;
}
These states can then be memoized to give an overall complexity of O(N3).

Solution for Subtask 3:

Simple Observation

One simple observation is that if two piles have the same number of coins, it will always be a loosing position for the current player. That being said, any of the player would like to balance the two piles after his turn so that the next player who takes the turn ends up in the loosing position. There exists no other loosing position except both the piles having same number of coins.

Hence, it suffices to check the following condition for predicting the winner of the game.

return (s.length()%2 != 0 && s.find("W") == s.length()/2 ) ? "Chef" : "Aleksa"
Nim Game Approach

The problem can also be modelled into standardised Nim game problem.

There is a well know formula to detect the winning player if both the players play optimally in the mentioned pile game. If Xor of number of coins in all the piles is zero, that means it is a loosing position for the first player. Otherwise, it will always be a winning position. In our case, XOR will be the bitwise XOR of number of characters before and after the single 'W' character in the string. Read this content to know more about the proof of this formula.

For details on the implementation, please look at the below mentioned solutions

COMPLEXITY
Overall complexity for the solution to pass all the subtasks is O(N). */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <cstring>
#include <cassert>
#define rf freopen("in.in", "r", stdin)
#define wf freopen("out.out", "w", stdout)
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e5+10, mod = 1e9+7;

char input[111];
int test_cases;

int main()
{
	//rf;// wf;
	
	scanf("%d", &test_cases);
	while(test_cases--)
	{
		scanf("%s", input);
		int cnt1=0, cnt2=0;
		int n = strlen(input);

		for(; input[cnt1]!='W' && cnt1 < n; ++cnt1);
		assert(cnt1 < n);

		for(cnt2 = cnt1+1; input[cnt2]!='W' && cnt2 < n; ++cnt2);
		assert(cnt2 == n);
		cnt2 -= cnt1+1;

		if(cnt1^cnt2)
			cout << "Aleksa\n";
		else cout << "Chef\n";

	}
	return 0;
}


