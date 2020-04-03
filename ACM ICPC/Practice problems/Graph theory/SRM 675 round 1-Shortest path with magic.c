/* 


 Problem Statement for ShortestPathWithMagic


Problem Statement
There are n cities, numbered from 0 to n-1. It is possible to travel directly between any two cities. Different pairs of cities may 
require different travel times. You are given the travel times as a String[] dist with n elements, each consisting of n digits. 
The digit dist[i][j] represents the time needed to travel between cities i and j in either direction.



You are also given an int k. You have k magic potions. The potion makes you twice as fast as you normally are. Each time you travel (directly)
 from some city to some other city, you may take one of the potions. If you do, that travel will only take half of what it normally would.
  You are not allowed to take more than one potion at the same time. You are not required to drink all potions you have. 



Compute and return the smallest amount of time in which you can travel from city 0 to city 1.
 
Definition
    	
Class:	ShortestPathWithMagic
Method:	getTime
Parameters:	String[], int
Returns:	double
Method signature:	double getTime(String[] dist, int k)
(be sure your method is public)
    
 
Notes
-	The travel times given in dist don't have to satisfy the triangle inequality.
-	Your return value must have a relative or absolute error less than 1e-9
 
Constraints
-	dist will contain between 2 and 50 elements, inclusive.
-	Each string in dist will contain exactly |dist| characters.
-	Each character in dist will be between '0' and '9', inclusive.
-	For any valid i and j: dist[i][j] = dist[j][i].
-	For any valid i: dist[i][i] = 0.
-	k will be between 0 and 50, inclusive.
 
Examples
0)	
    	
{"094",
 "904",
 "440"}
1
Returns: 4.5
According to dist, you need:
9 units of time to travel between cities 0 and 1
4 units of time to travel between cities 0 and 2
4 units of time to travel between cities 1 and 2
You have a single magic potion. The optimal solution is to drink the potion and to travel directly from city 0 to city 1. This trip will 
take 9/2 = 4.5 units of time.
1)	
    	
{"094",
 "904",
 "440"}
2
Returns: 4.0
The normal travel times are the same as in Example 0, but now you have two magic potions. This changes the optimal solution.
 Now it is better to travel from 0 to 2 and then from 2 to 1. For each segment of your trip you will drink one of the potions. 
 Thus, each segment will only take 4/2 = 2 units of time.  */
 
 /* Normally in a problem where we have to find the shortest path between some vertices (cities) and weighted edges (roads) between the vertices 
 we can use Dijkstra's algorithm (for example). The potions make the problem special in which you can halve the length of some of the edges.

The potions don't make the problem as special as it might first seem. In the version of the problem without potions, we move from a city aa to a city bb. 
In the real problem might use some potions. Moving from city aa to city bb with a potion is not the same as not using the potion. The edge cost is halved, 
but also the state changes. We were in city a and had r potions left, and after moving we are in city b with r-1 potions left. If we choose not to 
use the potion, we end up in city bb with rr potions left. We can consider each pair (city, number of remaining potions) as a vertex in this problem 
instead of just using the cities as vertices. This means we want to find the shortest path between (city 0, 0 potions) to (city 1, any number of potions) . 
Any number of potions is valid for the final vertex, because maybe it is not necessary to use all the potions (for example, if the number of edges in the 
path is smaller than the number of potions).

Once we use (city, number of remaining potions) as vertices all that remains in the problem is to implement a shortest paths algorithm . 
Dijkstra works well in this case. There are O(nk)O(nk) vertices and each vertex has O(n)O(n) edges (nn edges without using potions and nn edges 
with potions) so the number of edges is O(n2k)O(n2k). The usual Dijkstra implementation will need O(log(nk)(nk+n2k))O(log(nk)(nk+n2k)) time.

A slight complication is that the distances may not be integer (when halving a road of odd length). This might make the Dijkstra hard to implement. 
We can fix this by solving the problem using edges of double the real size and then halving it again once the minimum distance is found.*/

double getTime(vector<string> dist, int k)
{
    int n = dist.size();
    const int INF = 10000;
     
    vector<vector<int>> shortest(n, vector<int>(k+1, INF) );
 
    // Dijkstra:
     
    // We can use a std::set for Dijkstra, of course a priority_queue works
    // as well, but sets allow us to remove elements which makes the algo
    // O(|V|) in memory as opposed to O(|E|), this doesn't matter in this
    // problem.
    //
    // set contains pairs (distance, vertex), this way the smallest element
    // in the set will be the one with smallest distance.
    set< tuple<int,int,int> > Q;
     
     
    // The act of pushing an element (x,r) with distance d to the Dijkstra queue
    auto push = [&](int d, int x, int r) {
        if (shortest[x][r] > d) {
            // distance was larger than recorded, update:
            auto it = Q.find( make_tuple( shortest[x][r], x,r) );
            if (it != Q.end() ) {
                Q.erase(it); //erase the previous element from the set
            }
            // update
            shortest[x][r] = d;
            Q.insert( make_tuple( shortest[x][r],x,r) );
        }
    };
     
    // begin by pushing (0,k):
    push(0, 0,k);
    while (Q.size() != 0) {
        auto it = Q.begin();
        int d, x, r;
        tie(d,x,r) = *it;
        Q.erase(it);
        // move from (x,r) to (y, something):
        for (int y = 0; y < n; y++) {
            int dxy = (int)(dist[x][y] - '0');
            if (r > 0) {
                // use a potion
                push( d + dxy, y, r - 1);
            }
            // don't use a potion:
            push(d + 2*dxy, y, r);
             
            // costs are doubled, we will need to half them later
        }
    }
     
     
    // the minimum distance to (vertex 1, some r)
    int res = INF;
    for (int i = 0; i <= k; i++) {
        res = std::min(res, shortest[1][i]);
    }
    return res / 2.0;
}

///////////////another approach ////////////////////////////////

 public class ShortestPathWithMagic {
 
    double[][] x;
 
    public double getTime(String[] dist, int k)
    {
        int n = dist.length;
        x = new double[n][k+1];
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= k; j++)
            {
                x[i][j] = 1e10;
                if(i == 0)
                    x[i][j] = 0;
            }
        for(int iteration = 0; iteration < n; iteration ++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    for(int c = 0; c <= k; c++)
                    {
                        double len = dist[i].charAt(j) - '0';
                        x[i][c] = Math.min(x[i][c], x[j][c] + len);
                        if(c > 0)
                            x[i][c-1] = Math.min(x[i][c-1], x[j][c] + len / 2);
                    }
        return x[1][0];
    }
}
