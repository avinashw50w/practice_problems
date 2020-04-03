/*Roman has no idea, why this problem is called Stone. He also has no idea on how to solve the followong problem: given array of N integers A and a number K. 
During a turn the maximal value over all Ai is chosen, let's call it MAX. Then Ai =
MAX - Ai is done for every 1 <= i <= N. Help Roman to find out how will the array look like after K turns.

Input

The numbers N and K are given in the first line of an input. Then N integers are given in the second line which denote the array A.

Output

Output N numbers on a single line. It should be the array A after K turns.

Constraints

1 <= N <= 105
0 <= K <= 109
Ai does not exceed 2 * 109 by it's absolute value.*/

/*QUICK EXPLANATION:
There will a cycle of size not greater than 2. After that we can easily simulate the operations.*/

ll a[100000+2];
int main() {
	ll n, k; sl(n); sl(k);
	rep(i,0,n) sl(a[i]);

	if(k==0) { rep(i,0,n) printf("%lld ", a[i]); return 0; }

	(k&1) ? k=1: k=2;

	rep(i,0,k){
		ll m=*max_element(a,a+n);
		rep(j,0,n) a[j] = m-a[j];
	}
	rep(i,0,n) printf("%lld ", a[i]);
	printf("\n");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main(){
	long long int n,k,*a,i,min = 2000000001,max = -2000000001;
	n = read();
	k = read();
	a = (long long int*)calloc(n,sizeof(long long int));
	for(i = 0;i<n;i++){
		a[i] = read();
		if(a[i]<min) min = a[i];
		else{
			if(a[i]>max) max = a[i];	
		}
	}
	//printf("%d %d\n",max,min);
	//printf("%d",min);
	if(k == 0){
		for(i = 0;i<n;i++){
			printf("%lld ",a[i]);
		}
	}
	else if(k%2 == 0){
		for(i = 0;i<n;i++){
			printf("%lld ",a[i]-min);
		}
	}
	else{
		for(i = 0;i<n;i++){
			printf("%lld ",max-a[i]);
		}
	}
	free((void*)a);
}
