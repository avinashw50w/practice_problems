/*Chef sometimes suffers from insomnia. During sleepless nights, he often plays this game: He creates an array A of N integers and also decides one integer K.
 After that, he tries to count the number of non-empty contiguous subsequences (subsegments) of A, such that there are no bad pairs of integers in this subsegment.
  A pair (x, y) of integers is called bad if x is situated to the left of y in the array and x mod y = K. Finally, before going to sleep, Chef wrote down the 
  answer on a sheet of paper. Sadly, he has forgotten it this morning and want your help regarding that.
Input
The first line contains two integers - N and K.
Second line contains N integers - A1, A2 ... AN - separated by spaces, denoting the array A.

Output
A single line containing an integer - the answer to the problem.
*/
#include <stdio.h>
#define MAX 100007
#define gc getchar
int n,k,maxa,i,p1,p2,path,hash[MAX],b;
void scant(int *x)
{
    register int c=gc();
    *x=0;
    for(;c<48||c>57;c=gc());
    for(;c>47&&c<58;c=gc())
    {
        *x=(*x<<1) +(*x<<3)+c-48;
    }
}
int main(void) {
	long long sum=0;
	scanf("%d %d",&n,&k);
	scant(&b);
	for(p1=1;p1<=n;p1++)
	{
	    while(path<p1)
	    {
	        if(b>maxa)
	            maxa=b;
	        hash[b]=p2+1;
	        p2++;
	        if(p2==n)
	        {
	            sum += ((long long)n-p1+1)*(n-p1+2)/2;
	            printf("%lld",sum);
	            return 0;
	        }
	        scant(&b);
	        if(b>k)
	            for(i=k;i<=maxa;i+=b)
    	            if(hash[i]!=0&&path<hash[i]&&hash[i]>=p1)
    	                path = hash[i];
	    }
	    sum += p2-p1+1;
	}
}
