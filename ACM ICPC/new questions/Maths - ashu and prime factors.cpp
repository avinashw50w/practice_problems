/*Given a prime number X, you need to give the count of all numbers in range 1 to 106 inclusive which have minimum prime factor X.
Constraints:
1 ≤ T ≤ 10^5
Prime number X where 2 ≤ X ≤ 10^6

SAMPLE INPUT 
2
2
11
SAMPLE OUTPUT 
500000
20779
Explanation
The minimum prime factor of all even numbers in the range [2, 1000000] is 2, and there are 1000000/2 = 500000 such even numbers.
The numbers with minimum prime factor as 11 are: 11, 121, 143, ...*/

const int maxn = 1000001;
int p[maxn], cnt[maxn];

void seive() {
	long long i, j, c;
	for(i = 2; i < maxn; ++i) {
		if(!p[i]){
			c = 0;
			for(int j = i; j < maxn; j+=i) {
				if(p[j] == 0) c++;
				p[j] = 1;
			}
			cnt[i] = c;
		}
	}
}

int main()
{
	seive();
    int t; cin>>t;
    int n;
    while(t--) {
    	cin>>n;
    	cout << cnt[n] << endl;
    }
    return 0;
}

/*We can use a method similar to finding primes with Sieve of Eratosthenes. While processing multiples of a prime number X, 
mark only those multiples (uptil 106) that haven't yet been marked and increment the multiple count for X.

Consider the list from 1 to 10. Let all numbers from 2 to 10 be unmarked initially. Count of required multiples of all primes = 0. 
That is: count[2] = 0, count[3] = 0, count[5] = 0, count[7] = 0.

Initially: 1 2 3 4 5 6 7 8 9 10 (1 is marked as non-prime, and it is not a multiple of any prime)
Next un-marked number in the list = 2. So, we mark the multiples of 2, which have not been marked yet.
4, 6, 8, 10 are multiples of 2, and all of them are un-marked initially. So, we include them all in count[2]. Hence, count[2] = 4.

Updated list: 1 2 3 4 5 6 7 8 9 10 (Note: 4 is marked)

Next un-marked number = 3.
6, 9 are the multiples of 3. However, 6 has already been marked. Hence, we only take 9 into account. Hence, count[3] = 1.

Updated list: 1 2 3 4 5 6 7 8 9 10

Next un-marked number: 5
10 is the multiple of 5, but it is already marked. Hence, count[5] = 0.

Next un-marked number: 7
No multiple of 7, less than equal to 10, is available to mark. Hence, count[7] = 0.

Similarly, perform this same action uptil 106. At the end, add 1 to each count[i], because every prime number is the smallest multiple of itself.

For given value of X in each test case, print the value of count[X] on a new line.*/