/*A map of some object is a rectangular field consisting of n rows and n columns. Each cell is initially occupied by the 
sea but you can cover some some cells of the map with sand so that exactly k islands appear on the map. We will call a 
set of sand cells to be island if it is possible to get from each of them to each of them by moving only through sand 
cells and by moving from a cell only to a side-adjacent cell. The cells are called to be side-adjacent if they share a 
vertical or horizontal side. It is easy to see that islands do not share cells (otherwise they together form a bigger island).

Find a way to cover some cells with sand so that exactly k islands appear on the n × n map, or determine that no such way exists.

Input
The single line contains two positive integers n, k (1 ≤ n ≤ 100, 0 ≤ k ≤ n2) — 
the size of the map and the number of islands you should form.

Output
If the answer doesn't exist, print "NO" (without the quotes) in a single line.

Otherwise, print "YES" in the first line. In the next n lines print the description of the map. 
Each of the lines of the description must consist only of characters 'S' and 'L', where 'S' is a cell that is 
occupied by the sea and 'L' is the cell covered with sand. The length of each line of the description must equal n.

If there are multiple answers, you may print any of them.

You should not maximize the sizes of islands.

Examples
inputCopy
5 2
output
YES
SSSSS
LLLLL
SSSSS
LLLLL
SSSSS*/

#include <iostream>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	if((n*n + 1)/2 > k) {
		cout << "NO\n";
		return 0;
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) 
			printf((i+j)&1 == 0 && k-- ? "L" : "S");
		printf("\n"); 
	}
}