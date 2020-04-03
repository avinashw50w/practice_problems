/*PROBLEM
We have two markets S and T. We want to build two restaurants. The markets and restaurants can be considered as points in 2D Cartesian plane. 
Arrange markets and the restaurants in such a way that:

The distance between S and T is D.
The distance between S and one of the restaurants is DS.
The distance between T and the other restaurant is DT.
The distance between the two restaurants is minimized.
Determine the minimum distance between the two restaurants.

QUICK EXPLANATION
To solve this kind of problem, it is best to try sketching many placements of the objects, and try spotting some easy patterns that lead to 
the best result. The answer to this problem is very short: max(0, D - DS - DT, DS - DT - D, DT - DS - D).

EXPLANATION
We can divide the input into 4 cases:

Case 1. D ≥ DS + DT

The optimal placement of the objects is in a straight line as follows.

  +----------D----------+
 /                       \
S        R       R        T
 \      /         \      /  
  +-DS-+           +-DT-+
Here, the markets are represented by S and T while restaurants are represented by R's. The minimum distance between the points is D - DS - DT.

Case 2. (DS + DT > D) and (D + DS > DT) and (D + DT > DS)

The lengths are said to satisfy the triangle inequality. In this case, we can always form a triangle as follows.

  +----------D----------+
 /                       \
S                         T
  \                     /
    \                 /
      DS           DT
        \         /
          \     /
            \ /
             R
Here, the two restaurants are located in the exact same position and thus represented by a single R. The distance is of course 0.

Case 3. Triangle inequality does not hold and DS ≥ D + DT

The optimal placement is as follows.

  +----------DS---------+
 /                       \
S        T        R       R
 \      / \      /  
  +-D--+   +-DT-+
The distance between the restaurants is DS - D - DT.

Case 4. Triangle inequality does not hold and DT ≥ D + DS

The optimal placement is as follows.

  +----------DT---------+
 /                       \
R        R       S        T
          \      /\      /  
           +-DS-+  +-D--+
The distance between the restaurants is DT - D - DS.

***

So, the code for this solution is very simple, just considering all four cases and printing the appropriate value. However, one can actually 
unite the four cases in one single expression: max(0, D - DS - DT, DS - DT - D, DT - DS - D). */


int main() {
	int t, ds,dt,d;
	t=inp();
	while(t--){
		ds=inp();
		dt=inp();
		d=inp();
		printf("%d.0\n", max(0, max(d-(ds+dt), max(ds-(d+dt), dt-(d+ds)))));
	}
	return 0;
}
