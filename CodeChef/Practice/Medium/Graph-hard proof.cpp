/*You are preparing for an exam in Calculus 4. In the chapter "Abstract Fourier Series", you encountered an excercise in which you are given a collection of N 
statements and your task is to prove that all N statements are equivalent. For the purpose of this problem, we will number the statements 0 through N-1.

For any pair of statements x and y, you are able to prove that statement x implies statement y. However, the proofs of different implications may have different 
difficulties. You are given a int[] D with N^2 elements. For each x and y, the difficulty of proving the implication "x => y" is D[x*N+y].

The exercise is solved by proving a set of implications such that each statement directly or indirectly implies each other statement. For example, if N = 3, one 
way of solving the exercise is to prove the implications 0 => 1, 1 => 0, 0 => 2, and 2 => 0. Another way of solving the exercise is to prove the implications 0 => 1, 1 => 2, and 2 => 0.

You are not looking for the least difficult solution. When writing proofs, your biggest issue is switching between easy and hard proofs. Therefore, you are 
looking for a solution where the difference between the difficulty of the hardest proof and the difficulty of the easiest proof is as small as possible. Compute and return that difference.

 
Definition
    	
Class:	HardProof
Method:	minimumCost
Parameters:	int[]
Returns:	int
Method signature:	int minimumCost(int[] D)
(be sure your method is public)
    
 
Constraints
-	D will contain exactly N^2 elements.
-	N will be between 1 and 50, inclusive.
-	Each element of D will be between 0 and 150,000, inclusive.
-	For each valid x, D[x*N+x] will be 0.
 
Examples
0)	
    	
{0,11,13,13,
10,0,12,13,
10,10,0,11,
12,10,10,0}
Returns: 1
Here, an optimal solution consists of the following proofs: 0 => 1, 1 => 2, 2 => 3, and 3 => 0. The difficulties of these proofs are 11, 12, 11, and 12, 
respectively. The difference between the largest and the smallest difficulty is 12-11 = 1.*/

/*So how can we find those needed sequences of implications? A good idea is to think of this as a graph. Each statement is a vertex and each implication A→B is 
a directed edge connecting A to B. A sequence of implications starting with statement 0 is then simply a path. So what we need to know is if we can reach all 
other vertices when starting with vertex 0. This is doable in O(|E|+|V|) time by using a Depth-first search or a Breadth-first search, where |V| is the number 
of vertices (n) and |E| is the number of edges which is O(n2). So the complexity will be O(n2) . We can even use the same approach to find the reverse direction 
paths. Just use a modified version of the graph in which all the existing implications get their directions reversed, so starting at vertex 0 we can find all 
the vertices such that you can reach vertex 0 starting at that vertex.

Picking the implications
Given the implications, we can verify in O(n2) time if the implications are enough to make all statements equivalent. But how can we find the set of implications 
that has the least difference between the most expensive implication and the least expensive one? One way we could do is pick a minimum m and a maximum M 
difficulty for the implications. Then we should pick all the implications with difficulty between m and M and check in O(n2) if they are enough to prove the 
equivalences. The problem is that there are O(n2) possible different values for m and M, so this would make an O(n6) approach.

We can use binary search to optimize it from O(n6) to O(n4log(n)),You can fix m then binary search for the maximum M. Or you can binary search for d=M-m and then 
fix m and only use implications with cost between m and m+d.
*/

vector<bool> bfs(int n, int m, int dif, vector<int> & D, bool forward)
{
    vector<bool> reach(n, false);
    queue<int> Q;
    Q.push(0);
    reach[0] = true;
    while (! Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int y = 0; y < n; y++) {
            int a = x, b = y;
            if (! forward) {
                a = y, b = x;
            }
            if ( m <= D[a*n + b] && D[a*n + b] <= m + dif) {
                if (! reach[y]) {
                    reach[y] = true;
                    Q.push(y);
                }
            }
        }
    }
    return reach;
 
}
 
 
// is it possible to have a given difference "dif"?
bool is_correct(int n, int dif, vector<int> & D)
{
    // fix the minimum difficulty m:
    for (int m: D) {          //O(n^2 * log(Max(D)))
         
        // do a BFS search in both directions to know which vertices are
        // reachable from 0 and can reach 0.
        vector<bool> forw = bfs(n,m,dif, D,true);  //O(n^4 * log(Max(D)))
        vector<bool> back = bfs(n,m,dif, D,false); //O(n^4 * log(Max(D)))
        bool good = true;
        for (int i = 0; i < n; i++) {   //O(n^3 * log(Max(D)))
            if ( !forw[i] || !back[i] ) {
                // not equivalent
                good = false;
            }
        }
        if (good) {
            return true;
        }
    }
    return false;
}
 
 
int minimumCost(vector<int> D)
{
    int n = 0;
    while (n * n < D.size() ) {
        n++;
    }
    // Binary search
    int lo = -1; // a small value that we know is not good
    int hi = *max_element(D.begin(), D.end()); // a large value that we know is good
     
    // half the gap between known values in each step
    while (lo + 1  < hi) {
        int ha = (lo + hi) / 2;
        if (is_correct(n, ha, D)) {
            hi = ha;
        } else {
            lo = ha;
        }
    }
    return hi;
}