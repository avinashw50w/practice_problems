/* Chef is working with lines on a 2-D plane.
He knows that every line on a plane can be clearly defined by three coefficients A, B and C: any point (x, y) lies on the line if and only if A * x + B * y + C = 0.
Let's call a set of lines to be perfect if there does not exist a point that belongs to two or more distinct lines of the set.
He has a set of lines on a plane and he wants to find out the size of the largest perfect subset of this set.
Input

The first line of input contains one integers T denoting the number of test cases.
Each test case consists of one integer N denoting number of lines.
Next N lines contain 3 space-separated integers each denoting coefficients A, B and C respectively.
Output

For each test case output the cardinality of the largest perfect subset in a single line.
Constraints

1 ≤ N ≤ Nmax
Sum over all N for all test cases ≤ NSmax
|A|, |B|, |C| ≤ 109
For a line with coefficients A, B and C either A or B is not zero.
Subtasks

Subtask #1 [35 points]: Nmax = 5000, NSmax = 50000
Subtask #2 [65 points]: Nmax = NSmax = 105
Example

Input:
1
5
1 0 0
1 2 3
3 4 5
30 40 0
30 40 50

Output:
2
Explanation

Lines 3*x + 4*y + 5 = 0 and 30*x + 40*y + 0 = 0 form a biggest perfect subset.

solution:
PREREQUISITES:
Cartesian coordinates, parallel lines, sets, GCD, Euclidean algorithm, sorting

PROBLEM:
A set of lines is called perfect if there's no point that belongs to two distinct lines of the set.

Given a set of N lines, each determined by three coefficients (A,B,C) (representing the line Ax+By+C=0), what is the size of the largest perfect subset?

QUICK EXPLANATION:
The answer is simply the largest set of distinct lines that are all parallel to one another. To get the answer, group the lines according to slope, being careful to not count coinciding lines twice. (e.g. x+y+1=0 coincides with 2x+2y+2=0 so should only be counted once.) The answer is the size of the largest group.

One way to group the lines is to add them to a set data structure. Another is to sort them according to slope, so that lines with the same slope are found consecutively.

EXPLANATION:
A set containing just one line is clearly perfect, so let's investigate perfect sets of size at least two. Let a and b be two lines in a perfect set. Since a and b must not intersect (and definitely must not coincide), then they must be parallel. In other words, they must have the same slope. Since this argument applies to any pair of lines in the perfect set, we can say that a perfect set is just a set of distinct lines all having a common slope.

Our goal now is to find the largest perfect set. Naturally, we want to group the lines according to slope, and take the largest group as the answer. In fact, this is basically the algorithm to solve this problem! However, there are at least two problems that might come up when implementing this:

First, we must be able to represent the slope exactly, and not just a floating point number, otherwise you risk getting wrong answer due to bad rounding. (Remember that many numbers cannot be represented exactly in floating point.)
Second, we must be able to detect whether two lines coincide, because we should only count coinciding lines once.
We'll deal with these problems one by one.

Representing the slope
First, note that it's actually possible to get accepted while using floating point slopes (especially if the data isn't strong enough or the bounds of the problem prevents rounding errors from being a problem), but it's still important to know an error-free way to represent slopes, in other words, a way that can be shown to always work. Also, representing a slope exactly has many applications even outside of this problem. So how do we represent the slope of a line exactly?

Representation 1
Well, one way to represent the slope exactly is to simply represent it as an exact fraction. For example, the slope of Ax+By+C=0 is −A/B. But we must be able to detect the same fractions! (For example, 1/2=2/4=3/6.) One way to do it is to reduce the fraction to lowest terms, by dividing the numerator and denominator by the greatest common divisor (gcd). This works because rational numbers have a unique representation in lowest terms.

We need to represent negative slopes as well! To make the "lowest term representation" unique, simply ensure that the denominator is always positive. Another problem that will arise is how to represent the slope of vertical lines. Their slope can't be represented by a rational number (because it's "infinite"). However, since there is a unique slope for vertical lines, we can simply use a unique object to represent the "vertical slope". (or just handle vertical lines separately)

Representation 2
There's actually a way to represent the slopes without needing any special handling for the vertical slope. Instead of representing the slope of the line as a rational number, we represent it as the vector pointing to the direction of the line. Remember that a vector is an ordered pair ⟨x,y⟩, which represents the direction pointing from (0,0) towards (x,y). (In a vector, the distance between these points are also important, but since we're only talking about the "direction" of the line, it doesn't matter for our purposes.)

What is the direction vector of the line Ax+By+C=0? Suppose (x1,y1) and (x2,y2) are points on this line. Then ⟨xd,yd⟩=⟨x2−x1,y2−y1⟩ is one possible direction vector. But these points satisfy the equation of the line, so:
Ax1+By1+C=0
Ax2+By2+C=0
Subtracting these two, we get:
A(x2−x1)+B(y2−y1)=0
or
Axd+Byd=0
But one solution to this equation is simply xd=B and yd=−A, thus ⟨B,−A⟩ is one direction vector for the line Ax+By+C=0!

But in order to group our lines according to slope, we must again be able to detect vectors representing the same direction. Similarly to rational numbers, we must find some sort of "normal form" that we can reduce our direction vectors to. Note that we also consider opposing vectors as representing the same "direction", e.g. ⟨x,y⟩ and ⟨−x,−y⟩.

One way to define such a normal form is the following. Let's say a vector ⟨x,y⟩ with integer coordinates is in normal form if and only if x and y are relatively prime and the polar angle of (x,y) is less than 180 degrees. The reader is invited to prove that every direction vector has a unique normal form.

Finally, to convert ⟨x,y⟩ to normal form, simply divide both coordinates by gcd(x,y), and then negate both if y is negative, or y=0 and x is negative.

Using vectors instead of slopes, we don't have to worry about "infinite" slopes any more!

Detecting coinciding lines
Next, what about detecting coinciding lines? Note that coinciding lines necessarily have the same slope, so we can simply look at lines with the same slope, and find among those the lines that overlap.

Note that two lines overlap if and only if their equations are the same, up to a nonzero multiplicative constant. For example, the following lines all coincide with one another:
4x+6y+1=0
8x+12y+2=0
44x+66y+22=0
−44x−66y−22=0
However, these lines do not coincide with the line 4x+6y+2=0 or 4x+6y−1=0.

In this case, we can simply try to reduce the equations into some sort of "normal form" (as in the previous section), in such a way that each equation of a line has a unique normal form. Here's one way: Let's say the equation Ax+By+C=0 is in normal form if A, B and C are relatively prime, and one of the following conditions hold:

C>0
C=0 and B>0
C=0, B=0 and A>0
The idea behind this is actually just an extension of our "normal form" of direction vectors in the previous section, because ⟨x,y⟩ is in normal form if x and y are relatively prime and one of the following conditions is satisfied:

y>0
y=0 and x>0
Thus, we can just reduce all our equations to their normal forms, and this way, two lines coincide if and only if their equations are equal!

Solution
Armed with the above techniques, the solution is now easy. First, group the lines according to their slopes (or normal forms of their direction vectors). Then, for each group, compute the normal forms of their equations, and remove duplicates. Finally, the answer is simply the largest remaining group!

The following is a Python implementation which solves a single test case:

from fractions import gcd
from collections import defaultdict
s = defaultdict(set)
for i in xrange(input()):
    a, b, c = map(int, raw_input().strip().split())
    g = gcd(a, b)
    h = gcd(g, c)
    s[a/g, b/g].add((a/h, b/h, c/h))
print max(map(len, s.values()))
Since Python's gcd(a,b) is guaranteed to have the same sign as b, dividing by the gcd will already guarantee normality (as we've defined it).

The time complexity of this algorithm is O(NlogN) if one uses balanced tree sets.

Alternatively, you can just sort them according to their normal forms, so parallel lines and coinciding lines are found consecutively. This runs in O(NlogN) time also.

Time Complexity:
O(NlogN) or expected O(N)   */

#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<pair<int, int>, int> ma;
set<pair<pair<int, int>, int> > S;
int n, a, b, c, ret;

int gcd (int a, int b) {
    if (a == 0 || b == 0)
        return max(a, b);
    return __gcd(a, b);
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a < 0 || (a == 0 && b < 0)) {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        int g = gcd(gcd(abs(a), abs(b)), abs(c));
        a /= g;
        b /= g;
        c /= g;
        pair<pair<int, int>, int> li = make_pair(make_pair(a, b), c);
        if (S.find(li) == S.end()) {
            S.insert(li);
            g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;
            ret = max(ret, ++ma[make_pair(a, b)]);
        }
    }
    cout << ret << endl;
    return 0;
}

