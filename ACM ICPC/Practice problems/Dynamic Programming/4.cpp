/*Samu had come up with new type of numbers, she named them Special Coprime numbers. Special Coprime numbers follow a property : A number N is said to be 
Special Coprime if sum of its digits as well as the sum of the squares of its digits are coprime to each other.

Now she started counting numbers that are Special Coprime. But soon she get bored and decided to write a program that can help do it. Now she want you to 
help her to find count of such numbers between L and R , where both L and R are included.

Input Format : 
First line contain number of test cases T. Each test case contains two space separated integers L and R, denoting the range in which you need to find 
the count of Special Coprime numbers.

Output Format : 
For each test case you need to print the count of such numbers in range [L,R]

Constraints :
1 ≤ T ≤ 1000 
1 ≤ L ≤ R ≤ 10^18

Quick Explanation: 

Given two integers L and R, you need to find the count of numbers between the given integers such that those numbers exhibit the special property 
as mentioned in the statement.

Solution:

To find count of special numbers in a particular range[L,R], we can always apply simple inclusion-exclusion principle and say that count of such numbers 
would be equal to get(0,R) - get(0,L-1).

In Short: -> get(L,R) = get(0,R) - get(0,L-1)

Now, to calculate get(0,X) i.e count of special numbers, we follow a DP approach.

We need to iterate all the numbers from 0 to X. What matters is how you iterate them such that you dont cross X. Also, we need to keep track of sum of 
digits and sum of square of digits to verify whether the number formed at last was special or not.

Lets keep a state F(idx, tight, dig_sum, sq_dig_sum) where idx denotes the index which we need to currently fill with any of the digits in range[0,9] 
and tight denotes whether the number we have formed till now is less than the current given X or equal to it. If its equal to it, then while filling 
the current index, we keep in mind so as to not to surpass the digit at idxth position of given X. if its not equal to it, we can fill any of the digit 
from [0,9], the number formed will still be smaller than X.

So, we need tight as 0 for smaller than X and 1 for equal to X in our current implementation.

If we have tight as 0, meaning for particular length, dig_sum and sq_dig_sum, we keep a pre-computed result in other recursion.

Look at the tester's code for detailed implementation.

Complexity Analysis: 

Precomputation of O(18 Max_dig_sum * Max_sq_dig_sum * 10)*

After pre-computation, Overall complexity is just the number of digits in the number.*/

ll dp[20][200][1500];  // dp[no of digits][sum of digits][sum of squares of digits]
int digits[20];

ll solver(int pos, int digitSum, int squareSum, bool check) {
	if(pos == -1) 
		return __gcd(digitSum, squareSum) == 1;
	if(!check and dp[pos][digitSum][squareSum] != -1) 
		return dp[pos][digitSum][squareSum];
	ll ans = 0;
	int endingDigit;
	if(check) endingDigit = digits[pos];
	else endingDigit = 9;
	rep(i,0,endingDigit+1)
		ans += solver(pos-1, digitSum+i, squareSum+i*i, check && i==endingDigit);

	if(!check)
		dp[pos][digitSum][squareSum] = ans;

	return ans;
}

ll solve(ll n) {
	if(n == 0) return 0;
	int len = 0;
	while(n){
		digits[len++] = n%10;
		n /= 10;
	}
	return solver(len-1, 0, 0, 1);
}

int main() {
	mset(dp,-1);
	caset{
		ll L, R;
		sl(L); sl(R);
		printf("%lld\n", solve(R) - solve(L-1) );
	}
	return 0;
}
