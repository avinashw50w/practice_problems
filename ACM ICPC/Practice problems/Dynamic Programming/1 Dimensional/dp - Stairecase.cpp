/*Jack and Jill are sitting at the bottom of their tree house and debating in how many ways then can jump up the stairs on the tree and reach the tree house .
Because Jack is older than Jill, He can jump one, two or three stairs in one step while Jill can jump just one or two stairs in one step .

For example, Jack can cover the 8 stairs by jumping (2,2,2,2) or (2,1,2,1,2) or other suitable combinations of steps. Could you help them to find the total 
number of possibilities they have to reach the top. Note that the order of the steps is important here, for example, (3,1) is treated distinct from (1,3) 
i. e. jumping 3 stairs in first step followed by jumping 1 stair in other step is different from jumping one stair in first step and 3 stairs in second step. 
Write a program to help them out

Input: The number of stairs to be covered.

Output: Number of total ways to reach to the top for Jack in the first line and Number of total ways to reach at the top for Jill in the second line. 
(For other cases, output is ERROR)*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin>>N;

	if(N < 0) { cout << "ERROR\n"; return 0; }
	 
	int jack[N+1], jill[N+1];

	memset(jack,0,sizeof(jack));
	memset(jill, 0, sizeof(jill));

	jack[1] = 1;
	jack[2] = 2;
	jack[3] = 4;

	jill[1] = 1;
	jill[2] = 2;

	for(int i=4;i<=N;++i) jack[i] = jack[i-1] + jack[i-2] + jack[i-3];

	for(int i=3;i<=N;++i) jill[i] = jill[i-1] + jill[i-2];

	cout << "Jack-" << jack[N] << endl;
	cout << "Jill-" << jill[N] << endl;
}