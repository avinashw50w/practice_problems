/*There are N numbers a[0],a[1]..a[N - 1]. Initally all are 0. You have to perform two types of operations :

1) Increase the numbers between indices A and B by 1. This is represented by the command "0 A B"

2) Answer how many numbers between indices A and B are divisible by 3. This is represented by the command "1 A B".

Input :

The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output :

Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.*/

struct node{
	int rem1, rem2, added;
	node(): rem1(0), rem2(0), added(0) {}
};

node st[100001*3];

void change(node& P, int l, int r) {
	int tmp = P.rem1;
	P.rem1 = (r-l+1) - P.rem1 - P.rem2;
	P.rem2 = tmp;
}

void update(int i, int l, int r, int a, int b) {
	if(b<l || r<a) return;

	if(a<=l && r<=b) {
		change(st[i],l,r);
		st[i].added = (st[i].added+1)%3;	
		return;
	}
	int mid = (l+r)>>1;
	int left = (i<<1);
	int right = left|1;

	update(left, l, mid, a, b);
	update(right, mid+1, r, a, b);

	st[i].rem1 = st[left].rem1 + st[right].rem1;
	st[i].rem2 = st[left].rem2 + st[right].rem2;

	rep(k ,0, st[i].added) change(st[i],l,r);
}

int query(int i, int l, int r, int a, int b, int added) {
	if(b<l || r<a) return 0;

	if(a<=l && r<=b) {
		switch(added) {
			case 1 : return st[i].rem2;
			case 2 : return st[i].rem1;
			default : return (r-l+1) - st[i].rem1 - st[i].rem2;
		}
	}

	added = (added + st[i].added)%3;

	int mid = (l+r)>>1;
	int left = (i<<1);
	int right = left|1;
	int x = query(left, l, mid, a, b, added);
	int y = query(right, mid+1, r, a, b, added);
	return x+y;
}

int main() {
	BOOST;
	int N, Q;
	cin >> N >> Q;

	int type, l, r;
	while(Q--){
		cin>>type>>l>>r;

		if(type == 0) update(1, 0, N-1, l, r);

		else cout << query(1, 0, N-1, l, r, 0) << "\n";
	}
	return 0;
}
