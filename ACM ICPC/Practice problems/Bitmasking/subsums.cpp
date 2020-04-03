/*Given a sequence of N (1 ≤ N ≤ 34) numbers S1, ..., SN (-20,000,000 ≤ Si ≤ 20,000,000), determine how many subsets of S 
(including the empty one) have a sum between A and B (-500,000,000 ≤ A ≤ B ≤ 500,000,000), inclusive.*/
/*The solution is to Generate all subsets of the given numbers and find the number of subsets that give a sum between A and B (Inclusive). 
So this will be 2^34 (17179869184) operations atmost, which will result in TLE! So we need to come up with an alternative!
We can reduce the problem size by dividing the set into two [0…N/2] and [N/2…N-1] and find all subsets individually which will be 2*2^16 (131072)
operations. Now we can find the combinations of these sets giving the desired sum. This again can be done in an efficient way, sort one of the
summed up set and binary search the values that will yield the sum for the particular value of the other set. Example we have N=4 A=-1 B=1 and 
NUMS=[1,2,-1,0].
Now we obtain two sets like SETA=[0,1,2,3] SETB=[-1,-1,0,0] For each value in SETA we Binary search for the values that would produce the 
desired sum, for 0 we search for -1 and 1 and thus the number of sets would be high-low+1. Similarly for 1 we search for -2 and 1. This way 
we can get the total sets that yield the sum between A and B. Approximate operations would be 2^17+sort(2^16)+2^17*bsearch(2*16) which is much 
lesser than 2*34 operations!*/

int a[50];
int N, A, B;

vector<ll> genSubset(int start, int n) {
	vector<ll> ret;
	ll mask = (1<<n);
	rep(i,0,mask) {
		ll sum = 0;
		rep(j,0,n) {
			if(i & (1<<j))
				sum += a[start + j];
		}
		ret.push_back(sum);
	}
	return ret;
}

int main() {
	int N, A, B;
	si(N); si(A); si(B);
	
	rep(i,0,N) si(a[i]);

	vector<ll> left, right;

	left = genSubset(0, N/2);
	right = genSubset(N/2, N&1 ? N/2+1 : N/2);

	sort(all(right));

	ll cnt = 0;
	rep(i,0,left.size()) {
		int l = lower_bound(all(right), A - left[i]) - right.begin();
		int h = upper_bound(all(right), B - left[i]) - right.begin();
		cnt += (ll)(h - l);
	}
	printf("%lld\n", cnt);

	return 0;
}


//////////////////////////////////////////////////////

// this will give TLE

int main() {
	int N, A, B;
	si(N); si(A); si(B);
	int a[N+2];

	rep(i,0,N) si(a[i]);

	vector<ll> v;

	ll mask = (1<<N) , sum = 0;
	
	rep(i,0,mask) {
		sum = 0;
		rep(j,0,N) {
			if(i & (1<<j)) 
				sum += a[j];
		}
		v.push_back(sum);
	}

	ll cnt = 0;
	rep(i,0,v.size()) {
		if(A <= v[i] <= B) cnt++;
	}

	printf("%lld\n", cnt);

	return 0;
}
