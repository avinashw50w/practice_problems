/*Chef had an interesting dream last night. He dreamed of a new revolutionary chicken recipe. When he woke up today he tried very hard to reconstruct the ingredient list. But, he could only remember certain ingredients. To simplify the problem, the ingredient list can be represented by a string of lowercase characters 'a' - 'z'.

Chef can recall some characters of the ingredient list, all the others, he has forgotten. However, he is quite sure that the ingredient list was a palindrome.

You are given the ingredient list Chef dreamed last night. The forgotten characters are represented by a question mark ('?'). Count the number of ways Chef can replace the forgotten characters with characters 'a' - 'z' in such a way that resulting ingredient list is a palindrome.

Input

The first line of input contains a single integer T, the number of test cases. T lines follow, each containing a single non-empty string - the ingredient list as recalled by Chef. Whatever letters he couldn't recall are represented by a '?'.

Output

For each test case, output a single line containing the number of valid ways the ingredient list could be completed. Since the answers can be very large, output each answer modulo 10,000,009.

Example

Input:
5
?
??
ab?
a?c
aba

Output:
26
26
1
0
1*/
typedef long long int ll;
const int mod = (int)1e7 + 9;

ll mpow(ll a, ll b){
	if(b==0) return 1;
	ll x=mpow(a,b/2);
	x=(x*x)%mod;
	if(b&1) x=(x*a)%mod;
	return x;
}

int main() {
	string s;
	int t=inp();
	while(t--){
		cin>>s;
		int n=s.size();
		ll ans = 0, cnt = 0;
		int flag=0, flag2=0;
		rep(i,0,n) { if(s[i] == '?') { flag=1; break; } }
		if(!flag){
			rep(i,0,n/2) if(s[i]!=s[n-i-1]) { flag2=1; break; } 
			
			if(!flag2) { printf("1\n"); continue; }
			else { printf("0\n"); continue; }
		}
		
		flag2=0;
		rep(i,0,n/2){
			if(s[i] == '?' || s[n-i-1] == '?'){
				if(s[i] == '?' && s[n-i-1] == '?') cnt++;
			}
			else if(s[i]!=s[n-i-1]) { flag2=1; break; }
		}
		if(flag2) printf("0\n");
		else {
			if((n&1) && s[n/2] == '?') cnt++;
			printf("%lld\n", mpow(26,cnt));
		}
	}
	return 0;
}
