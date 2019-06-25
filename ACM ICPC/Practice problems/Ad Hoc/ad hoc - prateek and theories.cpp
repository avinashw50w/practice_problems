/* problem is to find the max no of intersection of intervals

INPUT:
The first line of the input contains the integer t , the number of test cases.
For each test case first line contains a positive integer n , that is, the number of theories.
Then, n lines follow, one for each theory(1 to n ). Each line contains, 2 integers T1[i] and T2[i]. 
T1[i] is the lower bound of the theory period for the theory i. (1 <= i <= n )
T2[i] is the upper bound of the theory period for the theory i. (1 <= i <= n )

We can use STL Map to solve this problem. For every interval, we update the map value of T1[i] by 1 and 
update map value of T2[i] by -1. Initially map values will be 0. This part can be done in O(nlogn). 
Now lets take a variable X which has been initialised to 0. We have to iterate all the values of map one by one. 
For every value of map, X gets added by the value which the map holds for that particular time. 
Our answer will be the maximum value of X at any time while 
traversing the values of the map. Expected complexity of the solution is O(nlogn).*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a, b;
	cin>>t;
	while(t--) {

		cin>>n;

		map<int,int> m;

		for(int i=0;i<n;++i) {
			cin>>a>>b;
			m[a]++;
			m[b]--;
		}

		int ans = 0, cnt = 0;

		for(map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
			cnt += it->second;
			ans = max(ans, cnt);
		}

		cout << ans << endl;
	}
}