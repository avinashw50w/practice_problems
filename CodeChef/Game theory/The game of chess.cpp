/* Infotsav has always been about geeks and geek-stuff, with the best of brains battling it out for victory. Since we are talking about the battle of wits, what better than a game of chess! You are given a 50x50 chessboard, where the bottom left corner is indexed (0, 0). There is a knight and a queen on the chessboard and you and your friend is playing your own version of chess. Both of you play your turns alternatively, with you taking the first turn.
In each turn you select any one of the pieces and move it such that they don’t move towards right or towards top. That is they must move to either left, bottom or bottom-left. The one who will not be able to make a move in his turn will lose the game. Both players will play optimally.


Note


- A knight can move

- 2 vertical and 1 horizontal steps, or 1 vertical and 2 horizontal steps.


- Queen can move 

*at least* one step
- horizontally, vertically or diagonally
Input

The First line contains an integer, T, representing the number of test cases, followed by T lines.
The Each of these test cases consists of four integers, xk, yk, xq, yq, where (xk, yk) represents the index of knight, while (xq, yq) represents the index of the Queen.
Output

For each test case, print "WIN" (without quotes) if you can win the game,
otherwise print "LOSE".
Constraints

1 = T = 10^6
0 = xk, yk, xq, yq < 50
Example

Input:
2
1 1 3 0
2 2 0 1

Output:
WIN    
LOSE
Explanation

Test case #1: Knight being at (1, 1) will not be able to make a move. Since queen is at (3, 0), you can
move it to the left three steps so that it lands at (0, 0). Now your friend doesn't have any option to make a move, leading to your victory.
Test case #2: Initally
knight is at (2, 2) and queen is at (0, 1). Knight can be moved exactly one time, i.e. to (0, 1) or (1, 0), and similarly queen will be able to make exactly one
move, i.e. to (0, 0). So you have to select any one of them, and your friend will be to choose the other move. Since you don't have any more move, you are bound to
loose the game. ...

Solution:
DIFFICULTY:

DIFFICULT

EXPLAINATION

The chess-game can be considered to two independent chess games, where in first only a knight is present and the queen in other.

Now each game is equivalent to single nim heap in the nim game.

Now we will calculate the grundy values for each game interdependently (which is the minimum excluded value, mex, for each position).

For Knight game, where knight is at (x, y),

grundyKnight(x, y) = mex(grundyKnight(x-1, y-2), grundyKnight(x-2, y-1))

Similarly for Queen game, with queen at (x, y)

grundyQueen(queen) = mex( grundyQueen(x-i, y), grundyQueen(x-i, y-i), grundyQueen(x, y-i)) , where 1 <= i <= 50

So the grundy value of both game combined (original game) is the nim sum of both games.

grundy(knight-game + queen-game) = grundyKnight(knight-position) xor grundyQueen(queen-position)

Since, according to sprague grundy theorem, the game can be won if grundy value is a positive value.*/

#include <bits/stdc++.h>
using namespace std;
 
const int sz = 50;
 
vector <vector<int> > knight(sz, vector <int> (sz, -1));
vector <vector<int> > queen (sz, vector <int> (sz, -1));
 
void checkWithAssert(int v) {
    assert(0 <= v && v < sz);
}
 
bool inRange(int x, int y) {
    return x >= 0 && x < sz && y >= 0 && y < sz;
}
 
int grundyKnight(int x, int y) {
    int &ret = knight[x][y];
    if(ret != -1)
        return ret;
 
    set <int> mex;
    mex.clear();
 
    if(inRange(x-1, y-2))
        mex.insert(grundyKnight(x-1, y-2));
    if(inRange(x-2, y-1))
        mex.insert(grundyKnight(x-2, y-1));
 
    ret = 0;
    while(mex.find(ret) != mex.end()) {
        ret++;
    }
    return ret;
}
 
int grundyQueen(int x, int y) {
    int &ret = queen[x][y];
    if(ret != -1)
        return ret;
 
    set <int> mex;
    mex.clear();
 
    for(int i = 1; i < (int)sz; ++i) {
        if(inRange(x-i, y))
            mex.insert(grundyQueen(x-i, y));
        if(inRange(x, y-i))
            mex.insert(grundyQueen(x, y-i));
        if(inRange(x-i, y-i))
            mex.insert(grundyQueen(x-i, y-i));
    }
 
    ret = 0;
    while(mex.find(ret) != mex.end()) {
        ret++;
    }
    return ret;
}
 
bool isWin(int xk, int yk, int xq, int yq) {
    return (grundyKnight(xk, yk) ^ grundyQueen(xq, yq)) != 0;
}
 
int main()
{
    int T;
    cin >> T;
    assert(1 <= T && T <= (int)1e5);
 
    while(T--) {
        int xk, yk, xq, yq;
        cin >> xk >> yk >> xq >> yq;
 
        checkWithAssert(xk);
        checkWithAssert(yk);
        checkWithAssert(xq);
        checkWithAssert(yq);
 
        cout << (isWin(xk, yk, xq, yq) ? "WIN" : "LOSE") << "\n";
    }
 
    return 0;
}
