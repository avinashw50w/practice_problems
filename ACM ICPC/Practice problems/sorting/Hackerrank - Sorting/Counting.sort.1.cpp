#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n,i;
    scanf("%ld",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count[100];
    memset(count,0,sizeof(count));
    for(i=0;i<n;i++)
        count[arr[i]]++;
    for(i=0;i<100;i++)
        printf("%d ",count[i]);
    return 0;
}

