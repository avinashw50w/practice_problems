/*given a 3x3 matrix V. Find a 3x3 magic square M such that the value of K = sum(abs(V[i][j] - M[i][j])) is minimum */

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
typedef vector<int> vi;

vector<vi> magic_squares;

int diff(vi a, vi b) {
	int ret = 0;
	rep(i,0,9) ret += abs(a[i]-b[i]);
	return ret;
}

int is_magic_square(vi v) {
	int a[3][3];
	rep(i,0,3) rep(j,0,3) a[i][j] = v[3 * i + j];

	int sum = 0, temp = 0;
	rep(i,0,3) sum += a[0][i];

	rep(i,1,2) {
		temp = 0;
		rep(j,0,3) temp += a[i][j];

		if(temp != sum) return 0;
	}

	rep(i,0,3) {
		temp = 0;
		rep(j,0,3) temp += a[j][i];

		if(temp != sum) return 0;
	}

	temp = 0;
	rep(i,0,3) temp += a[i][i];
	if(temp != sum) return 0;

	temp = 0;
	rep(i,0,3) temp += a[i][2-i];
	if(temp != sum) return 0;

	return 1;
}

void find_magic_squares() {
	vi v(9);
	rep(i,0,9) v[i] = i+1;

	do{
		if(is_magic_square(v))
			magic_squares.push_back(v);
	}while(next_permutation(v.begin(), v.end()));
}

int main() {
	vi v(9);
	rep(i,0,9) cin>>v[i];

	find_magic_squares();

	int ans = 10000000;
	rep(i,0, magic_squares.size()) {
		ans = min(ans, diff(v, magic_squares[i]));
	}
	cout<<ans<<endl;
}