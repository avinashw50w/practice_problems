/*Rohit dreams he is in a shop with an infinite amount of marbles. He is allowed to select n marbles. There are marbles of k different colors. 
From each color there are also infinitely many marbles. Rohit wants to have at least one marble of each color, but still there are a lot of 
possibilities for his selection. In his effort to make a decision he wakes up. Now he asks you how many possibilities for his selection he 
would have had. Assume that marbles of equal color can't be distinguished, and the order of the marbles is irrelevant.

Input

The first line of input contains a number T <= 100 that indicates the number of test cases to follow. Each test case consists of one line 
containing n and k, where n is the number of marbles Rohit selects and k is the number of different colors of the marbles. You can assume 
that 1<=k<=n<=1000000.

Output

For each test case print the number of possibilities that Rohit would have had. You can assume that this number fits into a signed 64 bit integer.*/
/*There is only one way to select the first 7 items...as they are non distinguishable...right...but the remaining 23 items...the problem is a 
classic multiset permutation problem...u have k color groups...x1+x2+x3.....xk=(n-k)..where x1,x2,x3 ..xk..are the number of items belonging to 
respective colors....u have to distribute the remaining (n-k) items in the k groups such that x1,x2..xk>=0, ..... the 7^23 term that u are 
calculating is a sequence which has the importance of order... permutation=importance of order+ non repetition..... sequence=importance of 
order+ repetition......... combination=no importance of order + non repetition....... multiset= no importance of order + repetition.....

this is a easy problem based on permutations and combinations

the number of ways of selecting n marbles , such that each marbles of atleast 1 type is selected considering k types is same as (number of ways
of getting sum n of k numbers and each number is greater than equal to 1 )  ie, x1+x2+x3+....+xk = n (xi is the no of items of same type)

it is same as finding the coefficient of x^n in binomial expansion of (x+x^2+x^3+x^4.....+x^n)^k

this comes out to be C(n-1,k-1) */


int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n, k;
	caset{
		cin>>n>>k;

		--n; --k;

		if(k > n-k) k = n-k;

		double p = 1;
		for(int i=k; i>0; i--, n--) p *= n;

		for(; k; k--) p /= k;

		printf("%.f\n", p );
	}
	return 0;
}
