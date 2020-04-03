/*You are given n triangles.

You are required to find how many triangles are unique out of given triangles. For each triangle you are given three integers a,b,c , the sides of a triangle.

A triangle is said to be unique if there is no other triangle with same set of sides.

Note : It is always possible to form triangle with given sides.

INPUT:

First line contains n, the number of triangles. Each of next n lines contain three integers a,b,c (sides of a triangle).

Output:

print single integer, the number of unique triangles.

Constraints:

1 <= n <= 10^5
1 <= a,b,c <= 10^15*/

int main() {
	int n; cin>>n;
	ll a, b, c;
	vector<ll> p(3);

	map<vector<ll>, int> m;

	rep(i,0,n) {
		cin>>p[0]>>p[1]>>p[2];
		sort(all(p));
		m[p]++;
	}

	int cnt = 0;
	for(auto i = m.begin(); i!=m.end(); ++i) {
		if(i->second == 1) cnt++;
	}

	cout << cnt << endl;
	return 0;
}
