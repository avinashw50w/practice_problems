/*Given a string of digits S, insert a minimum number of opening and closing parentheses into it such that the resulting string is balanced and each digit d is inside exactly d pairs of matching parentheses.

Let the nesting of two parentheses within a string be the substring that occurs strictly between them. An opening parenthesis and a closing parenthesis that is further to its right are said to match if their nesting is empty, or if every parenthesis in their nesting matches with another parenthesis in their nesting. The nesting depth of a position p is the number of pairs of matching parentheses m such that p is included in the nesting of m.

For example, in the following strings, all digits match their nesting depth: 0((2)1), (((3))1(2)), ((((4)))), ((2))((2))(1). The first three strings have minimum length among those that have the same digits in the same order, but the last one does not since ((22)1) also has the digits 221 and is shorter.

Given a string of digits S, find another string S', comprised of parentheses and digits, such that:
all parentheses in S' match some other parenthesis,
removing any and all parentheses from S' results in S,
each digit in S' is equal to its nesting depth, and
S' is of minimum length.

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line represents a test case and contains only the string S.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the string S' defined above.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ length of S ≤ 100.

Input 
4
0000
101
111000
1

Output
Case #1: 0000
Case #2: (1)0(1)
Case #3: (111)000
Case #4: (1)*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

void solve() {
    string s, res = "";
    cin >> s;
    int count = 0;
    for (char c: s) {
        int d = c - '0';
        while (count < d) res += '(', count++;
        while (count > d) res += ')', count--;
        res += c;
    }

    while (count) res += ')', count--;

    printf("%s\n", res.c_str());
}

int main() {
    int t, caset = 0; cin >> t;
    while (t--) {
        printf("Case #%d: ", ++caset);
        solve();
    }
}