/* Mr. Napa, the terrorist, came to MNNIT and has attacked the Lecture Hall. He has a freeze gun and has frozen everyone there.

Dassu, the super-human , came to their rescue. Dassu destroyed the freeze gun and ruined NAPA's plan. But Dassu is unable to revert people back to normal. 




There are 2 red buttons on the top-right block (1, M) . One is to convert all the people on that block back to normal, other is to kill all the people on that block. But the thing is only one button can be pressed and that too once. Dassu wants to save all the people and NAPA wants to kill all of them. 

Since no one can achieve their goal individually, so NAPA proposed an agreement. He said that both of them want everyone to be present in the top-right block. So they should begin by pushing people towards that block. The one who pushed the last person would press his/her desired button.

Now the Lecture hall is rectangular and divided in blocks. There are N rows( 1 , 2 .. , N ) and M columns ( 1, 2 .. , M ). There are P people in the Hall. 


Now Dassu and Mr. NAPA would play turn by turn and could select any block( with atleast one person ) and push some people(any positive number) from that block to the block up or right(but not both) of it.
Now Dassu wants to know whether to play the game or not. Dassu will move first and will only play the game if Dassu can save everyone. Both Dassu and Mr. NAPA are nerds, so they will make the best possible moves.
 
NOTE: There may be multiple people on a single block at a time
Input

The First line would contain 3 integers - N, M & P

The next P lines would contain 2 integers each, the row and column number of each person. 
 
Output

"Yes" if DASSU can win the game, and "No" otherwise.
 
Constraints

Should contain all the constraints on the input data that you may have. Format it like:
1 = N * M = 1018
1 = N,M
1 = P = 106
1 = X = N
1 = Y = M
 
Example

Input:
3 3 1

2 2


Output:
No
 
Explanation

The person is at (2, 2).



Possible ways to reach (1, 3):-

(2, 2) -> (2, 3) -> (1, 3)

(2, 2) -> (1, 2) -> (1, 3)

In both the case, NAPA is making the last move. ...

Solution: */

DIFFICULTY
Medium

PREREQUISITES
Game-Theory , Staircase Nim

PROBLEM
Various people are standing on various blocks in a rectangular matrix. You can select a block with atleast 1 person and push any positive number of people from that block to the block above or right of that. You have to push all the people to the top-right corner. 

EXPLANATION
This question uses the concept of "staircase nim" of game theory.
Let's start from the basic. 
P1(Dassu) moves first. Suppose that there is a person at (i,j) and he has to reach (x,y). If (x+y) and (i+j) has the same parity, after reaching (x,y) it would be P1's move. So if (x+y) and (i+j) has the same parity, there's no change in order to continue the game forward. However if they have different parity, the order would change. 

We Can assign a value 0 or 1 to the situation.

0 - same parity i.e no change in order
1 - different parity i.e. change in order

Now suppose there are 2 people and let us suppose that their moves are independent. So we will consider the 2 independently and assign 0 or 1 to each as described above. To combine these independent situation into one, we can XOR them. Why this works? 

Now we need to consider one more case. If there are more than one person in a block, they are not independent. Why? Because we can move them all (or some) in one move to the next block. So what we need to see is the least (non-negative)number that is not possible when we make a move on the current block. Grundy Numbers 

In case , there was only a single person, we can move only one - so remaining can be 0. So minimum not possible is 1.
In case , there were 2 people, we can move one or both - so remaining can be 0,1. So minimum not possible is 2.
In case , there were 3 people, we can move 1,2 or all- so remaining can be 0,1,2So minimum not possible is 3.
Hence in this example grundy number of a particular pile( or block ) is the number of people in the block.

Now we have considered all the cases:- So what has our solution reduced to?

ans=0
for( all the blocks )
 {
    if parity_current_block is not equal to parity_destination_block
    ans= ans ^ grundy_number;
 }
Alternate Approach


The (1,M) is a loosing case. If all are on (1,M) , the player who makes the first move looses. So the Grundy Number assigned to (1,M) is 0.
We can go to (1,M) only from (1,M-1) and (2,M). So their grundy number are 1 as we can reach a 0 condition from there.
For(2,M-1), we can reach 1-condition but not 0-condition. So its grundy number becomes 0. Proceeding in this way, We see that grundy number possible are 0 & 1 and are alternation. 
For N=4 and M=3, grundy number matrix would look like:-

0 1 0
1 0 1
0 1 0
1 0 1

The person standing on a particular block are it's multiplier. 


ans=0
for( all the blocks )
  {
    grundy_number = ( (i+j)%2 != (1+m)%2 )
    ans= ans ^ ( grundy_number * multiplier );
  }
Setter Code
Code

In case the range for Input i.e. N & M are small, the following code would work :-

#include<bits/stdc++.h>
using namespace std;

#define LL long long int
vector<vector<int> > a;
int N,M,P;
void play()
{
    int grundy_value, ans = 0; 
    LL i,j;
    for(i=N;i>=1;i--)
    {
      for(j=1;j<=M;j++)
      {
         grundy_value=a[i][j];
         if( (i+j) % 2 != (1+M) % 2) //(1,M) is the destination
         ans^=grundy_value;
      }
    }
    cout<<(ans ? "Yes" : "No")<<endl;
}

int main() 
{
    int i,j;
    cin>>N>>M>>P;
    a.resize(N+1,vector<int> (M+1,0));
    for(i=0;i<P;i++)
    {
        int X,Y;
        cin>>X>>Y;
        a[X][Y]++;
    }
    play();
    return 0;
}
But as the range grows, we need to think of alternate methods rather than storing the people as matrix.

The Following code will work :-

#include<bits/stdc++.h>
using namespace std;

#define LL long long int
vector<pair<LL,LL> > a;
LL N,M,P;
void play()
{
    sort(a.begin(),a.end());
    LL grundy_value=1, ans = 0;
    LL i;
    for(i=1;i<P;i++)
    {
         if(a[i]==a[i-1])
         grundy_value++;
         else
         {
            LL x,y;
            x=a[i-1].first;
            y=a[i-1].second;
            if( (x+y) % 2 != (1+M) % 2) //(1,M) is the destination
            ans^=grundy_value;
            grundy_value=1;
         }
    }
            LL x,y;
            x=a[P-1].first;
            y=a[P-1].second;
            if( (x+y) % 2 != (1+M) % 2) //(1,M) is the destination
            ans^=grundy_value;

    cout<<(ans ? "Yes" : "No")<<endl;
}

int main()
{
    LL i,j;
    cin>>N>>M>>P;
    for(i=0;i<P;i++)
    {
        LL X,Y;
        cin>>X>>Y;
        a.push_back(make_pair(X,Y));
    }
    play();
    return 0;
}
