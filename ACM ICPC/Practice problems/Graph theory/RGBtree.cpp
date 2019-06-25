/*Problem Statement
    	You are given a simple undirected graph with n nodes, labeled 0 through n-1. Each edge of this graph is red, green, or blue. 
        You are given a description of the graph in a String[] G. For each pair of nodes (i, j) there are four possibilities:
G[i][j] = 'R', meaning that i and j are connected by a red edge.
G[i][j] = 'G', meaning that i and j are connected by a green edge.
G[i][j] = 'B', meaning that i and j are connected by a blue edge.
G[i][j] = '.', meaning that i and j are not connected by an edge.


A spanning tree of our graph is any set S of exactly k = n-1 edges such that it is possible to travel from any node to any other node 
by only using edges from S. Does our graph have a spanning tree that has exactly k/3 edges of each color (red, green, blue)? If it does, 
return "Exists". Otherwise, return "Does not exist".
 
Definition
    	
Class:	RGBTree
Method:	exist
Parameters:	String[]
Returns:	String
Method signature:	String exist(String[] G)
(be sure your method is public)
    
 
Constraints
-	n will be between 4 and 13, inclusive.
-	n mod 3 will be 1.
-	G will contain exactly n elements.
-	Each element in G will contain exactly n characters.
-	Each character in G will be one of {'.', 'R', 'G', 'B'}.
-	For each i, G[i][i] = '.'.
-	For each i and j, G[i][j] = G[j][i].
 
Examples
0)	
    	
{".RGB",
 "R...",
 "G...",
 "B..."}
Returns: "Exist"
This graph has exactly three edges: one red, one green, and one blue. These three edges form the desired spanning tree.*/

/*Let's think of a way to enumerate all spanning trees in the graph, when we find one that has the correct edge colors, we can return true. 
If we find no such spanning tree, the return is false. It helps to know Prim's algorithm. It is used for minimum spanning trees, but in case 
of a graph where all edges have the same weight, all spanning trees are minimum. So Prim's algorithm will work just fine:

Start with an arbitrary vertex, any vertex works so we will use vertex 0.
In every step, pick the smallest edge that adds a connection between a vertex in the connected set and a vertex outside of the set. 
In this case, all edges are the smallest length, so we can pick any of them.
In each step we might have multiple options for what edge to pick. We need to try all combinations of such decisions. Even for a small 
constraint like n≤13n≤13, this might be too slow. Imagine a graph in which every pair of vertices has a connecting edge - A complete graph. 
The number of spanning trees in a complete graph is nn−2nn-2 (Cayley's formula) , for n=13n=13, this number is very high.

Dynamic programming
Instead of trying all possible spanning trees, notice that when adding a vertex to the connected component, we do not really care about 
the specific color configuration between the previously picked vertices. All that we need to remember is the number of edges of each color 
that we already picked AND of course, the current set of vertices in the connected component. Let's think of a function f(S,r,g,b) 
that tells us if we can reach a spanning tree. SS is the current set of vertices in the connected component. rr, gg and bb are the 
number of edges of each color that we have already picked.

A base case, when SS contains all the vertices in the graph and rr, gg and bb are each n−13n-13, then the result is true. Else, if SS is 
full we do not need to do anymore as we already know the result is false.
Otherwise, try all vertices ii that belong to the connected component SS and all vertices jj that don'T. If there is an edge connecting them, 
we can find if there exists a spanning tree including this edge. Depending of the edge color: f(S⋃{j},r+1,g,b)f(S⋃{j},r+1,g,b), 
f(S⋃{j},r,g+1,b)f(S⋃{j},r,g+1,b) or f(S⋃{j},r,g,b+1)f(S⋃{j},r,g,b+1). (We add jj to the set and increment the number of edges of that color). 
Repeat this for all pairs (i,j)(i,j) until you find one in which the spanning tree exists.
Each state of the function needs O(n2)O(n2) calls. There are O(2n)O(2n) subsets SS and rr, gg and bb should never exceed n−13n-13. 
We can use dynamic programming or memoization to ensure that each state is calculated at most once. This means that the final complexity 
is O(2n⋅n5)O(2n⋅n5) which is very appropriate for n≤13n≤13.*/

int mem[1<<13][5][5][5]; // we'll memoize the results of calls to f() in this
 
vector<string> G;
 
// We are using a bit mask to represent set S of the vertices in the connected
// component. mask & (1<<j) means j is in the bit mask.
// mask | (1 << j) returns a new bit mask that includes j.
bool f(int mask, int r, int g, int b)
{
    bool res = false;
    if (mem[mask][r][g][b] == -1) {
        int n = G.size(), k = (n - 1)/3;
         
        // when all the edge counts are correct, the tree is found:
        if (r == k && g == k && b == k) {
            res = true;
        }
         
        // pick a new edge to include:
        for (int i = 0; i < n; i++) {
            if ( mask & (1<<i) ) {    // one end of the new edge should be in the current set:
                for (int j = 0; j < n; j++) {
                    if ( (! (mask & (1 << j) ) ) && (G[i][j] != '.') ) {
                        // increment the appropriate color
                        int nr = r, ng = g, nb = b;
                        switch ( G[i][j] ) {
                        case 'R':
                            nr++;
                            break;
                        case 'G':
                            ng++;
                            break;                                
                        case 'B':
                            nb++;
                            break;                                
                        }
                        // no need to check when there are too many edges of a color:
                        if ( (nr <= k) && (ng <= k) && (nb <= k) ) {
                            res = (res || f(mask | (1<<j), nr,ng,nb) ); 
                        }
                    }
                }
            }
        }
        mem[mask][r][g][b] = (res? 1: 0);
    } else {
        res = ( (mem[mask][r][g][b] == 1) ? true : false);
    }
    return res;
}
 
 
string exist(vector<string> G)
{
    this->G = G;
    memset(mem, -1, sizeof(mem) );
     
    // 1, because the set that includes {0} is 1 << 0 = 1
    return f(1,  0,0,0) ? "Exist" : "Does not exist";
}