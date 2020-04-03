/* Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses. He, along with his friends, goes to his
 stable during the weekends to watch a few of these horses race. Chef wants his friends to enjoy the race and so he wants the race to be close. 
 This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less.
There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such 
that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and 
report the minimum difference that is possible between 2 horses in the race.
Input:

First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].
Output:

For each test case, output a single line containing the minimum difference that is possible.
Constraints:

1 = T = 10
2 = N = 5000
1 = S[i] = 1000000000

Example:

Input:
1
5
4 9 1 32 13

Output:
3

Explanation: The minimum difference can be achieved if we pick horses with skills 1 and 4 for the race.*/

#include <iostream>
#include <algorithm>
#define oo 0x3f3f3f3f
using namespace std;
#define ll long long int
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#if defined(WIN64)
#define gc getchar()
#else
#define gc getchar_unlocked()
#endif
inline ll inp(){
	ll n = 0;
	register int c = gc;
	while(c==' ' or c=='\n') c=gc;
	while(c>='0' and c<='9'){
		n = (n<<3) + (n<<1) + c-48;
		c=gc;
	}
	return n;
} 
 
ll a[5000+5];
int main(){
	int t=inp();
	while(t--){
		int n=inp();
		rep(i,0,n) a[i] = inp();
		sort(a,a+n);
		ll diff = 0 , min_diff = oo;
		rep(i,0,n-1){
			diff = a[i+1]-a[i];
			min_diff = min(min_diff,diff);
		}
		cout<<min_diff<<endl;
	}
} 
