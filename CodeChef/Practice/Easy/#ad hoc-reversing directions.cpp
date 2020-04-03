/*Chef recently printed directions from his home to a hot new restaurant across the town, but forgot to print the directions 
to get back home. Help Chef to transform the directions to get home from the restaurant.

A set of directions consists of several instructions. The first instruction is of the form "Begin on XXX", 
indicating the street that the route begins on. Each subsequent instruction is of the form "Left on XXX" or "Right on XXX", 
indicating a turn onto the specified road.

When reversing directions, all left turns become right turns and vice versa, and the order of roads and turns is reversed. See the sample input for examples.

Input

Input will begin with an integer T, the number of test cases that follow. Each test case begins with an integer N, 
the number of instructions in the route. N lines follow, each with exactly one instruction in the format described above.

Output

For each test case, print the directions of the reversed route, one instruction per line. Print a blank line after each test case.

Constraints

1 ≤ T ≤ 15
2 ≤ N ≤ 40
Each line in the input will contain at most 50 characters, will contain only alphanumeric characters and spaces and will not contain consecutive spaces nor trailing spaces. 
By alphanumeric characters we mean digits and letters of the English alphabet (lowercase and uppercase).
Sample Input

2
4
Begin on Road A
Right on Road B
Right on Road C
Left on Road D
6
Begin on Old Madras Road
Left on Domlur Flyover
Left on 100 Feet Road
Right on Sarjapur Road
Right on Hosur Road
Right on Ganapathi Temple Road
Sample Output

Begin on Road D
Right on Road C
Left on Road B
Left on Road A

Begin on Ganapathi Temple Road
Left on Hosur Road
Left on Sarjapur Road
Left on 100 Feet Road
Right on Domlur Flyover
Right on Old Madras Road*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	                                                                           


int main() {
	int t, n, i;
	char turn[40][50], road[40][50];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);

		for(i=0;i<n;++i) scanf("%s %[^\n]%*c", turn[i], road[i]);

		for(i=n-1;i>=0;--i){
			if(i == n-1) printf("Begin %s\n", road[i]);
			else {
				if(strcmp(turn[i+1], "Left") == 0)
					printf("Right %s\n", road[i]);
				else printf("Left %s\n", road[i]);
			}
		}
		printf("\n");
	}
	return 0;
}


