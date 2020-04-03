/*Xsquare loves to play with arrays a lot. Today, he has two arrays named as A and B. Each array consists of N positive integers.

Xsquare has decided to fulfill following types of queries over his array A and array B.

1 L R : Print the value of AL + BL+1 + AL+2 + BL+3 + ... upto Rth term.
2 L R : Print the value of BL + AL+1 + BL+2 + AL+3 + ... upto Rth term.
Input

First line of input contains two space separated integers N and Q denoting the size of arrays ( A , B ) and number of queries respectively. Next N lines of 
input contains N space separated integers denoting array A. Next line of input contains N space separated integers denoting array B. Next Q lines of input 
contains Q queries (one per line). Each query has one of the above mentioned types.*/

/*
 clear cut idea : swap the element at even position in array A with the elements in the array B at even position then the problem becomes trivial given an array 
 and find the sum of a given range 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, Q;
	cin>>N>>Q;

	vector<long long> A(N+1), B(N+1);

	for(int i=1;i<=N;++i) cin>>A[i];

	for(int i=1;i<=N;++i) cin>>B[i];

	for(int i=2;i<=N;i+=2) swap(A[i], B[i]);

	for(int i=2;i<=N;++i) {
		A[i] += A[i-1];
		B[i] += B[i-1];
	}

	int type, L, R;

	while(Q--) {
		cin>>type>>L>>R;

		if(type == 1) {
			if(L&1) cout<<A[R] - A[L-1] << endl;

			else cout << B[R] - B[L-1] << endl;
		}
		else {
			if(L&1) cout << B[R] - B[L-1] << endl;

			else cout << A[R] - A[L-1] << endl;
		}
	}
	
}