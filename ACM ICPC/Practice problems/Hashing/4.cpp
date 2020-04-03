/*Monk has magical powers, by which he can compare any part of the strings and figure out if they're equal. His magical powers are faster 
than a super computer even. So, to prove his worth, he's given a string and he has to answer multiple queries based on the string.

Every query will have four integers - L1, R1, L2, R2. The first two integers denoting String [ L1, R1 ] (including both L1 and R1) 
denoting the first substring, the next two integers denoting the second substring String [ L2, R2 ] (including both L2 and R2).

For every query, you've to answer in Yes or No whether the two substrings are equal or not. Easy enough?

Input:
The first line contains a string, S.
Then, an integer Q denoting the number of queries in the next line.
Then, for every query, there will be 4 integers L1 R1 L2 R2, denoting the substring S[L1 R1] and S[L2 R2].

Output:
For each query output "Yes" if the two substrings are same , else output "No".

Constraints:
1 ≤ |S| ≤ 105
1 ≤ Q ≤ 105
1 ≤ L1 ≤ R1 ≤ |S|
1 ≤ L2 ≤ R2 ≤ |S|
The string will contain only lowercase letters.  */

/*Difficulty : Medium

Pre-Requisites : Hashing , Rolling Hash

Problem : Given a string S , many queries are given of the form L1 R1 L2 R2 which ask whether the substring S[L1...R1] and S[L2...R2] 
are same or not ?

Explanation :
The naive solution for this problem is to check in linear time whether the two given substrings are same or not which gives the time 
complexity of O(Q*N) which will lead to TLE.

What we can use to solve this problem is Hashing , that is if we have a way to get hash of any substring in O(1) time complexity then we 
can just compare the Hash of the two substrings whether they are equal or not . One type of hash function which we can use is of the from , 
for string S of length N the hash H(S) is given by , H(S[1...N]) = ( S[1] * BN-1 + ... + S[N-2] * B2 + S[N-1] * B+ S[N] ) % M

Now , if the Hash function is of the above type then we can see that for any random substring S[L...R] we can calculate its as , 
H(S[L...R]) = ( S[L] * BR-1 + ... + S[R-2] * B2 + S[R-1] * B + S[R] ) % M

We can see that we can change the above equation into the following form ,

H(S[L...R]) = H(S[1...R]) - H(S[1...L-1]) * B(R-L+1)   //  S[1]*BR-1 + S[2]*BR-2  ..... - S[1]*BL-2 - S[2]*BL-3 -  ......  => S[1]*(BR-1 - BL-2) => R-1 - (L-2) = R-L+1 

Here , B and M and depends on the way you implement the Hash function.

Now , the problem with hashing is that a perfect hash function is not possible to be made so collisions can occur and it can give us a 
false match.So , to solve this problem we can calculate two hashes for a substring using different B and M , and when matching two substrings 
both hashes of two substrings should be same . This reduces chance of a false match. Thus , we achieve the time complexity of O(N + Q).*/

const int MAXN = 100000;
const int mod1 = 10000003;
const int mod2 = 10000019;
#define b1 13
#define b2 17

ll h1[MAXN+5], h2[MAXN+5];
ll p1[MAXN+5], p2[MAXN+5];
int n;
string s;
int l1,r1,l2,r2,q;

void prec(){
	n = s.size();
	p1[0] = p2[0] = 1;
	for(int i=1;i<=n;++i){
		p1[i] = (b1*p1[i-1])%mod1;
		p2[i] = (b2*p2[i-1])%mod2;

		h1[i] = (b1*h1[i-1] + s[i-1]-'a' + 1)%mod1;
		h2[i] = (b2*h2[i-1] + s[i-1]-'a' + 1)%mod2;
	}
}

pair<ll,ll> getHashKey(int l, int r){
	int len = r-l+1;

	int ret1 = (h1[r] - (h1[l-1]*p1[len])%mod1 + mod1)%mod1;
	int ret2 = (h2[r] - (h2[l-1]*p2[len])%mod2 + mod2)%mod2;

	return make_pair(ret1,ret2);
}

int main() {
	cin>>s;
	
	prec();
	
	si(q);
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(r1-l1 != r2-l2){
			printf("No\n");
			continue;
		}
		pair<ll,ll> a,b;

		a = getHashKey(l1,r1);
		b = getHashKey(l2,r2);

		if(a == b) {
			printf("Yes\n");
		} 
		else printf("No\n");
	}
	return 0;
}
