/* What is the maximum number of squares of size 2x2 that can be fit in a right angled isosceles triangle of base B.

One side of the square must be parallel to the base of the isosceles triangle.

Base is the shortest side of the triangle
Input

First line contains T, the number of test cases.

Each of the following T lines contains 1 integer B.
Output

Output exactly T lines, each line containing the required answer.
Constraints

1 = T = 103

1 = B = 104
Sample Input

11
1
2
3
4
5
6
7
8
9
10
11
Sample Output 

0
0
0
1
1
3
3
6
6
10
10

explanation : First consider the right angle triangle ?XYZ, where YZ is the base of triangle. Suppose length of the base is B. If we consider the 
position of first square with the vertex YY, we will have (B/2-1) squares in the base, and we will be left with another isosceles right angle triangle 
having base length (B-2).


Let f(B) = Number of squares which can be fitted in triangle having base length B.


f(B)=(B/2-1)+f(B-2)
The given time limit is sufficient even if we calculate f(Bf(B) using the given recursion, and use memoization. Later we can answer each query in O(1)O(1) time.
We can do it for even and odd numbers separately with the base case f(1)=f(2)=f(3)=0.*/

#include <iostream>
using namespace std;
int f[10101];
void gen(){
	f[1]=f[2]=f[3]=0;
	for(int i=4;i<10101;i++)
	f[i] = (i/2 - 1) + f[i-2];
}
int main(){
	int t;cin>>t;
	gen();
	while(t--){
		int b;cin>>b;
		cout<< f[b] << endl;
	}
}
