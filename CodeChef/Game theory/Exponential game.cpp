/* Little Chef is trying to learn exponents. He is especially interested in a number raised to the power of itself. Head Chef being his mentor has decided to give him a two player game to play. The game is as follows: You are given n piles of stones. The piles have a_1, a_2 .. a_n number of stones . Each player on his/her turn can remove x number of stones where x = n^n (for some natural number n > 0) from any one pile. The player who is unable to move loses. Head Chef is playing this game with the Little Chef and being senior he gives the first move to the Little Chef .
Input

Input Description.
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows:
The first line of each test case contains a single integer N denoting the number of piles. The second line contains N space-separated integers A1, A2, ..., AN denoting the number of stones in each pile.
Output

Output description.
For each test case, output a single line containing the string "Head Chef" if Head Chef will win the game or the string "Little Chef" is Little Chef 
will win the game (assuming optimal play by both players).
Constraints

1 = T = 100
1 = N = 100
1 = a_i = 100000
Example

Input:
1
1
4

Output:
Little Chef
Explanation

Example case 1. Little Chef can remove all the four stones and Head Chef will lose.
Scoring

Subtask 1 (16 points): N = 1 

Subtask 2 (24 points): N = 2 

Subtask 3 (60 points): See constraints 

Solution:
DIFFICULTY :
Easy-Medium
PREREQUISITES :
Basic Game Theory , Zero-sum game , Impartial game , Sprague Grundy Theorem .
PROBLEM :
Given n piles of stones . In each turn you can remove a^a stones for some natural number a from one of the piles . Given two players who alternately play their moves , the loser is the one who is unable to make a move. Given an initial configuration you have to predict the winner under the assumption of optimal play .

EXPLANATION:
Basic game theory Concept :
In case there is no pile of stones at all the first player loses . In case there are only a few piles , the problem can be solved iteratively . The base state is when there are 0 stones in all the piles , when the first player loses . For all other states , the state is win for first player if a state which is win for the second player is reachable from it in one move otherwise it is a losing position .

Example : Suppose we have only 1 pile with N stones .

N = 0 : Second win ( base case )

N = 1 : N = 0 is reachable which is second win , hence this position is first win .

N = 2 : N = 1 is reachable , which is first win , hence this position is second win .

N = 3 : N = 2 is reachable , which is second win , hence this position is first win .

N = 4 : N = 3 and N = 0 are reachable , N = 0 is second win , hence this position is first win . ( Note only one of the positions reachable being second win is sufficient for the position to be first win ) .

N = 5 : N = 4 and N = 1 are reachable , N = 1 is first win and N = 4 is first win, hence this position is second win . ( Note when all reachable positions are first win , then the position is second win )

Sprague Grundy Theorem :
We associate with each position of the game a number called the Grundy number of the position . The Grundy number of a losing position is 0 . Any other value of grundy number denotes a winning position . The grundy number of the position is the smallest number which is not a grundy number of the position reachable from it . The grundy number of a combination of games is the xor of grundy numbers of all the games .

Explanation :
Subtask 1 and 2 can be solved with Basic game theory . For subtask 3 apply Sprague Grundy Theorem .*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
//sg[i] - Sprague-Grundy's number for a group of i stones. We can calculate it in a 
//standard way because there are only 6 numbers that n^n does not exceed 10^5.
int main(){
    int tc;
    scanf("%d", &tc);    
    int sg[100333];
    sg[0] = 0;
    int deg[123];
    int i, j;
    for (i = 1; i <= 7; i++){
        deg[i] = 1;
        for (j = 1; j <= i; j++)
            deg[i] = deg[i] * i;    
    }
    int o = 0;
    int used[1000]={};
    for (i = 1; i <= 100000; i++){
        o++;
        for (j = 1; deg[j] <= i; j++){
            used[sg[i- deg[j]]] = o;//mark all reachble positions with 'o'
        }
        for (j = 0; j <= 1 << 30; j++)
            if (used[j] != o) {sg[i] = j; break;}//finding MEX
    }
    while (tc--){
        int n;  
        scanf("%d", &n);
        int ans = 0;
        for (i = 1; i <= n; i++){
            int x;
            scanf("%d", &x);
            ans ^= sg[x];
        }          
        if (ans) printf("Little Chef\n");
        else printf("Head Chef\n");
    }
}
