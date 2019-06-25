/*Chinese Remainder Theorem | Set 2 (Inverse Modulo based Implementation)
We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). 
We need to find minimum positive number x such that:


     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 
Example:

Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
Output: 11
Explanation: 
11 is the smallest number such that:
  (1) When we divide it by 3, we get remainder 2. 
  (2) When we divide it by 4, we get remainder 3.
  (3) When we divide it by 5, we get remainder 1. 

The solution is based on below formula.


x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all but num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of 
         pp[i] with respect to num[i]  */

// finding inverse using extended euclid
int inv(int a, int m) {
	
	if(m == 1) return 0;

	int m0 = m, t, q;
	int x = 1, y = 0;

	while(a > 1) {

		q = a / m;	// quotient
		// a will become m, and m will become a%m
		t = m;
		m = a % m, a = t;

		// extended euclid
		t = y;

		y = x - q * y;

		x = t;
	}

	if(x < 0) x += m0;

	return x;
}

int findMinX(int num[], int rem[], int N) {
	int prod = 1;
	for(int i = 0; i < N; ++i) prod *= num[i];

	int res = 0;

	for(int i = 0; i < N; ++i) {
		int pp = prod / num[i];
		res += rem[i] * pp * inv(pp, num[i]);
	}

	return res % prod;
}


// Driver method
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}

