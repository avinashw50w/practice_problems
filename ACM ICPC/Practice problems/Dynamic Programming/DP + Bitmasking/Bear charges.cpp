/*Limak is a little bear who loves to play computer games. Today he is playing a game in which the goal is to capture all bases on the map.
There are N bases on the map. The bases are numbered 0 through N-1. For each i, base i is located at (x[i], y[i]). Initially, Limak only 
controls base 0.
Each base contains an electric cannon. The cannon in each base that is owned by Limak is being charged at the rate of 1 unit of energy per 
second. Charging happens continuously: for example, in 4.7 seconds the cannon gains 4.7 units of energy.
To capture an enemy base, Limak has to shoot it by a cannon from one of his bases. Shot takes no time but it consumes energy. Assume Limak 
wants to shoot base B using a cannon in his base A. Let D be the Euclidean distance between bases A and B. In order to shoot the cannon from 
base A to base B the cannon needs to have at least D units of energy. Exactly D units of energy are consumed by the shot. (I.e., at the 
moment of the shot the energy of the cannon in base A is decreased by D.)
At the beginning of the game the energy of the cannon in base 0 is 0. Whenever Limak captures another base, the energy of the cannon in that 
base is also 0, and the cannon begins to charge immediately after the capture.
Limak is able to fire the cannons at arbitrary, possibly non-integer times. He is able to fire multiple cannons at the same time. (Each of 
them pointed at a different enemy base.) Limak may capture the enemy bases in any order he likes.

Return the shortest time in which Limak can capture all the bases.
 
Definition
    	
Class:	BearCharges
Method:	minTime
Parameters:	int[], int[]
Returns:	double
Method signature:	double minTime(int[] x, int[] y)
(be sure your method is public)  
 
Notes
-	Your return value must have absolute or relative error smaller than 1e-9.
 
Constraints
-	N will be between 1 and 10, inclusive.
-	x will have exactly N elements.
-	y will have exactly N elements.
-	Each element in x and y will be betweeen -10^9 and 10^9, inclusive.
-	No two bases will be located at the same coordinates.
 
Examples
0)	
    	
{10, 11, 12}
{0, 0, 1}
Returns: 2.414213562373095
Wait for one unit of time and then fire the cannon in base 0 at base 1 to capture it. Wait for another sqrt(2) units of time and then fire 
the cannon in base 1 to capture base 2.

 Each base is a vertex and all vertices (except 0) should have a parent — base from which this one was captured. So we are looking for a tree 
 but not exactly MST because for a vertex order of his children matters.
Let dp[mask][x] denote time needed to capture all bases in set defined by mask if we start with base x. We will calculate dp[S][a] by 
iterating over possible first son of a and over bitmask denoting set of vertices in subtree of a — so consider to which base b we shoot 
first and what bases will be captured directly or indirectly by b. dp[S][a] = min(dp[S][a], dist(a, b) + max(dp[A][a], dp[S - A][b]))
It is O(3n·n2) but you can get easier implementation with O(4n + 3n·n2)  */

public static double minTime(int[] x, int[] y) {
        int n = x.length;
        int M = 1 << n;
        double dp[][] = new double[M][n];
        for(int S = 0; S < M; ++S)
         for(int A = 0; A < M; ++A)
          if((S | A) == S)
           for(int a = 0; a < n; ++a)
            for(int b = 0; b < n; ++b)
             if((A & (1 << a)) > 0)
              if((S & (1 << b)) > 0 && (A & (1 << b)) == 0) {
               double dist = Math.sqrt(Math.pow(x[a]-x[b],2) + Math.pow(y[a]-y[b],2));
               double maybe = dist + Math.max(dp[A][a],dp[S-A][b]);
               if(dp[S][a] < 0.1 || dp[S][a] > maybe)
                dp[S][a] = maybe;
              }
        return dp[M-1][0];
    }