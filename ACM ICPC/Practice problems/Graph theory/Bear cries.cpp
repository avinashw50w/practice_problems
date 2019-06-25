/*Today Limak is sad, so he sent his friend a sequence of crying emoticons. However, due to a network malfunction all those emoticons got 
mixed together into a single string.
You are given a String message containing the message Limak's friend received. You guess that the message can be divided into one or more 
crying emoticons. Each emoticon must be a subsequence of the message, and each character of the message must belong to exactly one emoticon. 
Note that the subsequences are not required to be contiguous.
Let X be the number of ways in which one can divide the gives message into emoticons. Compute and return the value (X modulo 1,000,000,007).

Definition
    	
Class:	BearCries
Method:	count
Parameters:	String
Returns:	int
Method signature:	int count(String message)
(be sure your method is public)
    
 
Constraints
-	message will contain between 1 and 200 characters, inclusive.
-	Each character in message will be either semicolon or underscore.
 
Examples
0)	
    	
";_;;_____;"
Returns: 2
There are two ways to divide this string into two crying emoticons. One looks as follows:
 ;_;
    ;_____;
and the other looks like this:
 ;_ ;
   ; _____;

 We will aim towards a dynamic programming solution. Each of the ; characters can be assigned one of two roles: First or second ; in an 
 emoticon. Let's see them as opening and closing ; characters. The "_" characters need to be assigned to open ; that come to their left. 
 Each open ; needs to be assigned at least one "_" before we can close it. At the end, there should be no open ;. There is a difference 
 between an open emoticon that already contains a "_" and one that still doesn't have any.

Let's assign the roles of the characters starting i=0i=0 and moving forward. We should use aa to represent the current number of open 
emoticons without "_" and bb the number of open emoticons with at least one "_"

If s[i]s[i] is ; we can use it to open or close an emoticon.
If s[i]s[i] opens an emoticon then the number of currently open emoticons increase by 1: a=a+1a=a+1
If s[i]s[i] closes an emoticon then we can only pick one of the bb emoticons that can be closed and close it. bb will decrease.
If s[i]s[i] is "_" then it must be assigned to an open emoticon.
We can assign it to one of the aa emoticons that lack a "_". There are aa options in total and this decreases aa while decreasing bb.
We can assign it to one of the bb emoticons that already contain one or more "_". There are bb options and aa and bb remain unchanged.
Move to the next character, ii increases.
We just need to translate this into something that counts the number of ways to assign. Let f(i,a,b)f(i,a,b) be the number of ways to assign 
the characters with index greater than or equal to ii, assuming that the first ii characters have already been assigned in such a way that 
there are aa open emoticons that lack a "_" and bb open emoticons that can be closed because they contain a "_".

Base case: i=ni=n meaning that all characters were assigned and there is nothing else to do. If a=b=0a=b=0, then there are no open emoticons, 
meaning everything is consistent and the result is 1 because there is 1 correct way to finish. Else the result is 0 because nothing we can 
do is correct.
If s[i] is ";":
s[i] opens an emoticon: f(i+1,a+1,b)
or s[i] closes an emoticon: b.f(i+1,a,b−1).
If s[i] is "_" :
Assign it to an open emoticon that lacks a "_": a.f(i+1,a−1,b+1)
Or assign it to an open emoticon with "_": b⋅f(i+1,a,b)b⋅f(i+1,a,b)
f(i,a,b)f(i,a,b) is the sum of all these results.
This is a recurrence relation that we can implement using memoization so that each distinct state is processed at most once. ii, aa and 
bb are each O(n)O(n) so the implementation would be O(n3)O(n3), which is all right for n≤200n≤200, but we can improve this by noticing that 
there cannot be more than n3n3 emoticons in total, hence aa and bb won't be larger than 66. (Make sure to stop incrementing aa when it is 
that large).*/

const int MOD = 1000000007;
 
string message;
int n;
 
long dp[201][67][67];
 
long f(int i, int a, int b)
{
    // i: number of positions we already processed
    // a: current number of open ; without _
    // b: current number of open ; that already have _
    long res = dp[i][a][b];
    if (res == -1) {
        res = 0;
        if (i == n) {
            // all must be closed
            if (a == 0 && b == 0) {
                res = 1;
            }
        } else {
            if (message[i] == '_') {
                if (a > 0) {
                    // pick an open ; and add its first _
                    res += ( a * f(i + 1, a - 1, b + 1) ) % MOD;
                }
                if (b > 0) {
                    // pick an open ; with _ and add even more _
                    res += ( b * f(i + 1, a, b) ) % MOD;
                }
            } else {
                if (a < n/3) {
                    // open an ;
                    res += f(i + 1, a + 1, b);
                }
                if (b > 0) {
                    // close an ;
                    res += ( b * f(i + 1, a, b - 1) ) % MOD;
                }
            }
        }
        res %= MOD;
        dp[i][a][b] = res;
    }
    return res;
}
 
int count(string message)
{
    this->message = message;
    n = message.size();
    // fill dp array with -1
    memset(dp, -1, sizeof(dp));
    return (int)f(0, 0, 0);
}