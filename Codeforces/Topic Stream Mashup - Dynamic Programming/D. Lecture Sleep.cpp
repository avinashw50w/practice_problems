/*Your friend Mishka and you attend a calculus lecture. Lecture lasts n minutes. 
Lecturer tells ai theorems during the i-th minute.

Mishka is really interested in calculus, though it is so hard to stay awake for all the time of lecture.
 You are given an array t of Mishka's behavior. If Mishka is asleep during the i-th minute of the lecture 
 then ti will be equal to 0, otherwise it will be equal to 1. When Mishka is awake he writes down all the 
 theorems he is being told — ai during the i-th minute. Otherwise he writes nothing.

You know some secret technique to keep Mishka awake for k minutes straight. However you can use it only 
once. You can start using it at the beginning of any minute between 1 and n-k+1. If you use it on some 
minute i then Mishka will be awake during minutes j such that  and will write down all the theorems 
lecturer tells.

You task is to calculate the maximum number of theorems Mishka will be able to write down if you use your 
technique only once to wake him up.

Input
The first line of the input contains two integer numbers n and k (1<=k<=n<=1-^5) — the duration of the 
lecture in minutes and the number of minutes you can keep Mishka awake.

The second line of the input contains n integer numbers a1,a2,... an (1≤ai≤10^4) — the number of theorems 
lecturer tells during the i-th minute.

The third line of the input contains n integer numbers t1,t2,... tn (0≤ti≤1) — type of Mishka's behavior 
at the i-th minute of the lecture.

Output
Print only one integer — the maximum number of theorems Mishka will be able to write down if you use your technique only once to wake him up.

Example
inputCopy
6 3
1 3 5 2 5 4
1 1 0 1 0 0
output
16 */

// sol: this is a sliding window problem where the length of the window is k

////////////////////////////////////////////////////////////////
int solve(int n, int k) {
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int p[n] = {0}, s[n] = {0};
    p[0] = a[0];
    for (int i = 1; i < n; ++i) {
        p[i] = a[i] * b[i] + p[i-1];
    }
    int r = 0;
    for (int i = n-1; i >= 0; --i) {
        r += a[i] * b[i];
        s[i] = r;
    }

    int pref[n] = {0};
    r = 0;
    for (int i = 0; i < n; ++i) {
        r += a[i];
        pref[i] = r;
    }

    int ans = -1e17;
    for (int i = 0; i + k - 1 < n; ++i) {
        int curr = 0;
        if (i > 0) curr += p[i-1];
        if (i + k < n) curr += s[i + k];
        int range_sum = pref[i + k -1];
        if (i > 0) range_sum -= pref[i - 1];

        curr += range_sum;

        ans = max(ans, curr);
    }

    return ans;
}

////////////////////////////////////////////////////////////////////////
int solve(int n, int k, vector<int> a, vector<int> t) {
    int sum = 0, ans = 0, end = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i >= k) 
            sum -= a[i-k] * t[i-k];
        sum += a[i] * t[i];
        if (sum > ans) {
            ans = sum;
            end = i;
        }
    }
    int start = end - k + 1;
    for (int i = 0; i < start; ++i) {
        ans += a[i]*t[i];
    }
    for (int i = end+1; i < a.size(); ++i) {
        ans += a[i]*t[i];
    }

    return ans;
}