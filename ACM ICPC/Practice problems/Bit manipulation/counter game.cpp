/*Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. 
In the game, they perform the following operations.

If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
If N is a power of 2, reduce the counter by half of N.
The resultant value is the new N which is again used for subsequent operations.
The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins.

Given N, your task is to find the winner of the game.

Update If they set counter to 1, Richard wins, because its Louise' turn and she cannot make a move.

Input Format 
The first line contains an integer T, the number of testcases. 
T lines follow. Each line contains N, the initial number set in the counter.

Constraints

1 ≤ T ≤ 10 
1 ≤ N ≤ 264 - 1

Note: Range of N is larger than long long int, consider using unsigned long long int.
*/

#include <iostream>
#include <cstdio>

int main() {
    long long unsigned int n, tmp;
    int turns, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%llu", &n), tmp=n;
        turns=0;
        while(tmp) tmp&=tmp-1, turns++;
        turns--;
        while((n&1)==0) n>>=1, turns++;
        if(turns%2==0) printf("Richard\n");
        else printf("Louise\n");
    }
    return 0;
}