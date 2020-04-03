/*Chef is the new king of the country Chefland. As first and most important responsibility he wants to reconstruct the road system of Chefland. There are N (1 to N) cities in the country and each city i has a population Pi. Chef wants to build some bi-directional roads connecting different cities such that each city is connected to every other city (by a direct road or through some other intermediate city) and starting from any city one can visit every other city in the country through these roads. Cost of building a road between two cities u and v is Pu x Pv. Cost to build the road system is the sum of cost of every individual road that would be built.

Help king Chef to find the minimum cost to build the new road system in Chefland such that every city is connected to each other.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

First line contains an integer N denoting the number of cities in the country. Second line contains N space separated integers Pi, the population of i-th city.

Output

For each test case, print a single integer, the minimum cost to build the new road system on separate line.

Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Pi ≤ 106 */

/*We need to add edges such that all the cities become connected. Connected is defined as "it should be possible from any city to reach any other city by a sequence of edges".

There doesn't exist a graph which is connected and has less than (N-1) edges (which is known as a tree). 
So we will be constructing a tree finally with (N-1) edges. So, we all nodes will be connected to the node with smallest value.*/

int main() {
	int t=inp();
	while(t--){
		int p, n=inp(), mn=10000000;
		ll sum = 0;
		rep(i,0,n) { p=inp(); sum += p; mn=min(mn,p); }
		
		sum -= mn;

		printf("%lld\n", sum*mn);

	}
	return 0;
}
