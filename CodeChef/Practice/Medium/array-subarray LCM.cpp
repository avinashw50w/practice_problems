/*
	               _            .                                 .x+=:.
	              u            @88>                              z`    ^%    .uef^"
	             88Nu.   u.    %8P      u.    u.                    .   <k :d88E
	      u     '88888.o888c    .     x@88k u@88c.       u        .@8Ned8" `888E
	   us888u.   ^8888  8888  .@88u  ^"8888""8888"    us888u.   .@^%8888"   888E .z8k
	.@88 "8888"   8888  8888 ''888E`   8888  888R  .@88 "8888" x88:  `)8b.  888E~?888L
	9888  9888    8888  8888   888E    8888  888R  9888  9888  8888N=*8888  888E  888E
	9888  9888    8888  8888   888E    8888  888R  9888  9888   %8"    R88  888E  888E
	9888  9888   .8888b.888P   888E    8888  888R  9888  9888    @8Wou 9%   888E  888E
	9888  9888    ^Y8888*""    888&   "*88*" 8888" 9888  9888  .888888P`    888E  888E
	"888*""888"     `Y"        R888"    ""   'Y"   "888*""888" `   ^"F     m888N= 888>
	 ^Y"   ^Y'                  ""                  ^Y"   ^Y'               `Y"   888
	                                                                             J88"
	                                                                             @%
	                                                                           :"
*/
/*Given an array A1,A2...AN, you have to print the size of the largest contiguous subarray such that
LCM of all integers in that subarray is equal to the product of all integers in that subarray.

Formally,
For a subarray Ai,Ai+1...Aj where 1 ≤ i < j ≤ N to be valid: LCM(Ai,Ai+1...Aj) should be equal to Ai*Ai+1*...*Aj. You have to print the size of 
the largest valid subarray.

If no subarray satisfies output -1.

Note:A single element is not considered a subarray according to definition in this problem.

Input
First line contains T, the number of testcases. Each testcase consists of N in one line followed by N integers in next line.

Output
For each testcase, print the required answer in one line.

Constraints
1 ≤ T ≤ 50
2 ≤ N ≤ 105
1 ≤ Ai ≤ 106
Example
Input:
3
2
7 2
4
2 2 3 4
3
2 2 4

Output:
2
2
-1
Explanation
Example case 1.LCM(2,7)=2*7. Therefore, subarray A1 to A2 satisfies.

Example case 2.The subarrays A2 to A3 and A3 to A4 are the maximum size possible.

Example case 3.No subarray will satisfy.*/
/* lcm of the subarray will only be equal to the product of the subarray only when none of the element of the subarray have any common factors. 

eg. [6, 15, 10] will have factors [(2,3), (3,5), (2,5)] */

#define oo 0x3f3f3f3f
#define eps 1e-9
const int mod = 1000000007;
const int MAXN = 1000000+5;

int p[MAXN], pos[MAXN];
int a[100000+1], dp[100000+1];

void seive() {
	ll i, j;
	for(i=2; i*i<MAXN;++i){
		if(!p[i]){
			p[i] = i;
			for(j=i*i; j<MAXN; j+=i) p[j] = i;
		}
	}
	for(; i<MAXN; ++i) p[i] = i;
}

vector<int> factorize(int n) {
	vector<int> ret;
	while(n>1){
		ret.push_back(p[n]);
		n /= p[n]; 
	}
	return ret;
}

// finds the largest index where any of the factors of a[idx] exists
int cal(int idx) {
	vector<int> factors = factorize(a[idx]);
	int ret = 0;

	rep(i, 0, factors.size()) {
		ret = max(ret, pos[factors[i]]);
		pos[factors[i]] = idx;
	}
	return ret;
}

int main() {
	BOOST;
	seive();
	caset{
		mset(pos, 0);
		int n; cin>>n;
		
		dp[0] = 0;
		
		rep(i,1,n+1) cin>>a[i];
		
		rep(i,1,n+1){
			dp[i] = min(dp[i-1]+1, i-cal(i)); 
		}
		
		int ans =  *max_element(dp,dp+n+1); 
		if(ans > 1) cout << ans << "\n";
		else cout << -1 << "\n";
	}

	return 0;
}
