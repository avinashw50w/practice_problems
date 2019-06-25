/*


 Problem Statement for LCMGCD


Problem Statement
    	
You are given the int[] x: a list containing n integers. Each element of x is a positive integer of the form 2^a * 3^b, where a and b are some nonnegative integers. The elements of x are not necessarily distinct.

You are going to perform n-1 operations. Each operation will consist of the following steps:

Choose two distinct indices into your list. Let X and Y be the numbers at those indices. Remove both of them from the list. (Note that X and Y are allowed to have the same value.)
Compute one of two possible values: either the greatest common divisor (gcd) of X and Y, or the least common multiple (lcm) of X and Y.
Append the computed value to your list.
Obviously, after n-1 operations you will be left with a single integer.
In addition to x you are given the int t. You would like to know whether it is possible to perform the sequence of operations on x in such a way that the final integer will be t. If it is possible, return "Possible", otherwise return "Impossible".

 
Definition
    	
Class:	LCMGCD
Method:	isPossible
Parameters:	int[], int
Returns:	String
Method signature:	String isPossible(int[] x, int t)
(be sure your method is public)
    
 
Constraints
-	x will contain between 1 and 50 elements, inclusive.
-	Each element of x will be between 1 and 10^9, inclusive.
-	t will be between 1 and 10^9, inclusive.
-	t and each element of x will be of the form 2^i*3^j for some nonnegative i,j.
 
Examples
0)	
    	
{2,3}
6
Returns: "Possible"
We can take the lcm to reach the goal.
1)	
    	
{4,9}
6
Returns: "Impossible"
We have lcm(4,9) = 36 and gcd(4,9) = 1. It's impossible to get 6.
2)	
    	
{6,12,24,18,36,72,54,108,216}
36
Returns: "Possible"
3)	
    	
{6,27,81,729}
6
Returns: "Impossible"
 */

/*We should consider the prime factorizations of all the numbers in the input. It is interesting that all the numbers in the input will be 
of the form 2a⋅3b2a⋅3b for non-negative a,ba,b, this will be their prime factorization. Let's represent each number by the two exponents 
aa and bb used for 2 and 3 respectively: (a,b)(a,b).

When taking the GCD of two numbers, it is the same as taking the prime factorizations and calculating the minimum exponent for each of 
the prime factors. So we have 2 numbers: 2a⋅3b2a⋅3b and 2c⋅3d2c⋅3d, the gcd will be equal to : 2min(a,c)⋅3min(b,d)2min(a,c)⋅3min(b,d). 
The LCM works in a similar way, but it uses the maximum exponent: 2max(a,c)⋅3max(b,d)2max(a,c)⋅3max(b,d). So we can convert the problem 
into something about taking minimums and maximums:

We are given a list of pairs in the form (a,b)(a,b), in each step we take two of the pairs (a,b)(a,b) and (c,d)(c,d) and remove them 
from the list and add either (min(a,c),min(b,d))(min(a,c),min(b,d)) or (max(a,c),max(b,d))(max(a,c),max(b,d)). After n−1n-1 steps, 
only one pair will remain, is it possible to make this last pair equal to (pa,pb)(pa,pb)?

The specific numbers don't matter
Let's focus on the first element of all the pairs. We have a list of integers and want to reach a integer papa by applying minimum or 
maximum operations to the elements of the list. In the list, there might be a variety of numbers, but we don't need to worry too much 
about which numbers they are, in reality we only care about their relative order in relation to papa: We can treat all numbers smaller 
than papa as effectively the same number. The same happens with all numbers larger than papa. At the end of the day, if we replace papa 
with 1, and all numbers smaller than papa with 0 and all numbers larger than papa with 2, then we can still use the same chain of 
minimum/maximum operations to reach the objective. The same happens with the second element of the pair. To reach pbpb we only need 
to know which numbers are smaller, larger or equal.

So this converts the problem to a simpler one. We have a list of pairs (a,b)(a,b) where 0≤a,b≤20≤a,b≤2. In each step, we take two 
pairs (a,b)(a,b) and (c,d)(c,d) and replace them with either the minimum or the maximum. We want the final pair to be (1,1)(1,1).*/

 // get the exponents of 2 and 3 in the prime factorization of x:
tuple<int,int> get32(int x)
{
    int r2 = 0, r3 = 0;
    while (x % 2 == 0) {
        r2++;
        x /= 2;
    }
    while (x % 3 == 0) {
        r3++;
        x /= 3;
    }
    return make_tuple(r2,r3);
}
 
set<vector<int> > seen; // a set of all the vectors p we have reached in the DFS:
 
void try_it(vector<int> & p) // DFS
{
    if (seen.count(p) == 0) {
        seen.insert(p);
        // pick two kinds of pairs:
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                if (p[a*3 + b] == 0) {
                    continue;
                }
                for (int c = 0; c < 3; c++) {
                    for (int d = 0; d < 3; d++) {
                        if (p[c*3 + d] == 0) {
                            continue;
                        }
                        for (int i = 0; i < 2; i++) {
                            // i = 0: minimize
                            // i = 1: maximize
                            vector<int> q = p;
                            q[a*3 + b]--;
                            q[c*3 + d]--;
                            if (q[a*3 + b] < 0) {
                                // if there are no more such pairs then continue
                                continue;
                            }
                            int s, t;
                            if (i == 0) {
                                s = std::min(a,c);
                                t = std::min(b,d);
                            } else {
                                s = std::max(a,c);
                                t = std::max(b,d);
                            }    
                            // increment the count of the new pair:
                            q[s*3 + t]++;
                            if (seen.count(q) == 0) {
                                try_it(q); // continue the search now with q
                            }
                        }
                    }
                }
            }
        }
    }
}
 
string isPossible(vector<int> x, int t)
{
    int w2,w3;
    tie(w2,w3) = get32(t);
    vector<int> p(9);
    for (int y: x) {
        int p2,p3;
        tie(p2,p3) = get32(y);
        // assign 0, 1 or 2, depending if the exponent is less, equal or more:
        if (p2 == w2) {
            p2 = 1;
        } else if (p2 > w2) {
            p2 = 2;
        } else {
            p2 = 0;
        }
        if (p3 == w3) {
            p3 = 1;
        } else if (p3 > w3) {
            p3 = 2;
        } else {
            p3 = 0;
        }
        if (p2 == 1 && p3 == 1) {
            // for (1,1) we need the accurate count
            p[ p2 * 3 + p3 ]++;
        } else {
            // for other pairs, we only need to know if there is at least one of them
            p[ p2 * 3 + p3 ] = 1;
        }
    }
    try_it(p);
     
    vector<int> want(9, 0);
    want[1*3 + 1] = 1;
     
    // perform the search.
    if ( seen.count(want) ) {
        return "Possible";
    } else {
        return "Impossible";
    }
}