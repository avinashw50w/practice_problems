/*Devu has an array A consisting of N positive integers. He would like to perform following operation on array.
Pick some two elements a, b in the array (a could be same as b, but their corresponding indices in the array should not be same).
Remove both the elements a and b and instead add a number x such that x lies between min(a, b) and max(a, b), both inclusive, (i.e. min(a, b) ≤ x ≤ max(a, b)).
Now, as you know after applying the above operation N - 1 times, Devu will end up with a single number in the array. He is wondering whether it is possible to do the operations in such a way that he ends up a number t.
He asks your help in answering Q such queries, each of them will contain an integer t and you have to tell whether it is possible to end up t.
Input

There is only one test case per test file.
First line of the input contains two space separated integers N, Q denoting number of elements in A and number of queries for which Devu asks your help, respectively
Second line contains N space separated integers denoting the content of array A.
Each of the next Q lines, will contain a single integer t corresponding to the query.
Output

Output Q lines, each containing "Yes" or "No" (both without quotes) corresponding to the answer of corresponding query.
Constraints

1 ≤ N, Q ≤ 105
0 ≤ t ≤ 109  */

int main() {
	int n,q,a[100000+2];
	cin >> n >> q;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int mx = *(max_element(a,a+n));
	int mn = *(min_element(a,a+n));
	while(q--) {
		int t; cin>>t;
		if(t > mx or t < mn){
			cout << "No\n";
		}
		else cout << "Yes\n";
	}
	return 0;
}