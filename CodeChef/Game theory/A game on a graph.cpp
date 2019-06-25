/* Two players, Askar and Bob, play a game with a token on an undirected graph G. The game goes as follows:
Askar chooses a starting vertex and places the token on this vertex.
The players now alternate turns; Bob moves first.
In his turn, each player has to move the token along exactly one edge to another vertex.
It's not allowed to move the token to some vertex if it was on that vertex earlier during the game (including the starting vertex).
The player who can't make a move loses.
A vertex v is called a winning vertex if Askar is able to win after choosing this v as the starting vertex. Assume that both players play optimally.
Given the graph G, determine how many winning vertices exist.
Input

The first line of the input contains an integer T - the number of test cases.
The first line of each test case contains two integers N and M, denoting the number of vertices and the number of edges of G.
The following M lines describe the edges of G. Each of these lines contains two integers x and y, denoting an edge between vertices x and y.
Output

For each test case, output a single line containing the number of winning vertices.
Constraints

 
1 = T = 100
N-1 = M = N(N-1)/2
1 = x,y = N
x ? y
All unordered pairs (x,y) will be distinct
The graph in each test case will be connected
Sum of M over all test cases in a single file will never exceed 106.
 
Subtasks

Subtask 1 (8 points): 1 = N = 18
Subtask 2 (19 points): 1 = N = 40
Subtask 3 (26 points): 1 = N = 200
Subtask 4 (47 points): 1 = N = 2000
The time limit is 2 seconds for subtasks 1-3 and 5 seconds for subtask 4.
Example

Input:
3
4 6
1 2
1 3
4 1
4 2
4 3
2 3
8 7
3 2
1 2
4 2
5 1
6 3
7 1
8 3
3 2
1 2
2 3

Output:
0
4
2
Explanation

Example case 1. The graph is a complete graph with 4 vertices, so the game will always last 3 turns; in the 4th turn, Askar will have no way to move and lose.
Example case 2. If Askar places the token on vertex 7, Bob will have to move it to vertex 1 and Askar can then move it to vertex 5 and win. 
A similar strategy exists for vertices 5, 6 and 8.
Example case 3. If Askar places the token on vertex 1, Bob will have to move it to vertex 2 and Askar can then move it to vertex 3 and win. 
The case when Askar starts at vertex 3 is analogous. On the contrary, if Askar starts at vertex 2, then Bob can move the token to either vertex 1 or 3, and in both cases 
Askar can't make a move and loses.

Solution:
DIFFICULTY:
Hard

PREREQUISITES:
game theory, graphs, maximum matching, Edmonds' blossom algorithm

PROBLEM:
Two players, A and B, play a game with a token on an undirected graph G. The game goes as follows:

A chooses a starting vertex and places the token on this vertex.
The players now alternate turns; B moves first.
In his turn, each player has to move the token along exactly one edge to another vertex.
It's not allowed to move the token to some vertex if it was on that vertex earlier during the game (including the starting vertex).
The player who can't make a move loses.
A vertex v is called a winning vertex if A is able to win after choosing this v as the starting vertex. Assume that both players play optimally. 
Given the graph G, determine how many winning vertices exist.

QUICK EXPLANATION:
================ 
Any vertex that is unmatched in one of the maximum matchings of the graph is a winning vertex. Using a maximum matching algorithm (for example Edmonds' Blossom) build one maximum matching of the graph.

Now, find all alternating paths on it which start on unmatched vertices (once again using Edmonds’ blossom algorithm). All vertices at the end of some alternating path of even length are winning.

EXPLANATION:
================

DEFINITIONS:
First let us see a few definitions.

Given a general graph G=(V,E), a maximum matching M is defined as a set of edges such that each vertex in V is incident with at most one edge in M and |M| is maximized.
Given G=(V,E) and a matching M of G, a vertex v is "exposed" if no edge of M is incident with v.
A path in G is an alternating path, if its edges are alternately not in M and in M (or in M and not in M).
An augmenting path P is an alternating path that starts and ends at two distinct exposed vertices. A matching augmentation along an augmenting path P is the operation of replacing M with a new matching as shown in the following image. 

According to Berge's lemma, a matching being maximum is equivalent to non-existence of an augmenting path in the graph.

A perfect matching is a matching of a graph containing n2 edges(where n is number of vertices), the largest possible, meaning perfect matchings are only possible on graphs with an even number of vertices.
WINNING CONDITION:
First, let’s investigate the winning condition of the players. There are two cases to be considered here depending on whether graph has a perfect matching or not.

Graph has perfect matching
If graph G has a perfect matching, all vertices v of G are matched, that means, no matter where A puts the token, B can always move this token along the matched edges in this matching. This guarantees that player B will always have a valid move and since the game is finite, he has to win.

Graph doesn't have perfect matching
If G does not have a perfect matching, player A can choose a maximum matching and place the token in an unmatched vertex, which will result in the player B moving it to a matched one. The player A can now repeat the same strategy of moving along matched edges to win. Notice that there’s no way for the player B to move the token to an unmatched vertex, as that would construct an augmenting path(remember the definition?), but there are no augmenting paths in a maximum matching.

Now, we clearly know what we want. We want to count how many vertices don't belong to all the maximum matchings of the graph G. Or in other words, we know what the winning vertices are: they’re vertices unmatched in some maximum matching.

Proof to above statement: If a vertex belongs to all maximum matchings, then player B will win by simply always moving along matched edges; in this arrangement player A can never move to an unmatched vertex, as that’d construct an alternating path that starts in a matched and ends in an unmatched vertex and flipping that path creates a new maximum matching where the starting vertex is unmatched, which is not possible since vertex belongs to all maximum matchings.

HOW TO COUNT WINNING VERTICES
There are too many distinct maximum matchings and even counting them is hard. We can see some of the methods below to count such vertices.

What we can do is find number of edges in maximum matching(for example using Edmonds’ blossom algorithm) of G. Say this value is C. Now for each vertex v we try to decide if it belongs to all maximum matchings or not. If we remove v from G and calculate maximum matching again, and if the new matching value c is <C, then we can say that it was part of all maximum matchings of G. An easy way to intuitively realise this is to consider that there exists a matching M of G which doesn't have v matched, then removing G shouldn't change the matching and maximum matching in G-v should still remain C.

Solution 1(slow)
Now, for calculating the maximum matching in the graph G by excluding some vertex v, we can compute the maximum matching with v excluded from scratch. This option clearly has complexity O(V·max_matching) where O(max_matching) is the complexity of maximum matching algorithm. It can pass subtasks 1, 2 and 3 if you use fairly fast maximum matching algorithm like Edmonds' Blossom modification which works in O(EVv).

Solution 2(fast)
For every vertex i which is part of the initial maximum matching, try to remove it and check if the matching can be increased. If not, then i occurs in all maximum matchings of the graph. For testing if the matching can be increased after removing the vertex i, it is enough to try to find an augmenting path starting from the vertex j, which is the vertex to which i is matched in the initial maximum matching.

Solution 3(faster)
We don't want to calculate maximum matching again and again. For that we need to analyse our matchings in some more detail. Let's say we have calculate a random maximum matching on the graph G initially. I hereby propose a statement:

All vertices at the end of some alternating path of even length beginning at an unmatched vertex are winning. 
If there is such an alternating path, we can flip the edges in it to produce another maximum matching, where the vertex at the end of this alternating path will now become unmatched. Now, we can say that this vertex is a winning vertex, because it's unmatched in one of the maximum matching.

If some vertex is winning, take the symmetric difference of our chosen (and computed) matching and the one where it’s unmatched. There’s a path starting on that vertex (it corresponds to an alternating path) and it has an even length (both matchings are maximum), so it has to end at an unmatched vertex in our chosen matching. Now, we’ve proven both sides of the equivalence between alternating paths and winning-ness of vertices.

The above part of finding vertices at the end of some alternating path of even length beginning at an unmatched vertex can be done in similar way to finding the augmenting paths in Edmonds' Blossom algorithm. For each unmatched vertex, try to augment from that vertex. There are 3 types of vertices in that augmenting DFS path(i.e. the path you take when you root the DFS tree at the unmatched vertex and go to all the vertices you see when you alternate-walk from this vertex):

vertices in at least one blossom; add all of them to the answer.
matched vertex whose spouse is behind it in the path; add to answer(since then path is of even length)
matched vertex whose spouse is after it in the path; do not add to answer(odd length)  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USE_SLOW_ALGO 0
#define DEBUG 0
#define NMAX 2501

int v[NMAX][NMAX], nv[NMAX];
int N, M;

void ReadInput() {
	scanf("%d %d", &N, &M);
	int i, j, k;
	memset(nv, 0, sizeof(nv));
	for (k = 1; k <= M; k++) {
		scanf("%d %d", &i, &j);
		nv[i]++; nv[j]++;
		v[i][nv[i]] = j;
		v[j][nv[j]] = i;
	}
}

int used[NMAX], lcaused[NMAX], blossomused[NMAX], blossom[NMAX], baseused[NMAX];
int Mv[NMAX], p[NMAX], pused[NMAX], q[NMAX], base[NMAX], qli, qls, lcaidx;
int blossom_changed[NMAX], nblossom_changed, blossom_changed_idx[NMAX];
int pathidx, blossomidx;
 
int LCA(int a, int b, int excl = 0) {
	lcaidx++;
	for (;;) {
		if (baseused[a] != pathidx) {
			base[a] = a;
			baseused[a] = pathidx;
			//exit(1);
		}
		a = base[a];
		lcaused[a] = lcaidx;
		if (!Mv[a] || Mv[a] == excl)  break;
		if (pused[Mv[a]] != pathidx) {
			exit(11);
		}
		a = p[Mv[a]];
	}
	for (;;) {
		if (baseused[b] != pathidx) {
			base[b] = b;
			baseused[b] = pathidx;
			//exit(2);
		}
		b = base[b];
		if (lcaused[b] == lcaidx) return b;
		if (pused[Mv[b]] != pathidx) {
			exit(12);
		}
		b = p[Mv[b]];
	}
}

void MarkPath(int i, int b, int children) {
	while (1) {
		if (baseused[i] != pathidx) {
			base[i] = i;
			baseused[i] = pathidx;
		}
		if (base[i] == b) break;
		if (baseused[Mv[i]] != pathidx) {
			base[Mv[i]] = Mv[i];
			baseused[Mv[i]] = pathidx;
		}
		if (blossom_changed_idx[i] != blossomidx) {
			blossom_changed[nblossom_changed++] = i;
			blossom_changed_idx[i] = blossomidx;
		}
		if (blossom_changed_idx[base[i]] != blossomidx) {
			blossom_changed[nblossom_changed++] = base[i];
			blossom_changed_idx[base[i]] = blossomidx;
		}
		if (blossom_changed_idx[Mv[i]] != blossomidx) {
			blossom_changed[nblossom_changed++] = Mv[i];
			blossom_changed_idx[Mv[i]] = blossomidx;
		}
		if (blossom_changed_idx[base[Mv[i]]] != blossomidx) {
			blossom_changed[nblossom_changed++] = base[Mv[i]];
			blossom_changed_idx[base[Mv[i]]] = blossomidx;
		}
		blossom[base[i]] = blossom[base[Mv[i]]] = 1;
		blossomused[base[i]] = blossomused[base[Mv[i]]] = blossomidx;
		p[i] = children;
		pused[i] = pathidx;
		children = Mv[i];
		if (pused[Mv[i]] != pathidx) exit(333);
		i = p[Mv[i]];
	}
}

int FindAugmentingPath(int root, int excl = 0) {
	pathidx++;
	used[root] = pathidx;
	qli = qls = 0;
	q[qls++] = root;
	
	while (qli < qls) {
		int i = q[qli++];
		if (baseused[i] != pathidx) {
			base[i] = i;
			baseused[i] = pathidx;
		}
		for (int k = 1; k <= nv[i]; k++) {
			int j = v[i][k];
			if (baseused[j] != pathidx) {
				baseused[j] = pathidx;
				base[j] = j;
			}
			if (base[i] == base[j] || Mv[i] == j || j == excl) continue;
			if (j == root || (Mv[j] > 0 && pused[Mv[j]] == pathidx && Mv[j] != excl)) {
				int curbase = LCA(i, j, excl);
				blossomidx++;
				nblossom_changed = 0;
				MarkPath(i, curbase, j);
				MarkPath(j, curbase, i);
				for (int ll = 0; ll < nblossom_changed; ll++) {
					int l = blossom_changed[ll];
					if (baseused[l] != pathidx) {
						baseused[l] = pathidx;
						base[l] = l;
					}
					if (blossomused[base[l]] == blossomidx) {
						base[l] = curbase;
						baseused[l] = pathidx;
						if (used[l] != pathidx) {
							used[l] = pathidx;
							q[qls++] = l;
						}
					}
				}
			} else if (pused[j] != pathidx) {
				p[j] = i;
				pused[j] = pathidx;
				if (!Mv[j] || Mv[j] == excl) return j;
				j = Mv[j];
				used[j] = pathidx;
				q[qls++] = j;
			}
		}
	}
	return 0;
}
 
int MaxMatching(int excl = 0) {
	int i, j, k, l, c = 0;
	memset(Mv, 0, sizeof(Mv));
	for (i = 1; i <= N; i++) {
		if (Mv[i] || i == excl) continue;
		for (j = 1; j <= nv[i]; j++)
			if (!Mv[v[i][j]] && v[i][j] != excl) {
				Mv[i] = v[i][j];
				Mv[v[i][j]] = i;
				c++;
				if (DEBUG) fprintf(stderr, "[MaxMatching] initial edge %d-%d c=%d\n", i, v[i][j], c);
				break;
			}
	}
	for (i = 1; i <= N; i++)
		if (!Mv[i] && i != excl) {
			j = FindAugmentingPath(i, excl);
			if (!j) continue;
			c++;
			if (DEBUG) fprintf(stderr, "[MaxMatching] augmenting path %d-%d c=%d\n", i, j, c);
			while (j > 0) {
				k = p[j];
				l = Mv[k];
				if (DEBUG) fprintf(stderr, "  add edge %d-%d\n", j, k);
				if (DEBUG && l > 0) fprintf(stderr, "  remove edge %d-%d\n", k, l);
				Mv[j] = k, Mv[k] = j;
				j = l;
			}
		}
	return c;
}

void WriteTest() {
	printf("%d %d\n", N, M);
	int i, j;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= nv[i]; j++)
			if (i < v[i][j])
				printf("%d %d\n", i, v[i][j]);
}

int main() {
	//freopen("y.txt", "r", stdin);
	int t, T, win2, i, j;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		ReadInput();
		int c, C = MaxMatching();
		for (win2 = 0, i = 1; i <= N; i++) {
			if (USE_SLOW_ALGO) {
				if ((c = MaxMatching(i)) < C) {
					win2++;
					//fprintf(stderr, "win2=%d i=%d c=%d C=%d\n", win2, i, c, C);
				}
			} else {
				// For every vertex i which is part of the initial maximum matching, try to remove it and check if the matching can be increased. If not, then i occurs in all maximum matchings of the graph. For testing if the matching can be increased after removing the vertex i it is enough to try to find an augmenting path starting from the vertex j, which is the vertex to which i is matched in the initial maximum matching.
				if (!Mv[i]) continue;
				for (j = 1; j <= N; j++)
					if (j != i && (!Mv[j] /*|| Mv[j] == i*/) && FindAugmentingPath(j, i)) {
						if (DEBUG) fprintf(stderr, "[Ans] excl=%d: FindAugmentingPath(%d)=1\n", i, j);
						break;
					}
				if (j > N) {
					win2++;
					//fprintf(stderr, "win2=%d i=%d\n", win2, i);
				}
			}
		}
		printf("%d\n", N - win2);
	}
	return 0;
}
