/*Our monk, while taking a stroll in the park, stumped upon a polynomial ( A X2 + B X +C ) lying on the ground. The polynomial was dying! Being considerate, our monk tried to talk and revive the polynomial. The polynomial said: 
I have served my purpose, and shall not live anymore. Please fulfill my dying wish. Find me the least non-negative integer Xo, that shall make my value atleast K i.e., A Xo2 + B Xo + C >= K . 
Help our Monk fulfill the polynomial's dying wish!


Input: 
The first line contains an integer T. T test cases follow. 
Each test case consists of four space-separated integers A, B, C and K. 

Output:
For each test case, output the answer in a new line.

Constraints:
1 ≤ T ≤ 105
1 ≤ A,B,C ≤ 105
1 ≤ K ≤ 1010    */


ll a,b,c,k;

int bsearch(int l,int r){
	ll x,ans = 10000000;
	while(l<=r){
		x = l + (r-l)/2; 
		ll t = a*x*x+b*x+c;
		if(t >= k) {
			ans = min(ans,x);
			r = x-1;
		}
		else l = x+1;
	}
	return ans;
}
int main() {
	caset{
		sl(a);sl(b);sl(c);sl(k);
		printf("%lld\n", bsearch(0,100000));
	}
	return 0;
}
