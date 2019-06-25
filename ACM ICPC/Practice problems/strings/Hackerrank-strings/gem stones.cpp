#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 100
int count=0;
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    scanf("%d",&t);
    int rocks=t;
    char str[size];
    int letter[26],i=0;
    memset(letter,0,sizeof(letter));
    int itwas[26];
   
    while(t--){
        scanf("%s",str);
        int n=strlen(str);
        memset(itwas,0,sizeof(itwas));
    	for(i=0;i<n;i++){
            letter[str[i]-'a']+=!itwas[str[i]-'a'];
            itwas[str[i]-'a']=1;
        }
        
    }
    for(i=0;i<26;i++){
        if(letter[i]==rocks)
        count++;
	}

    printf("%d",count);
    
    return 0;
}

