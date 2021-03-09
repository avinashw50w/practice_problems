/*Berland shop sells 𝑛 kinds of juices. Each juice has its price 𝑐𝑖. Each juice includes some set of vitamins in it. There are three types of vitamins: vitamin "A", vitamin "B" and vitamin "C". Each juice can contain one, two or all three types of vitamins in it.

Petya knows that he needs all three types of vitamins to stay healthy. What is the minimum total price of juices that Petya has to buy to obtain all three vitamins? Petya obtains some vitamin if he buys at least one juice containing it and drinks it.

Input
The first line contains a single integer 𝑛 (1≤𝑛≤1000) — the number of juices.

Each of the next 𝑛 lines contains an integer 𝑐𝑖 (1≤𝑐𝑖≤100000) and a string 𝑠𝑖 — the price of the 𝑖-th juice and the vitamins it contains. String 𝑠𝑖 contains from 1 to 3 characters, and the only possible characters are "A", "B" and "C". It is guaranteed that each letter appears no more than once in each string 𝑠𝑖. The order of letters in strings 𝑠𝑖 is arbitrary.

Output
Print -1 if there is no way to obtain all three vitamins. Otherwise print the minimum total price of juices that Petya has to buy to obtain all three vitamins.

inputCopy
4
5 C
6 B
16 BAC
4 A
outputCopy
15*/

ll solve() {
    int n;
    cin >> n;
    int cost;
    string s;
    // dp[i][mask] - the minimum cost to buy juices upto index i contaning vitamins in the mask
    ll dp[n+1][8]; 
    const ll inf = 1e17;
    fill(&dp[0][0], &dp[0][8], inf);

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> cost >> s;
        int curr_mask = 0;
        for (char c: s) {
            curr_mask |= 1 << (c - 'A');
        }

        for (int mask = 0; mask < 8; ++mask) {
            // don't buy the ith juice
            dp[i+1][mask] = min(dp[i+1][mask], dp[i][mask]); 
            // buy the i'th juice
            dp[i+1][mask | curr_mask] = min(dp[i+1][mask | curr_mask], dp[i][mask] + cost);
        }
    }

    ll ans = inf;
    for (int i = 0; i <= n; ++i) {
        ans = min(ans, dp[i][7]);
    }

    if (ans == inf) ans = -1;

    return ans;
}