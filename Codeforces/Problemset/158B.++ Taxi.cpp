/*After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate 
his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to 
Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. 
What minimum number of cars will the children need if all members of each group should ride in the 
same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. 
The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). 
The integers are separated by a space, si is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

Examples
inputCopy
5
1 2 4 3 3
outputCopy
4*/

/* Explanation: count freq of 4,3,2 and 1. Add count of 4 to ans, Pair 3 and 1, and add it, 
add the taxi required to accomodate remaing people in group of 2 and 1. */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, A[5] = {}; cin>>n;
	while(cin>>n) A[n]++;
	A[1] = max(A[1]-A[3], 0);
	cout << (A[4] + A[3] + (A[1] + 2*A[2] + 3)/4) << endl;
}