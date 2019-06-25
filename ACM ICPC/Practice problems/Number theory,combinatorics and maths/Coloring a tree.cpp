/*You have a tree consisting of n vertices. You want to color each vertex of the tree in one of the k colors such that for any pair of 
vertices having same color, all the vertices belonging to the path joining them should also have same color. In other words, for any two 
vertices u, v with same color, all the vertices in the path joining them should also have color same as that of the u (or same as v, 
as u and v have same color).

Find out possible number of ways in which you can color the tree satisfying the above property. As the answer could be large, print your answer 
modulo 109 + 7.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

For each test case, first line contains two space separated integers n, k denoting number of vertices in the tree and total number of colors, 
respectively

Each of the next n - 1 lines contain two space separated integers ui, vi, denoting that there is an edge between vertices ui and vi in the tree*/

/*Now, we know what we need to count. We need to count the number of valid selections of the set S, and the number of assignments of colors 
among them. S can be any set of nodes, with one condition: node 1 must be in S. (Why?)

Now, let's compute the answer. Suppose exactly i colors appear in the tree. How many choices for S are there? Well, S has i elements, but 
one element has already been chosen for us, namely node 1, so we need to select the remaining i-1 nodes among the remaining n-1 nodes. 
There are (n−1Ci−1) choices. Next, we need to assign colors to these nodes. First, we must select i colors among the k available. 
There are (kCi) choices. Finally, how many ways are there to assign these colors to the nodes? There are i choices of colors for the 
first node, i−1 for the second node, i−2 for the third node, etc. Therefore, there are i(i−1)⋯2⋅1=i!i(i−1)(i−2)⋯2⋅1=i! assignments. 
Therefore, the number of colorings of a tree with exactly i colors is (n−1Ci−1)(kCi)i!. Summing across all valid values of i, 
we get the following answer:
∑(i=1 to min(n,k))(n−1Ci−1)(kCi)i!  */
int n,k,u,v;
int C[55][55];
int fac[55];

int prec(){
	fac[0] = fac[1] = 1;
	rep(i,2,55) fac[i] = (i * fac[i-1]) % mod;

	rep(i,0,55){
		int k = (i>>1);
		C[i][0] = C[i][i] = 1;
		rep(j,1,k+1)
			C[i][j] = C[i][i-j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
}

int main() {
	prec();
	caset{
		si(n); si(k);
		rep(i,0,n-1) { si(u);si(v);}

		ll ans = 0;
		rep(i,1,k+1){
			ans = (ans + C[n-1][i-1] * C[k][i] * fac[i]) % mod;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
