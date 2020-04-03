/*The DNA of the Albocede alien species is made up of 4 types of nucleotides: a, b, c, and d. Different Albocedes may have different sequences of these nucleotides, 
but any Albocede's DNA sequence obeys all of the following rules:
It contains at least one copy of each of a, b, c, and d.
All as come before all bs, which come before all cs, which come before all ds.
There are exactly as many 'a's as 'c's.
There are exactly as many 'b's as 'd's.
For example, abcd and aabbbccddd are valid Albocede DNA sequences. acbd, abc, and abbccd are not.

The Albocede-n is an evolved species of Albocede. The DNA sequence of an Albocede-n consists of one or more valid Albocede DNA sequences, concatenated together 
end-to-end. For example, abcd and aaabcccdaabbbccdddabcd are valid Albocede-n DNA sequences. (Observe that a valid Albocede-n DNA sequence is not necessarily 
also a valid Albocede DNA sequence.)

From one of your alien expeditions, you retrieved an interesting sequence of DNA made up of only as, bs, cs, and ds. You are interested in how many of the 
different subsequences of that sequence would be valid Albocede-n DNA sequences. (Even if multiple different selections of nucleotides from the sequence produce 
the same valid subsequence, they still all count as distinct subsequences.) Since the result may be very large, please find it modulo 1000000007 (109 + 7).

Input

The first line of the input gives the number of test cases, T. Each of the next T lines contains a string S that consists only of the characters a, b, c, and d.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the output of the xth test case.

Limits

1 ≤ T ≤ 20.
Small dataset

1 ≤ length of S ≤ 50.
Large dataset

1 ≤ length of S ≤ 500.
Sample


Input 
 	
Output 
 
5
abcd
aaaabcd
aaaabbccd
abcdabcdaabccd
b
Case #1: 1
Case #2: 4
Case #3: 28
Case #4: 71
Case #5: 0
*/

#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

string cur;
int dp[502][502][502];
int dp2[502][502][502];

const int MOD = 1e9 + 7;

int rec(int, int ,int);

int rec2(int idx, int A, int B){


	if(idx == cur.size()) return (A == 0 and B == 0);

	int &ret = dp2[idx][A][B];
	if(ret != -1) return ret;

	ret = 0;

	if(A == 0 and B == 0) return ret = 1;

	if(cur[idx] == 'c'){
		if(A){
			ret = (ret + rec2(idx + 1, A - 1, B)) % MOD;
		}
	}
	else if(cur[idx] == 'd'){
		if(A == 0){
			ret  = (ret + rec2(idx + 1, A , B -1)) % MOD;
			if(B - 1 == 0){
				ret = (ret + rec(idx + 1, 0, 0)) % MOD;
			}
		}
	}
	return ret = (ret + rec2(idx + 1, A, B)) % MOD;
}

int rec(int idx, int A, int B){

	if(idx == cur.size()) return 0;

	int &ret = dp[idx][A][B];
	if(ret != -1) return ret;

	ret = 0;

	//printf("here for %d %d %d\n", idx, A, B);

	if(cur[idx] == 'a'){
		if(B == 0){
			ret = (ret + rec(idx + 1, A + 1, B)) % MOD;
		}
	}
	else if(cur[idx] == 'b'){
		if(A){
			ret = (ret + rec(idx + 1, A, B + 1)) % MOD;
			ret = (ret + rec2(idx + 1, A, B + 1)) % MOD;
		}
	}

	return ret = (ret + rec(idx + 1, A, B)) % MOD;

}

int main(){

	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		cin >> cur;
		memset(dp, -1, sizeof dp);
		memset(dp2, -1, sizeof dp2);
		printf("Case #%d: %d\n", i+1, rec(0, 0, 0));
	}
	
	return 0;
}
