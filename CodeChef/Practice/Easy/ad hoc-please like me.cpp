/*In a far away dystopian world, the measure of the quality of a person’s life is the numbers of likes he gets for an article about their life. For a person to stay alive, 
he has to acquire at least L number of likes before D days pass.
People in this world employ various techniques to increase the number of likes. One of the famous ones is to dis-like and re-like their own article once per day. 
On doing so you can assume that the number of likes for the post increase by a constant factor C.
So if one starts with S likes on Day-1, he would have D2 = S + C * S likes on Day-2, D3 = D2 + D2 * C on Day-3 etc. You are to answer if the person would survive at the end 
of Day-D or not.
Input
First line contains a single positive integer T denoting the number of test cases. The following T lines represent a test case each. Each test case contains 4 space-separated 
integers L, D, S and C.
Output
For each test case, print a single line containing “ALIVE AND KICKING” if the person would live, otherwise print, “DEAD AND ROTTING”.
Constraints
1 <= T <= 1000

1 <= L <= 1000000000

1 <= D <= 1000000000

1 <= S <= 1000000000

1 <= C <= 1000000000*/

int main() {
	ll t,l,d,s,c;
	sl(t);
	while(t--){
		scanf("%lld%lld%lld%lld",&l,&d,&s,&c);
		int f=0;
		while(d--){
			if(s>=l){ f=1; break;}
			s += s*c;
		}
		(f==1)? puts("ALIVE AND KICKING"): puts("DEAD AND ROTTING");
	}
	return 0;
}
