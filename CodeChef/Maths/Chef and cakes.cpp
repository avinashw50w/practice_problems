/* Chef has bought N robots to transport cakes for a large community wedding. He has assigned unique indices, from 1 to N, to each of them. How it will happen?
Chef arranges the N robots in a row, in the (increasing) order of their indices. Then, he chooses the first M robots and moves them to the end of the queue. Now, Chef goes to the robot at the first position in the row and hands it one cake. He then notes this robot's index (say k) in his notebook, and goes to the kth position in the row. If the robot at this position does not have a cake, he give him one cake, notes his index in his notebook, and continues the same process. If a robot visited by Chef already has a cake with it, then he stops moving and the cake assignment process is stopped.
Chef will be satisfied if all robots have a cake in the end. In order to prepare the kitchen staff for Chef's wrath (or happiness :) ), you must find out if he will be satisfied or not? If not, you have to find out how much robots have a cake, so that the kitchen staff can prepare themselves accordingly.
Input

The first line of input contains a single integer T denoting the number of test cases.
The single line of each test cases contains two space separated integers N and M.
Output

For each of the T test cases, output a single line:
If all N robots have a cake, output "Yes" (without quotes).
Otherwise, output "No" (without quotes) followed by a space and the number of robots which have a cake.
Constraints and Subtasks

1 ≤ T ≤ 10
0 ≤ M < N
Subtask 1: 25 points
1 ≤ N ≤ 10^5
Subtask 3: 75 points
1 ≤ N ≤ 10^9
Example

Input:
3
2 0
2 1
4 2

Output:
No 1
Yes
No 2

Explanation

In test case 1, we have two robots indexed 1 and 2. They are arranged as (1 2). Chef goes to the first robot, gives him a cake, and moves to position 1. In the next step, he sees that robot at this position already has a has cake. So Chef stops moving, and our answer is "No 1".
In test case 2, we again have two robots indexed 1 and 2. Initially, they are arranged as (1 2). Then, Chef moves robot#1 to the end of the row, and thus the arrangement becomes (2 1). Chef goes to the robot at the first position, which is robot#2. Chef hands him a cake, and moves to position 2. Then, he hands a cake to robot#1 at position 2, and moves back to the first position. Since, robot#2 at the first position already ahs a cake, Chef stops moving. All N robots have cakes, so Chef is satisfied, and our answer is "Yes".
In the 3rd test case, we have the following arrangement of robots: (3 4 1 2). Only robots with indices 3 and 1 will get cakes. So our answer is "No 2".  

Solution:
Greatest common divisor.

PROBLEM:
We have a permutation P[0..N−1] with P[x]=M+x for x<N−M and P[x]=x−(N−M) for x≥N−M. Start at x=0 and keep moving from x to P[x]. When visiting some x for the second time, stop. How many different x-s have been visited?

QUICK EXPLANATION:
The number of robots with cakes is N/gcd(N,M), which can be found using Euclid's GCD algorithm.

EXPLANATION:
For permutations, it's a well-known fact that if we start at x=0, we'll stop at x=0 as well - a permutation is made of cycles.

We can just simulate the first subtask. For the second subtask, this is too slow, but we can reduce our problem to a completely different one. The trick is to see that in each step, we're sent from x to x+M and if we see that x≥N afterwards (it really happens iff x≥N−M before this step), then we subtract N to get it back into the range [0,N). Imagine what'd happen if we wrote the permutation on paper and connected its ends - we're always just moving M places to the right on the tape. More formally, after moving to the next robot j times, we have x=(jM)%N.

When will we visit x=0 again, then? It happens for the smallest positive j such that N|jM; which is known to be N/gcd(N,M) (think why). That's the answer to the question "how many robots will have a cake at the end?"; if it's N - if N and M are coprime - we should print "YES".

The greatest common divisor can be computed using Euclid's algorithm in O(logN), which is the time complexity per test case. Memory: O(1). */

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iterator>

using namespace std;
typedef unsigned long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(b-1); k >= (a); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

int main(int argc, char** argv)
{
	int N,T,M, g;
	scanf("%d",&T);
	assert(1<=T && T <= 10);
	while(T--)
	{
		scanf("%d %d",&N,&M);
		assert(0<=M && M<N && N<=1e9);
		g = N/__gcd(N,M);
		if(g==N)
			printf("Yes\n");
		else
			printf("No %d\n",g);
	}
	return 0;
} 