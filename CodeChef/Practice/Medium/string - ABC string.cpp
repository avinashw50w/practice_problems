/*You are given an AB-string S. You need to count the number of substrings of S, which have an equal number of 'A'-s and 'B'-s.

Do you know how to solve it? Good. Mike will make the problem a little bit more difficult for you.

You are given an ABC-string S. You need to count the number of substrings of S, which have an equal number of 'A'-s, 'B'-s and 'C'-s.

A string is called AB-string if it doesn't contain any symbols except 'A' or 'B'. A string is called ABC-string if it doesn't contain any symbols except 'A', 'B' or 'C'.*/
/*PROBLEM:
Given a string S which is consisted of characters ‘A’, ‘B’ or 'C'. Find the number of substrings of S which have equal number of ‘A’s, ‘B’s and ‘C’s.

EXPLANATION:
Let, 
Ai = Number of ‘A’s in S between the indexes 1 and i (inclusive).
Bi = Number of ‘B’s in S between the indexes 1 and i (inclusive).
Ci = Number of ‘C’s in S between the indexes 1 and i (inclusive).

Let’s consider the substring Sj...i :
Number of ‘A’-s in that substring = Ai - Aj-1
Number of ‘B’-s in that substring = Bi - Bj-1
Number of ‘C’-s in that substring = Ci - Cj-1

So for that substring to be good: Ai - Aj-1 = Bi - Bj-1 = Ci - Cj-1

Alternatively the following two conditions are enough for that substring to be good:

Ai - Bi = Aj-1 - Bj-1 
Ai - Ci = Aj-1 - Cj-1

Go from left to right and for each index i find the number of valid good substrings which ends at i. The number of such substrings would be the number of 
indexes k (k < i) where (Ai - Bi, Ai - Ci )= (Ak - Bk, Ak - Ck ). That can be obtained if the pair (Ak - Bk, Ak - Ck )for all k are stored in a key-value 
storage where the key being the pair and value being the number indexes having that difference pair. If using C++, STL Map can be used. The author did not 
use a map, instead he computed all the difference pairs and then sorted those and then find the number of equal pairs.*/

pair<int,int> P[MAXN];

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string S;

	cin >> S;
	int N = S.size();
	int A, B, C;
	A = B = C = 0;
	rep(i,0,N) {
		A += (S[i] == 'A');
		B += (S[i] == 'B');
		C += (S[i] == 'C');
		P[i+1] = make_pair(A-B, A-C);
	}
	P[0] = make_pair(0,0);
	sort(P, P+N+1);

	ll ans = 0, cnt = 0;
	pair<int,int> prev(-oo, -oo);
	rep(i,0,N+1) {
		if(P[i] != prev) {
			prev = P[i];
			cnt = 0;
		}
		ans += cnt;
		cnt++;
	}

	cout << ans << endl;
	return 0;
}
