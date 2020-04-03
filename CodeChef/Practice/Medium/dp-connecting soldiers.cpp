/*To protect people from evil, a long and tall wall was constructed a few years ago. But just a wall is not safe, there should also be soldiers on it, always 
keeping vigil. The wall is very long and connects the left and the right towers. There are exactly N spots (numbered 1 to N) on the wall for soldiers. 
The Kth spot is K miles far from the left tower and (N+1-K) miles from the right tower.

Given a permutation of spots P of {1, 2, ..., N}, soldiers occupy the N spots in that order. The P[i]th spot is occupied before the P[i+1]th spot. When a soldier 
occupies a spot, he is connected to his nearest soldier already placed to his left. If there is no soldier to his left, he is connected to the left tower. 
The same is the case with right side. A connection between two spots requires a wire of length equal to the distance between the two.

The realm has already purchased a wire of M miles long from Nokia, possibly the wire will be cut into smaller length wires. As we can observe, the total 
length of the used wire depends on the permutation of the spots P. Help the realm in minimizing the length of the unused wire. If there is not enough wire, 
output -1.

Input

First line contains an integer T (number of test cases, 1 ≤ T ≤ 10 ). Each of the next T lines contains two integers N M, as explained in the problem statement 
(1 ≤ N ≤ 30 , 1 ≤ M ≤ 1000).

Output

For each test case, output the minimum length of the unused wire, or -1 if the the wire is not sufficient.

Example

Input:
4
3 8
3 9
2 4
5 25

Output:
0
0
-1
5


Explanation:
In the 1st case, for example, the permutation P = {2, 1, 3} will use the exact 8 miles wires in total.

In the 2nd case, for example, the permutation P = {1, 3, 2} will use the exact 9 miles wires in total*/
/*DETAILED EXPLANATION
If you haven't solved this problem yet, take some time now and try different cases on paper. eg. Consider N = 4 and try to find all possible sum_of_lengths for different permutations of {1,2,3,4}. You can also take a look at the explanation of sample cases under the problem statement for better understanding.

First lets see an almost bruteforce solution. Consider the array A for N = 9.
Initially A = |, 0, 0, 0, 0, 0, 0, 0, 0, 0, |
and we need to fill the array with 1s in some order. Suppose if we set A[4] = 1,
then A = |, 0, 0, 0, 1, 0, 0, 0, 0, 0, |
and length of wire on left side = 4, length of wire on right side = 6, so we need wire of length 4 + 6 = 10.

Note that if we place the first soldier among N spots at any index, we need wire of length (N+1). Not only that, the first soldier now acts as a barrier between his left and right sides. There will never be a wire which cross this soldier. So we have two independent problems now. If the first solder is placed at index I, then we need (N+1) length wire for this soldier and solve subproblem with (I-1) spots on left side and subproblem with (N-I) spots on right side.
A = |, 0, 0, 0, 1, 0, 0, 0, 0, 0, | is same as solving
A = |, 0, 0, 0, | and |, 0, 0, 0, 0, 0, | 

So we can store all possible values for each N = 1 to 30, and for a given N try all possible positions for the first soldier and mix the answers of the two independent subproblems to get all possible values. As the constraint on N is 30, you can just bruteforce each of these steps.

For an alternate simple approach, see point 2 in the quick explanation section.

SETTER'S SOLUTION
Can be found here

APPROACH
The problem setter used the approach given in the detailed explanation above.

TESTER'S SOLUTION
Can be found here

APPROACH
The problem setter and the tester have independently observed that each of the values between [min, max] can be achieved for some permutation P. This method 
takes only O(N) time. Here is a rough idea of the proof using induction, in tester's words. Just find the min to max lenght of wires required.


max[0] = min[0] = 0
max[n] = max[n-1] + n+1
min[n] = min[n/2] + min[n - n/2 - 1] + n+1
Therefore max[n] = n * (n+3) / 2, min[n] = O(n log n).


Here we assume that for k = 1,2,...,n-1, [ min[k], max[k] ] are all possible,
then we should prove [ min[n], max[n] ] are all possible.
From min[n/2] + min[n - n/2 - 1] + n+1 to max[n/2] + max[n - n/2 - 1] + n+1 are all possible by the assumption. 
If min[a+1]+min[n-a-2] ≤ max[a]+max[n-a-1] for all a=n/2, n/2+1, ..., n-2, then we can show [ min[n], max[n] ] are all possible.
L.H.S. = O(n log n), R.H.S = O(n^2), therefore, this is correct for large n.*/

int mini(int n) {
	if(n == 0) return 0;
	else return n+1 + mini(n/2) + mini(n-n/2-1);
}

int maxx(int n) {
	if(n == 0) return 0;
	else return n+1 + maxx(n-1);  //  it is equal to (n+1)+n+(n-1)+(n-2)+....+2 = (n+1).(n+2)/2 - 1 = (n.(n+3))/2
}

int solve(int n, int m) {
	int l = mini(n);
	int r = maxx(n);
	if(l<=m and m<=r) return 0;
	else if(m<l) return -1;
	else if(m>r) return m-r;
}

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;

	caset{

		cin>>n>>m;

		cout << solve(n,m) << endl;
	}
	return 0;
}
