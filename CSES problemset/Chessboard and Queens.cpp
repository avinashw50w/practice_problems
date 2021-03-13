/*Your task is to place eight queens on a chessboard so that no two queens are attacking each
other. As an additional challenge, each square is either free or reserved, and you can only
place queens on the free squares. However, the reserved squares do not prevent queens from
attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Example

Input:
........
........
..*.....
........
........
.....**.
...*....
........

Output:
65 */


int main() {
	string s[8];
	for (int i = 0; i < 8; ++i) cin >> s[i];

	int p[8], b[15], ans = 0;
	iota(p, p + 8, 0);
	// check all permutations of queens
	do {
		bool ok = 1;
		// check if we can place them on '.'
		for (int i = 0; i < 8; ++i)
			ok &= s[i][p[i]] == '.';

		// check if they don't lie diagonaly
		memset(b, b + 15, 0);
		for (int i = 0; i < 8; ++i)
			if (b[i + p[i]]) ok = 0;
			else b[i + p[i]] = 1;

		memset(b, b + 15, 0);
		for (int i = 0; i < 8; ++i)
			if (b[i + 7 - p[i]]) ok = 0;
			else b[i + 7 - p[i]] = 1;

		ans += ok;
	} while (next_permutaion(p, p + 8));

	cout << ans << "\n";
}