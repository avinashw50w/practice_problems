/*oday is chef's friend's birthday. He wants to give a gift to his friend. So he was desperately searching for some 
gift here and there.Fortunately, he found an array a of size n lying around. The array contains positive integers. 
Chef's friend likes even numbers very much. So for the gift, chef will choose a 
consecutive non-empty segment of the array. The segment should contain exactly k even integers. Though it can have any number 
of odd integers.He will then pick that segment and gift it to his friend.

But there is a problem. It might not be always possible for the chef to choose such a segment. Please tell whether it is possible 
for chef to select some gift or not?

Input

First line of the input contains a single integer T denoting number of test cases. 
For each test case, first line contains two space separated integers n, k. 
Next line contains n space separated integers denoting content of array a. 
It is also guaranteed that all the numbers in the array a are distinct.

Output

For each test case, print a single line containing "YES" or "NO" (without quotes) corresponding to the situation.

Constraints

1 ≤ T ≤ 10
1 ≤ n ≤ 50
0 ≤ k ≤ n
1 ≤ a i ≤ 100*/

int main() {
	int n,k,a;
	int t=inp();
	while(t--){
		n=inp(); k=inp();
		int cnt = 0;
		rep(i,0,n){
			a=inp();
			if(!(a&1)) cnt++;
		}
		if(k==0 && cnt==n) cnt=-1;
		(cnt>=k)? puts("YES"): puts("NO");
	}
	return 0;
}