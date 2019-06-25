#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char t[10];
    int h,m,s,h1,h2;
    scanf("%s",t);
    h=(t[0] - '0')*10 + (t[1] - '0');
   // m=(t[3] - '0')*10 + (t[4] - '0');
   // s=(t[6] - '0')*10 + (t[7] - '0');
    if(t[8]=='P'){
        h+=12;
    }
    t[8]='\0';
    h1=h/10;
    h2=h%10;
    t[0]=h1 + '0';
    t[1]=h2 + '0';
    printf("%s",t);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

