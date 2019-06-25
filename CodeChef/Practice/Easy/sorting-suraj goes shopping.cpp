/*It is winter super sale and all the shops have various offers. Suraj selected N items to buy and he is standing in the billing queue. It was then he noticed the offer "Buy two, get two". That means for every two items you buy, they give you two items for free. However, items can be of varying price, they always charge for 2 most costly items and give other 2 as free. For example, if the items cost 1, 1, 2, 2, then you have to pay 4 and take all 4 items.

Suraj is busy reordering his items to reduce the total price he has to pay. He can separate the items and get them on different bills if needed. Can you tell me what is the least price Suraj has to pay to buy all the N items?

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. First line of each test case has single integer N. Second line of each test case has N space separated integers, which are the costs of items Suraj want to buy.

Output

For each test case, output a single line containing the required answer.

Constraints

1 ≤ T ≤ 1000
1 ≤ N ≤ 1000
1 ≤ Cost of items ≤ 1000
Example

Input:
3
4
1 1 2 2
2
10 200
7
1 1 10 2 2 2 1

Output:
4
210
14
Explanation

Example case 1

Suraj pays for 2 costly items and gets other 2 for free.

Example case 2

Suraj has to pay for both the items, he wont get anything for free.

Example case 3

Suraj separates the items into 2 bills. In one bill he pays 12. And in another bill he pays 2.*/
int a[1000+2];

void CountingSort(int a[], int n){
	int b[n+2], c[1001]={}, k=0;
	rep(i,0,n) c[a[i]]++;
	rep(i,1,1001) c[i]+=c[i-1];
	for(int i=n-1;i>=0;--i) { b[c[a[i]]] = a[i]; c[a[i]]--; }

	for(int i=n;i>=1;--i) a[k++] = b[i];
}

int main() {
	int n,t=inp();
	while(t--){
		n=inp();
		rep(i,0,n) a[i]=inp();
		if(n==1) { printf("%d\n", a[0]); continue; }

		CountingSort(a,n);

		int sum = 0;
		for(int i=0;i<n;i+=4){
			sum += a[i]+ (i+1<n? a[i+1]: 0);
		}
		printf("%d\n", sum);
	}
	return 0;
}
