/*There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.

They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?

Input

The first input line has an integer n: the number of books.

The second line has n integers t1,t2,…,tn: the time required to read each book.

Output

Print one integer: the minimum total time.

Constraints
1≤n≤2⋅105
1≤ti≤109
Example

Input:
3
2 8 3

Output:
16

IDEA: if they both start reading at the same time, and we want the min time taken
so that they read all the books the first sort the books in increasing order of time taken
to read it. Now A start to read from the beginning and B from the end.
In this way time taken will be max(total time of each book, 2*maximum time)
2*max time case occurs when book with max time is so larger that A completes reading all
the books and is waiting for B to complete that book, in such case both A and B will take
time = max time book
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, a[maxn];

int main() {
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i], s += a[i];

    sort(a, a + n);
    cout << max(s, (ll)2 * a[n - 1]);
}