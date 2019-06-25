/* Tuzik and his master Vanka are playing some unusual game. Initially there are two stacks of nuts. The first stack contains A nuts and the second contains B nuts. A player's move consists of two steps:
Choose one stack and eat it.
Split the other stack into two new stacks. If a player can't split it he loses (if stack contains only 1 nut).
Tuzik starts the game. Tell who wins if both players play optimally.
Input

The first line of the input contains an integer T, denoting the number of test cases. The following T lines each contain 2 space-separated integers - A and B - for this test case.
Output

For each test case, output a single line containing the word "Tuzik" or "Vanka" (without quotes) depending on the winner in this test case.
Constraints

1 = T = 1000
1 = A, B = 104
Subtask #1[26 points]:1 = A, B = 10
Subtask #2[30 points]:1 = A, B = 100
Subtask #3[44 points]: 1 = A, B = 104
Example

Input:
2
1 1
1 2

Output:
Vanka
Tuzik
Explanation

In the first test case Tuzik can't finish even the first move, so Vanka wins.
In the second test case Tuzik eats the first stack (with 1 nut), then splits the second stack (with 2 nuts) into two stacks, and Vanka loses.

Solution: 
DIFFICULTY:
EASY

PREREQUISITES:
Game theory, Induction

PROBLEM:

There is a two player game which is played on two stacks of nuts. Players take moves alternately. The first player makes the first move. A valid move consists of two consecutive actions:

Choose one stack and remove all nuts from it. It results in removing this stack from the game
Split the remaining stack into two non-empty new stacks in any possible way
A player loses the game when he is not able to make any valid move.

Your task is to decide which player has a winning strategy if both of them play optimally.

QUICK EXPLANATION:

Consider all possible configurations of parity of the number of nuts in each stack. Based on that, figure it out which positions are winning and which are not. First player has a winning strategy if and only if the initial configuration of stacks is a winning position.

EXPLANATION:
Let's call a configuration of stacks a position in the game. Notice that a configuration can be presented as an unordered pair of integers {A,B}, where A and B denote the number of nuts on stacks.

We will call a position a losing one if and only if there is no valid move which leads to victory from this position. Respectively, we call a position a winning one, if and only if there exists a move which leads to a losing configuration for the opponent. It is called a winning position, because the current player has an ability to make a move which force his opponent to lose the game no matter what the opponent does.

Let's take a closer look to the problem by considering some small positions.

The smallest achievable position is {1,1}, because you can never produce an empty stack in a valid move. A player cannot make any move from position {1,1}, because there is no way to split a stack which contains only one nut (you have to remove the other one first).

Let's consider another position, {1,2}. The only valid move which a player can make is to remove the stack with one nut and split the other stack in half, which results in the configuration {1,1}. We know that {1,1} is a losing position, so {1,2} is a winning one.

Similarly, {2,2} is a winning position, because a player can remove any stack and split the other in half, which leads to {1,1} - a losing position for the opponent.

What about {2,3}? It is a winning one also. You can make a move similar to the previous two situations, i.e. remove the stack with 3 nuts and split the other in half, 
which leads to {1,1} position.

But not every position other that {1,1} is a winning one. Consider the position {1,3}. If you decide to remove the stack with 3 nuts, you cannot split the other one, 
so this move is not valid. It follows that every valid move has to remove the stack with one nut first and split the other in some way. Unfortunately, 
there is only one way to split a stack of 3 nuts, and it results with {1,2} which is a winning position for the opponent. We showed that {1,3} is a losing position. 
From the same argument, it follows that {3,3} is a losing position also.

What do the above losing position have in common? Well, in each of them both stacks have odd parity. Let's try to prove the following lemma.

Lemma:

Position {A,B} is losing if and only if A and B are odd. Every other position is a winning one.

We will prove the lemma by induction on the greater number in the position. Let {A,B} be any game position, where A=B. We showed that the lemma is true for B=3. 
Let {A,B} be any position where B>3, and we assume that the lemma is true for all positions {C,D} where C=D and D<B. We will show that it is also true for {A,B}.

There are two cases to consider:

A and B are both odd.

No matter which stack is removed first, the remaining stack has an odd number of nuts in it, so in any valid configuration formed by splitting it, 
one stack will have an odd number of nuts while the other will have an even number of nuts on it. Moreover, both these stacks will have less nuts than B, 
so from our assumption, we know that the just formed position is a winning position, so the position {A,B} is a losing one.

At least one stack have an even number of nuts on it.

It this case, we have to show that this position is a winning one. To make a desired move, we can split the stack with even number of nuts on it, 
so we remove the other one first (if there are two stacks with an even number of nuts, we can remove either one). Now we are about to split the 
stack in two new stacks and we can always do this to form two new smaller stacks with odd number of nuts on both of them. This is possible, 
because our original stack has even number of nuts. It follows from the assumption, that we can make a move which leads to a losing position 
for the opponent, so our position is a winning one.

Based on the lemma which we just proved, it follows that the first player has a winning strategy if and only if at least one initial stack 
has an even number of nuts in it. */

// time-complexity O(MAXN*MAXN) for precalculation, O(1) per query

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10100;
bool win[MAXN];

void precalc() {
    win[0] = win[1] = false;
    for (int i = 2; i < MAXN; i++) {
        win[i] = false;
        for (int j = 1; j < i; j++) {
            if (!win[j] && !win[i - j]) {
                win[i] = true;
                break;
            }
        }
    }
}

void solve() {
    int a, b;
    cin>>a>>b;
    if (win[a] || win[b]) {
        cout<<"Tuzik"<<"\n";
    }
    else {
        cout<<"Vanka"<<"\n";
    }
}

int main() {
    precalc();
    int tests;
    cin>>tests;
    while (tests--) {
        solve();
    }
    return 0;
}
