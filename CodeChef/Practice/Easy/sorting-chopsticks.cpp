/*Actually, the two sticks in a pair of chopsticks need not be of the same length. A pair of sticks can be used to eat as long as the difference in their length is at most D. The Chef has N sticks in which the ith stick is L[i] units long. A stick can't be part of more than one pair of chopsticks. Help the Chef in pairing up the sticks to form the maximum number of usable pairs of chopsticks.

Input

The first line contains two space-separated integers N and D. The next N lines contain one integer each, the ith line giving the value of L[i].

Output

Output a single line containing the maximum number of pairs of chopsticks the Chef can form.

Constraints

1 ≤ N ≤ 100,000 (10 5 )
0 ≤ D ≤ 1,000,000,000 (10 9 )
1 ≤ L[i] ≤ 1,000,000,000 (10 9 ) for all integers i from 1 to N
Example

Input:

5 2
1
3
3
9
4

Output:
2
Explanation

The 5 sticks have lengths 1, 3, 3, 9 and 4 respectively. The maximum allowed difference in the lengths of two sticks forming a pair is at most 2.
It is clear that the 4th stick (length 9) cannot be used with any other stick.
The remaining 4 sticks can can be paired as (1st and 3rd) and (2nd and 5th) to form 2 pairs of usable chopsticks.*/

int main() {
	int n,d;
	n=inp(); d=inp();
	int a[n+1];
	a[0]=inp();
	int mx, mn;
	mx = mn = a[0];
	rep(i,1,n) {
		a[i]=inp();
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}

	if(mx-mn <= d) { printf("%d\n", n>>1); return 0; }

	sort(a,a+n);
	int ans = 0, i = 1;
	while(i<n){
		if(a[i]-a[i-1] <= d) { ans++; i+=2; }
		else i++;
	}
	printf("%d\n", ans);
	return 0;
}
