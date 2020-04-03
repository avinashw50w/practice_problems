/*As the Monk is also taking part in the CodeMonk Series, this week he learned about hashing. Now he wants to practice some problems. 
So he came up with a simple problem. Firstly, he made a hash function F such that:

F(x) = x % 10
Now using this function he wants to hash N integers and count the number of collisions that will occur while hashing the integers.

Input:
The first line contains an integer T, denoting the number of test cases.
The first line of each test case contains an integer N, denoting the number of integers to hash.
The next line contains N space separated integers, denoting the integer X to hash.

Output:
For each test case, print the number of collisions that will occur while hashing the integers.

Constraints:
1 <= T <= 10
1 <= N <= 100
0 <= X <= 105  */

int a[101];
int main() {
	caset{
		int n,x; si(n);
		memset(a,0,sizeof a);
		int cnt = 0;
		rep(i,0,n){
			si(x);
			int f = x%10;
			if(a[f]) cnt++;
			else a[f] = 1; 
		}
		printf("%d\n", cnt);
	}
	return 0;
}
