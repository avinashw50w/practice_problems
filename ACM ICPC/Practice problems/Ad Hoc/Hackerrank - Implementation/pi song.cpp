#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
char pi[]={"31415926535897932384626433833"};
int t;
scanf("%d",&t);
while(t--){
char str[500],str1[30];
scanf("%s",str);
int c=0,i=0,j=0;
while(str[i]!='\0'){
if((str[i]>=97 && str[i]<=122) || (str[i]>=65 && str[i]<=90) || str[i]==' '){
if(str[i]==' '){
str1[j++]=c;
c=0;
continue;
} else c++;
}
    i++;
}
    i=0;
   while(str1[i]!='\0'){
       if(str1[i]!=pi[i]){
           printf("It's not a pi song.\n");
           break;
       }i++;
   }
printf("It's a pi song.\n");


}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

