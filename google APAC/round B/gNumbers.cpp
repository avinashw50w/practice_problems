/*Googlers are crazy about numbers and games, especially number games! Two Googlers, Laurence and Seymour, have invented a new two-player game based on "gNumbers". 
A number is a gNumber if and only if the sum of the number's digits has no positive divisors other than 1 and itself. (In particular, note that 1 is a gNumber.)

The game works as follows: First, someone who is not playing the game chooses a starting number N. Then, the two players take turns. On a player's turn, the player 
checks whether the current number C is a gNumber. If it is, the player loses the game immediately. Otherwise, the player chooses a prime factor P of C, and keeps 
dividing C by P until P is no longer a factor of C. (For example, if the current number were 72, the player could either choose 2 and repeatedly divide by 2 until 
reaching 9, or choose 3 and repeatedly divide by 3 until reaching 8.) Then the result of the division becomes the new current number, and the other player's turn begins.

Laurence always gets to go first, and he hates to lose. Given a number N, he wants you to tell him which player is certain to win, assuming that both players play optimally.

Input

The first line of the input gives the number of test cases, T. T test cases follow; each consists of a starting number N.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the winner's name: either Laurence or Seymour.

Limits

1 ≤ T ≤ 100.
Small dataset

1 < N ≤ 1000.
Large dataset

1 < N ≤ 10^15.
Sample


Input 
 	
Output 
 
9
2
3
4
6
8
9
30
36300
1000000000000000

Case #1: Seymour
Case #2: Seymour
Case #3: Laurence
Case #4: Laurence
Case #5: Laurence
Case #6: Laurence
Case #7: Seymour
Case #8: Laurence
Case #9: Seymour

In Case #1, 2 is already a gNumber, since the sum of its digits is 2, which has no positive divisors other than 1 and itself. So Laurence immediately loses, 
which means Seymour wins. The same is true for Case #2.

In Case #3, 4 is not a gNumber, since the sum of its digits is 4, which has a positive divisor other than 1 and itself (namely, 2). 4 has one prime factor (2), 
so Laurence must choose this factor and repeatedly divide 4 by it, which leaves him with 1. Then, Seymour begins his turn with 1, which is a gNumber. So he loses 
and Laurence wins.*/

using namespace std;
#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

map<LL, int> dp;

int P[35] = {2,3,5,7,11,13,17,19,23,29,			// max number can be 9999....16 digits , so sum of digits = 9 * 16 = 144
31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,				// so we have taken a list of primes upto 144
127,131,137,139,149};


bool isPrime(int sum){
	if(sum == 1) return true;
	REP(i, 0, 35){
		if(P[i] == sum) return true;
	}
	return false;
}

vector<LL> primes(LL x){		// generate prime factors of x
	vector<LL> ret;

	for(LL i = 2; i*i <= x; i++){

		int cnt = 0;
		while(x % i == 0){
			x = x / i;
			cnt++;
		}
		if(cnt) ret.push_back(i);
	}
	if(x > 2) ret.push_back(x);
	return ret;
}

int rec(LL x){

	if(dp.count(x)){
		return dp[x];
	}

	LL y = x, sum = 0;
	while(y) sum += y % 10, y = y / 10;

	
	if(isPrime(sum)){
		return dp[x] = false;
	}

	vector<LL> Primes = primes(x);

	for(int i = 0; i < Primes.size(); i++){
		LL y = x;
		while(y % Primes[i] == 0){
			y /= Primes[i];
		}
		if(rec(y) == false){
			return dp[x] = true;
		}
	}

	return dp[x] = false;

}

int main(){

	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		string ans = "Seymour";
		LL val;
		scanf(	"%lld", &val);
		if(rec(val)){;
			ans = "Laurence";
		}
		printf("Case #%d: ", i+1);
		cout << ans << "\n";
	}
	
	return 0;
}
