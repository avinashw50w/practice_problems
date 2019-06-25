#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char str[100001];
    int t,i,l,count;
    scanf("%d\n",&t);
    while(t!=0){
        t--;
        scanf("%s\n",str);
        l=strlen(str);
        count=0;
        for(i=0;i<l;i++){
        //	count=0;
         if(str[i]==str[i+1]){
             count++;
         }
     }
            printf("%d\n",count);
        }
    
    return 0;
}

