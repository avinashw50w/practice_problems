/*Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. In said contest, there are 
multiple types of competitions. Here, we consider the Open and High School competition types. For each type, each competitor receives a rating, 
an integer between 1 and 100000, inclusive. A coder's rating is based upon his or her level of performance in matches and is calculated using 
a complicated formula which, thankfully, you will not be asked to implement.

Although the Open and High School ratings for a coder who has participated in both competition types lately are usually close, this is not always 
the case. In particular, High School matches are more about speed, since many coders are able to solve all the problems, whereas Open matches 
require more thinking and there is a steeper curve in terms of problem difficulty.

Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. 
For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only if both of 
coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. For each coder i, determine how many 
coders coder i is better than.

Input Format
On the first line of input is a single integer N, as described above.
N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.

Output Format
Line i should contain the number of coders that coder i is better than.*/
const int MAXN = 100000+9;
/*========================================================================================*/
struct coder{
	int x, y, id;
	coder(){}
	coder(int _x, int _y, int _id) : 
		x(_x), y(_y), id(_id) {}

	bool operator < (const coder &C) const{
		if(x == C.x) return y < C.y;
		return x < C.x;
	}
} a[3*MAXN];

int bit[MAXN], ans[3*MAXN];

void update(int i){
	for(; i<=100000; i+=i&-i) bit[i]++;
} 

int query(int i){
	int ans = 0;
	for(; i> 0; i-=i&-i) ans += bit[i];
		return ans;
}

int main() {
	int n;
	si(n);
	rep(i,0,n) {
		si(a[i].x);
		si(a[i].y);
		a[i].id = i;
	}

	sort(a, a+n);

	int i = 0;
	while(i < n) {
		int curr = i;

		while(curr < n and a[curr].x == a[i].x and a[curr].y == a[i].y) curr++;

		rep(j,i,curr) 
			ans[a[j].id] = query(a[j].y);

		rep(j,i,curr) 
			update(a[j].y);

		i = curr;
	}

	rep(i,0,n) 
		printf("%d\n", ans[i]);

	return 0;
}
