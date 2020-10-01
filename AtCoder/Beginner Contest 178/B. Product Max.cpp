/*Given four integers a,b,c and d. If x and y are integers and a <= x <= b and c <= y <= d holds.
Then what is the maximum value of x * y */

/**
 * [a .. b]
 * [c .. d]
 * ans will be maximum of these four combinations: b*d, a*c, b*c, a*d
 */
int solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p = max(b * d, a * c);
    int q = max(b * c, a * d);
    return max(p, q);
}