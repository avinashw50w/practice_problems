/* http://codeforces.com/problemset/problem/859/B
Your security guard friend recently got a new job at a new security company. The company requires him to patrol an area of the 
city encompassing exactly N city blocks, but they let him choose which blocks. That is, your friend must walk the perimeter of a 
region whose area is exactly N blocks. Your friend is quite lazy and would like your help to find the shortest possible route that 
meets the requirements. The city is laid out in a square grid pattern, and is large enough that for the sake of the problem it 
can be considered infinite.

Input
Input will consist of a single integer N (1 ≤ N ≤ 106), the number of city blocks that must be enclosed by the route.

Output
Print the minimum perimeter that can be achieved.

Examples
input
4
output
8
input
11
output
14
input
22
output
20*/

#include <cstdio>
#include <cmath>

int main(){
	int n;

	scanf("%d", &n);

	printf("%.f\n", 2*ceil(2*sqrt(n)) );
}