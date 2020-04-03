
/* fn = -1+2-3+4-....(-1)^n*n 
fn = 2+3+4+... - (1+3+5+...)
for n even: fn = n/4(2*2 + (n/4-1)2) - n/4(2*1 + (n/4-1)2) = n/2
for n odd: fn = n/2 - n
*/

#include <iostream>
using namespace std;

int main() {
	long long n; cin >> n;
	if (n&1) cout << ((n>>1) - n) << endl;
	else cout << (n>>1) << endl;
}