/*Chef loves circular cakes. He divides them into smaller pieces and sells them. You are to help him in this work.
Today Chef has cooked the brand new circular cake. To split the cake Chef can make several (possibly, zero) cuts. Each cut should be a straight line going from the center of the cake to its border. Also, the angle between any two cuts should have positive integer value (Chef measure all the angles in degrees). Chef consider two pieces of cake equal if the appropriate angles are equal.


The picture contains two distinct pieces, and two cuts. Red part on the image shows one piece. The appropriate angle is AOB.
Chef gives to you an integer N, denoting the number of pieces Chef wants to make. You need to answer the following questions:
Is it possible to make exactly N equal pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake?
Is it possible to make exactly N pieces from the whole cake, in such a way that no two of them are equal?*/

#include <iostream>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		if(360%n == 0) printf("y ");
		else printf("n ");
		if(n<=360) printf("y ");
		else printf("n ");
		if(n<=26) printf("y ");  //  1+2+3+4+....+ n = 360  , => n*(n+1)/2 = 360 ,  => n ~ 26
		else printf("n ");
		printf("\n");
	}
	return 0;
}
