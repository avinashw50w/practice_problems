/*link: https://codeforces.com/gym/302977 */

/*You have a given integer 𝑛. Find the number of ways to fill all 3×𝑛 tiles with the shape 
described in the picture below. Upon filling, no empty spaces are allowed. Shapes cannot overlap.
___
   |    it's like an L shape

IDEA: if tile is of size 3x2 then there are two ways to fill the tile will this L shaped object.
SO recurrence is: f(i) = 2 * f(i-2)
*/

ll solve(int n) {
    vector<ll> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 2 * dp[i-2];
    }

    return dp[n];
}

// another easier method
// break the tile in 3x2 pieces then each piece has 2 ways to be filled by the shape
// so ans = 2 ^ (n/2)
ll solve(int n) {
    return 1 << (n/2);
}