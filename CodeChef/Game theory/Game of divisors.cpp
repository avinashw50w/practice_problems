/* Mike and his friend Tom are playing a very interesting game right now. Here is the description of the game:
Initially, there is a positive integer N written on the desk, which is strictly greater than 1;
Mike makes the first move, then players make moves alternatively;
On each move the current player can either decrease the number on the desk by 1, or divide it by one of it's divisors except itself and 1; It's forbidden to decrease the number if it's equal to 1;
If the current player can't make a move, then he loses. In other words, if there is "1" written on the desk right before his move, then he loses.
You are given a number N. You need to determine the winner of the game, if N is the number written of the desk initially. You may assume, that both players play optimally.
Input

There are multiple test cases in the input. The first line of the input contains one integer T, denoting the number of test cases in the input.
The next T lines contain one integer each, denoting the initial number of the game.
All the test cases are independent and must be considered separately!
 
Output

Your output should contain exactly T lines, each contains the name of the winner(Mike or Tom) of the corresponding game. You should output the verdicts of the games in the order they appear in the input.
 
Constraints

1 = T = 10 000;
2 = N = 108, for each test case appeared in the input.
 
Example

Input:
4 
5 
3 
2 
4

Output:
Tom
Tom
Mike
Mike 

Solution:
DIFFICULTY:
Easy-Medium

PREREQUISITES:
Game Theory, Sieve of Erasthosenes

PROBLEM:
Two players are playing a game where they start with an integer N. At each move a player can decrease the integer by 1 or divide it by one of it's divisor 
except itself and 1. The players have turns to give one move alternately. The player who cannot make any move ( the integer becomes 1) loses the game. 
Determine who would win the game if they start with N.

EXPLANATION:
If you are not familiar with "Game theory" problems, read this tutorial before.

The terminal position ( here it is N=1) is a losing position. A position is winning if it is possible to move to a losing position in one move. 
And a player is in a losing position if he can move to winning positions only.

The simplest way to solve this problem would be to notice the pattern by analyzing all the winning/losing positions between 2 and M 
(where M is a reasonable value say 10000) with a straightforward DP solution. The pattern is that all prime numbers except 2 and 17 are losing positions.
 All composite numbers except 16, 34 and 289 are winning positions. So the solution is just to check whether the number is a prime or a composite number.

Proof:

Here are the positions for N up to 15.

 N          = 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 
 position[] = L  W  L  W  L  W  L  W  W  W  L  W  L  W  W
When N = 2n where n >= 1:
N = 2, 4 and 8 are winning because 1,3 and 7 are losing positions. But 16 is not winning since {2,4,8,15} are not losing positions. 
But for all other powers of 2 greater than 16, the player can make a move to 16 and thus winning, so all the other powers of 2 are winning.

When N = 17k where k >= 1: 
N = 17 is winning since 16 is losing position. N = 172 = 289 is losing since {17, 288} are winning positions. For all other greater powers of 17, 
the player can make a move to losing position 289 and thus winning the game, so all other powers of 17 are winning.

When N = 2n *17k where n >= 1 and k >= 1: 
The smallest such N = 34 is losing, since {2, 17, 33} are all winning positions. But for any other multiples of 34, 
the player can make a move to losing position 34 and thus winning, so any other multiple of 34 would be winning.

When N = Number having at least one prime divisor which is not 2 or 17: 
It can be proven that all such prime numbers are losing positions and all such composite numbers are winning. Consider an algorithm similar to Sieve of Erasthoneses:

Find the smallest number N which is not determined yet whether winning or losing
Determine the state of that position
If it is losing then mark all it's multiples as winning positions.Because then all multiples of N would have a losing divisor N, so those would be winning.
Let's start with the first number 3 which is losing position (since 2 is winning), so all the multiples of 3 would be winning. 
The next undetermined number would be the next prime number 5 and that would be losing too and all it's multiples would be winning. 
The next undetermined position would always be a prime number( without considering 17) P and that would be losing since the composite number P-1 would be 
marked losing by one of it's losing prime divisor. All composite numbers having prime factor other than 2 or 17, would always be winning 
since it would be marked winning by one of it's losing prime divisor.*/

// DIVGAME
// Game of Divisors
// Author: Constantine Sokol
// Complexity : O( T * sqrt( N ) )
// Expected Verdict: AC
 
#include <iostream>
#include <cstdio>
 
#define mp make_pair
#define pb push_back
 
using namespace std;
 
bool fun( int n )
{
	if ( n == 2 ) return true;
	if ( n == 16 ) return false;
	if ( n == 17 ) return true;
	if ( n == 34 ) return false;
	if ( n == 289 ) return false;
	for ( int i = 2; i * i <= n; i++ )
		if ( n % i == 0 )
			return true;
	return false;
}
 
int main (int argc, const char * argv[])
{
	int test; scanf("%d", &test);
	while ( test-- )
	{
		int n;
		scanf("%d", &n);
		if ( fun( n ) ) puts("Mike"); else puts("Tom");
	}
    return 0;
} 


