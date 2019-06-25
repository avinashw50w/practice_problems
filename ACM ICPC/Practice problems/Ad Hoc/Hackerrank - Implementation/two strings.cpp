#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100000

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,i;
    scanf("%d",&t);
    char str1[size],str2[size];
    int letter1[26],letter2[26],itwas[26],l1,l2;
    while(t--){
        scanf("%s",str1);
        scanf("%s",str2);
        for(i=0;i<26;i++){
            letter1[i]=0;
            letter2[i]=0;
            itwas[i]=0;
        }
        int f=0;
        l1=strlen(str1);
        l2=strlen(str2);
        for(i=0;i<l1;i++)
            itwas[str1[i]-'a']=1;
        for(i=0;i<l2;i++){
            if(itwas[str2[i]-'a']==1){
                printf("YES\n");
                f=1;break;
            }
            
        }
     
          if(f==0)
            printf("NO\n");
    }
    
    return 0;
}

