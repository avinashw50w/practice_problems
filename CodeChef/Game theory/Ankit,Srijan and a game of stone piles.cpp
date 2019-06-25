/* There are N piles of stones, where i-th pile has Ai stones. A game is played on these piles, in order from pile 1 to N. When the game is on the i-th pile, a player 
can remove any non-zero number of stones from this pile in a single move. If the current pile becomes empty, the game moves on to the next pile. The player who is 
unable to make a move loses.
Srijan and Ankit are going to play this game. Ankit, being younger, always gets to start the game. However, Srijan, being clever, sneaks into the game arena early and 
permutes the order of piles. Then, the game is played on this new order of piles. Your task is to find out the number of orders in which the piles can be arranged 
so that Ankit wins the game. Assume that both the players play optimally. Since the answer can be very large, output it modulo 109 + 7.
Note that two orders are considered different if their contents are different. Formally, two orders A and B are different if there exists an index k (1 = k = N) 
such that Ak != Bk.
Input

The first line contains an integer T, denoting the number of test cases to follow. Each of the test cases contains exactly two lines.
The first line for each test case contains an integer N, denoting the number of piles, and the next line contains N space-separated integers, denoting the number 
of stones in the piles.
Output

For each test case, output a single integer corresponding to the answer for that test case.
Constraints

1 = T = 1000
1 = N = 10^5
1 = Ai = 10^10
The sum of values of N over all test cases does not exceed 10^6.
Example:

Sample input:
2
3
1 1 2
2
2 3

Sample Output:
2
2

Explanation:
Case 1:
The following different orders are possible:
[1, 1, 2]
Ankit removes the only stone in the first pile.
Srijan removes the only stone in the second pile.
Ankit removes both the stones in the second pile.
Ankit wins.
[1, 2, 1]
Ankit removes the only stone in the first pile.
Srijan takes one stone from then the second pile. Ankit removes the remaining one stone from the second pile.
Srijan removes the only stone in the third pile.
Srijan wins.
[2, 1, 1]
Ankit removes both the stones in the first pile.
Srijan removes the only stone in the second pile.
Ankit removes the only stone in the second pile.
Ankit wins.
Thus, Ankit wins on 2 different orders.

Solution:
DIFFICULTY:
Easy-Medium.

PREREQUISITES:
Game theory and Combinatorics.

PROBLEM:
A game is played with the rule that a non-zero number of the stones must be removed from the first non-empty pile. Find the number of permutations of the piles, 
in which the first player has a winning strategy.

QUICK EXPLANATION:
Find a way to check if a given permutation is the winning permutation, followed by finding the number of permutations which satisfy the given condition.

EXPLANATION:
The problem can be solved using various claims.

Claim 1: If each pile contains exactly 1 stone. Now, if number of piles is even, then second player will win. Otherwise, first player will win.

Reason: The reason being that each player will have exactly one way of making a move, i.e. emptying the current pile.

Claim 2: If the first pile contains more than one stone, then first player will always win.

Reason: Suppose that piles are numbered as 1,2,3...N. Number of stones in piles are given as A1,A2,....AN with the condition A1=2.

Case 1: Suppose in piles A2,A3,...AN, first player has winning strategy, then first player will remove A1-1 number of stones from the first pile and second 
player will be enforced to remove remaining 1 stone. First player will have winning strategy on remaining piles.

Case 2: Suppose in piles A2,A3,...AN, first player doesn't have winning strategy, then first player will empty first pile in single move. So, when game will 
arrive as pile 2, second player will not have the winning strategy, hence first player will have winning strategy.

Claim 3: Now we can claim very easily that first player will win if permutation is in such a way that A1=1,A2=1,...Ax=1,Ax+1!=1, and x is an even number, 
because when the game will arrive at pile number (x+1), first player will be making first move and he will win according the points given above.

How to count number of permutations such that number of 1's in the beginning is even?

Suppose count of 1's in the array A is M. Each distinct number of array A(except 1) is in array B, i.e., B1,B2,...BK, and count of Bi in array A is cnt[Bi].

Now count the number of permutations in which number of 1's in the beginning is at least x. To do that, keep x 1's in the beginning and permute rest of the numbers.

W(x)=(N-x)!/((M-x)!(cnt[B1]! cnt[B2]! .... cnt[BK]!)
Consider K=1/(cnt[B1]! cnt[B2]! .... cnt[BK]!)
So,W(x)=K×(N-x)!/(M-x)!
Number of permutations in which number of 1's in the beginning is exactly 2r.

Ways(2r)=W(2r)-W(2r+1)
So, number of permutations in which numbers of 1's in the beginning is even:

Number of permutations=?r=02r+1=MWays(2r)
K is a constant which can be calculated in O(N) time, and we can calculate it in the beginning. So, Number of permutations can also be calculated in O(N) time.*/

ll gcd(ll a, ll b)
{
    if( (a == 0) || (b == 0) )
        return a + b;
    return gcd(b, a % b);
}
 
ll pow_mod(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
ll arr[100010], fact[100010], ifact[100010], B[100010];
 
int main()
{
        #ifndef  ONLINE_JUDGE
            freopen("input.txt","r",stdin);
        #endif
 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
 
        ll N, i, j, M, cnt, oo, KK, RR, ans, ans22, T, ans33;
        string st;
 
        fact[0] = 1;
        rep(i, 1, 100005)
        {
            fact[i] =( (fact[i-1] * i) %MOD );
        }
        ifact[100005] = pow_mod(fact[100005], MOD-2);
        rrep(i, 100004, 0)
        {
            ifact[i] =( ( ifact[i+1] * (i+1) ) %MOD );
        }
 
        cin>>T;
        while( T-- )
        {
              cin >> N;
              oo = 0;
              KK = 1;
              ans = 0;
              M = 0;
 
              rep(i, 0, N-1)
              {
                  cin >> arr[i];
                  if( arr[i]==1 )
                  {
                      M++;
                  }
              }
              if( M==N )
              {
                  if( (N%2)==0 )
                  {
                      cout << "0" << endl;
                  }
                  else
                  {
                      cout << "1" << endl;
                  }
 
                  continue;
              }
              sort( arr, arr+N );
              cnt = 1;
              rep(i, 0, N-1)
              {
                  if( arr[i] > 1 )
                  {
                      if( arr[i] == arr[i+1] )
                      {
                          cnt++;
                      }
                      else
                      {
                          B[oo++] = ifact[cnt];
                          cnt = 1;
                      }
                  }
              }
              rep(i, 0, oo-1)
              {
                  KK =( ( KK * B[i] ) %MOD );
              }
              rep(i, 0, M)
              {
                  if( (i%2)==0 )
                  {
                        ans22 = ( ( fact[N - i] * KK ) %MOD );
                        ans22 =( (ans22 * ifact[M - i]) %MOD );
                        ans =( (ans + ans22) %MOD );
                  }
                  else
                  {
                      ans22 = ( ( fact[N - i] * KK ) %MOD );
                      ans22 =( (ans22 * ifact[M - i]) %MOD );
                      ans =( (ans - ans22 + MOD) %MOD );
                  }
              }
 
              cout << ans << endl;
        }
 
        return 0;
}
 
