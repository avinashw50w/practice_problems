/*Farmer Feb has three fields with potatoes planted in them. He harvested x potatoes from the first field, y potatoes from the second field and is yet to harvest potatoes from the third field. Feb is very superstitious and believes that if the sum of potatoes he harvests from the three fields is a prime number (http://en.wikipedia.org/wiki/Prime_number), he'll make a huge profit. Please help him by calculating for him the minimum number of potatoes that if harvested from the third field will make the sum of potatoes prime. At least one potato should be harvested from the third field.
Input

The first line of the input contains an integer T denoting the number of test cases. Each of the next T lines contain 2 integers separated by single space: x and y.
 
Output

For each test case, output a single line containing the answer.
 
Constraints

1 ≤ T ≤ 1000
1 ≤ x ≤ 1000
1 ≤ y ≤ 1000*/

int isPrime(int n){
	ll i,j;
	if(n==2) return 1;
	if(n%2==0) return 0;
	for(i=3;i*i<=n;i+=2){
		if(n%i == 0) return 0;
	}
	return 1;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		x += y;
		for(int i=1;i<=1000;++i){
			if(isPrime(x+i)){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}