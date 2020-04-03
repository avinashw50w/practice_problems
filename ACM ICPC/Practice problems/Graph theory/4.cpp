 /*Our Code Monk recently learnt about Graphs and is very excited!

He went over to the Graph-making factory to watch some freshly prepared graphs. Incidentally, one of the workers at the factory was ill today, so Monk decided to step in and do her job.

The Monk's Job is to Identify whether the incoming graph is a tree or not. He is given N, the number of vertices in the graph and the degree of each vertex.

Find if the graph is a tree or not.

Input:
First line contains an integer N, the number of vertices.
Second line contains N space-separated integers, the degrees of the N vertices.

Output:
Print "Yes" (without the quotes) if the graph is a tree or "No" (without the quotes) otherwise.

Constraints:
1 ≤ N ≤ 100
1 ≤ Degreei ≤ 1000  */

/*  solution: based on handshaking lemma 
sum of degrees of all the vertices = 2*(number of edges)

and in a tree, number of edges = number of vertices - 1           */

int main() {
	int n; si(n);
	int deg[n+2];
	sum_deg = 0
	rep(i,0,n) {
		si(deg[i]);
		sum_deg += deg[i];
	}
	int edges = sum_deg/2;
	(edges == n-1)? puts("Yes"): puts("No");
	return 0;
}
