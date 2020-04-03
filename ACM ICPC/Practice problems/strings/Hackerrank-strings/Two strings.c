/* You are given two strings, A and B. Find if there is a substring that appears in both A and B.

Input Format

Several test cases will be given to you in a single file. The first line of the input will contain a single integer T, the number of test cases.

Then there will be T descriptions of the test cases. Each description contains two lines. The first line contains the string A and the second line contains the string B.

Output Format

For each test case, display YES (in a newline), if there is a common substring. Otherwise, display NO.

Constraints

All the strings contain only lowercase Latin letters.
1<=T<=10
1<=|A|,|B|<=105           */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 101010

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,i;
    scanf("%d",&t);
    char str1[size],str2[size];
    int itwas[26],l1,l2;
    while(t--){
        scanf("%s",str1);
        scanf("%s",str2);
        for(i=0;i<26;i++){
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
