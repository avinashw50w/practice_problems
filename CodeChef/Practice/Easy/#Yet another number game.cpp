/* Alice and Bob play the following game. They choose a number N to play with. The rules are as follows :
1) Alice plays first, and the two players alternate.
2) In his/her turn, a player can subtract from N any proper divisor (not equal to N) of N. The number thus obtained is the new N.
3) The person who cannot make a move in his/her turn loses the game.
Assuming both play optimally, who wins the game ?
Input :
The first line contains the number of test cases T. Each of the next T lines contains an integer N.
Output :
Output T lines, one for each test case, containing "ALICE" if Alice wins the game, or "BOB" otherwise.
Sample Input :
2
1
2

Sample Output :
BOB
ALICE

Constraints :
1 <= T <= 10000
1 <= N <= 1000000000 */

#include <stdio.h>
 
int main()
{
  int t;
  long long n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%ld",&n);
    if((n&1)==0)  // if n is even
    {
      printf("ALICE\n");
    }
    else
    {
      printf("BOB\n");
    }
  }
  return 0;
} 

/* EXPLANATION:
Let us look at small examples first and then try and figure out how to solve the problem.This following table represents Whether you will win or lose if 
you are on the given number and it is your chance to play.

1)Lose

2)Win

3)Lose

4)Win

5)Lose

6)Win

7)Lose

8)Win

It seems that if N is an Even number then Alice wins otherwise Bob wins.This is indeed True.

Strategy to be followed :- If you are on an Even number,subtract 1 from the number.The opponent will then have an Odd number.
All factors of odd numbers are Odd.Hence he can only subtract an Odd number.Hence you will have an even number on your turn.Keep following the same strategy.
What will remain "Invariant" is that you will always have an even number and the opponent will have an odd number.This process will keep continuing until 
you reach one the numbers between 1 and 8,for which the results are listed above.*/
