/* Alice and Bob play the following game.
Given two numbers x and m . A grid is built in the following fashion:
x			x + 1	x + 2		..........	x + m - 1
x + 1		x + 2	x + 3		..........	x + m
x + 2		x + 3	....		........	x + m + 1
....		....	....		..........	....
x + m -1	x + m	x + m + 1	........	x + 2m - 2

Each cell is a pile and the value in each cell is the number of stones in that pile. In each turn, a player removes any non-zero number of stones from any one pile. 
Game ends when all the piles become empty. The player who is unable to make a move looses the game. Both of them play optimally. Alice starts the game. You have to tell who 
the winner will be.
Input

The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contains two integers x and m.
Output

Output T lines, one for each test case, containing ALICE if Alice wins the game, or BOB otherwise.
Constraints

1 = T = 10^5
0 = x = 10^18
0 = m = 10^18
Example

Input:
2
1 1
1 2
Output:
ALICE
ALICE
 
Explanation

Example case 1. Alice will take away the one coin in the first move and thus Bob will not be able to make a move.*/

#include "bits/stdc++.h"
using namespace std;
int t;
long long x , m;
bool solve(long long x , long long m){
    if(m == 0){
        return 1;
    }
    if(x == 0){
        if((m % 4) == 0){
            return 1;
        }
        if(m == 1){
            return 1;
        }
        return 0;
    }
    if(x == 2){
        if(m % 4 == 3){
            return 1;
        }
        return 0;
    }
    if(((x % 4) == 0) || ((x % 4) == 1)){
        if((m % 4) == 0){
            return 1;
        }
    }
    return 0;
}
bool brute(long long x , long long m){
    long long xo = 0;
    for(long long i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < m ; ++j){
            xo ^=  (x + i + j);
        }
    }
    return !xo;
}
int main(){
    /*for(int i = 0 ; i <= 100 ; ++i){
        for(int j = 1 ; j <= 100 ; ++j){
            assert(solve(i , j) == brute(i , j));
        }
    }*/
    scanf("%d" , &t);
    while(t--){
        scanf("%lld %lld" , &x , &m);
        assert(x >= 0);
        assert(m >= 0);
        puts(solve(x , m) ? "BOB" : "ALICE");
    }
} 
