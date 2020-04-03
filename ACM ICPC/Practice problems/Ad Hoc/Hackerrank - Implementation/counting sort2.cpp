#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long int n,i;
    scanf("%ld",&n);
    int A[n+1],B[n+1],count[100];
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);
    memset(count,0,sizeof(count));
    for(i=1;i<=n;i++)
        count[A[i]]++;
    for(i=1;i<100;i++)
        count[i] += count[i-1];
    for(i=n;i>=1;i--){
        B[count[A[i]]] = A[i];
        count[A[i]]--;
    }
    for(i=1;i<=n;i++)
        printf("%d ",B[i]);
    return 0;
}

