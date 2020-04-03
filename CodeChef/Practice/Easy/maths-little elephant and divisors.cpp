/*The Little Elephant from the Zoo of Lviv has an array A that consists of N positive integers. Let A[i] be the i-th number in this array (i = 1, 2, ..., N).

Find the minimal number x > 1 such that x is a divisor of all integers from array A. More formally, this x should satisfy the following relations:

A[1] mod x = 0, A[2] mod x = 0, ..., A[N] mod x = 0,

where mod stands for the modulo operation. For example, 8 mod 3 = 2, 2 mod 2 = 0, 100 mod 5 = 0 and so on. If such number does not exist, output -1.

Input

The first line of the input contains a single integer T, the number of test cases. T test cases follow. The first line of each test case contains a single integer N, the size of the array A for the corresponding test case. The second line contains N space separated integers A[1], A[2], ..., A[N].

Output

For each test case output a single line containing the answer for the corresponding test case.

Constraints

1 ≤ T ≤ 100000

1 ≤ N ≤ 100000

The sum of values of N in each test file does not exceed 100000

1 ≤ A[i] ≤ 100000

Example

Input:
2
3
2 4 8
3
4 7 5

Output:
2
-1*/

/*PROBLEM
You are given a list of numbers. You have to find the smalelst number which divides all these numbers.

QUICK EXPLANATION
To the initiated, this question should be a breeze.

Find the GCD of the list of numbers.
Find the smallest prime factor of the GCD.*/

const int MAXN=100000+2;
int factors[MAXN];

void pre(){
	rep(i,2,MAXN) factors[i]=i;
	rep(i,2,MAXN){
		if(factors[i]==i){
			for(ll j=2*i;j<=MAXN;j+=i) 
				factors[j] = min(factors[j],i);
		}
	}
}

int main() {
	pre();
	int t=inp();
	while(t--){
		int n=inp();
		int g=0;
		rep(i,0,n) { int x=inp(); g=__gcd(g,x); }
		if(g==1) { printf("-1\n"); continue; }
		printf("%d\n", factors[g]);
	}
	return 0;
}
