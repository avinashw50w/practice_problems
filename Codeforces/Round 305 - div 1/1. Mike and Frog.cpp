/*Mike has a frog and a flower. His frog is named Xaniar and his flower is named Abol. Initially(at time 0), 
height of Xaniar is h1 and height of Abol is h2. Each second, Mike waters Abol and Xaniar.


So, if height of Xaniar is h1 and height of Abol is h2, after one second height of Xaniar will become  
and height of Abol will become  where x1, y1, x2 and y2 are some integer numbers and  denotes the remainder of a modulo b.

Mike  wants to know the minimum time it takes until height of Xania is a1 and height of Abol is a2.

Mike has asked you for your help. Calculate the minimum time or say it will never happen.

Input
The first line of input contains integer m (2 ≤ m ≤ 106).

The second line of input contains integers h1 and a1 (0 ≤ h1, a1 < m).

The third line of input contains integers x1 and y1 (0 ≤ x1, y1 < m).

The fourth line of input contains integers h2 and a2 (0 ≤ h2, a2 < m).

The fifth line of input contains integers x2 and y2 (0 ≤ x2, y2 < m).

It is guaranteed that h1 ≠ a1 and h2 ≠ a2.

Output
Print the minimum number of seconds until Xaniar reaches height a1 and Abol reaches height a2 or print -1 otherwise.*/

int a[2], b[2], x[3], y[3], p;
inline int nex(int c, int w){
	return (1LL * c * x[w] + y[w])%p;
}
int main(){
	iOS;
	cin >> p;
	For(i,0,2){
		if(!i)
			cin >> a[0] >> a[1];
		else
			cin >> b[0] >> b[1];
		cin >> x[i] >> y[i];
	}
	ll ans = 0LL;
	while(a[0] != a[1] && ans < p + 20){
		++ ans;
		a[0] = nex(a[0], 0);
		b[0] = nex(b[0], 1);
	}
	if(a[0] != a[1]){
		cout << -1 << endl;
		return 0;
	}
	if(a[0] == a[1] && b[0] == b[1]){
		cout << ans << endl;
		return 0;
	}
	int o = 0;
	int cur = a[0];
	x[2] = x[1], y[2] = y[1];
	x[1] = 1, y[1] = 0;
	do{
		cur = nex(cur, 0);
		++ o;
		x[1] = (1LL * x[1] * x[2]) % p;
		y[1] = (1LL * y[1] * x[2]) % p;
		y[1] = (1LL * y[1] + y[2]) % p;
	}while(o < p + 10 && cur != a[1]);
	if(cur != a[1]){
		cout << -1 << endl;
		return 0;
	}
	int O = 0;
	cur = b[0];
	do{
		cur = nex(cur, 1);
		++ O;
	}while(O < p + 10 && cur != b[1]);
	if(cur != b[1]){
		cout << -1 << endl;
		return 0;
	}
	ans += 1LL * o * O;
	cout << ans << endl;
}

/*In this editorial, consider p = m, a = h1, a′ = a1, b = h2 and b′ = a2, x = x1, y = y1, X = x2 and Y = y2.

First of all, find the number of seconds it takes until height of Xaniar becomes a′ (starting from a) and call it q. 
Please note that q ≤ p and if we don't reach a′ after p seconds, then answer is  - 1.

If after q seconds also height of Abol will become equal to b′ then answer is q.

Otherwise, find the height of Abdol after q seconds and call it e.

Then find the number of seconds it takes until height of Xaniar becomes a′ (starting from a′) and call it c. 
Please note that c ≤ p and if we don't reach a′ after p seconds, then answer is  - 1.

if g(x) = Xx + Y, then find f(x) = g(g(...(g(x)))) (c times). It is really easy:

c = 1, d = 0
for i = 1 to c
     c = (cX) % p
     d = (dX + Y) % p
Then,

f(x)
     return (cx + d) % p
 

Actually, if height of Abol is x then, after c seconds it will be f(x).

Then, starting from e, find the minimum number of steps of performing e = f(e) it takes to reach b′ and call it o. 
Please note that o ≤ p and if we don't reach b′ after p seconds, then answer is  - 1.

Then answer is x + c × o.

Time Complexity: O(p)

*/