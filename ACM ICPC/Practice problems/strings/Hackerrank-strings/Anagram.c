/* Sid is obsessed with reading short stories. Being a CS student, he is doing some interesting frequency analysis with the books. 
He chooses strings S1 and S2 in such a way that |len(S1) - len(S2)| = 1.

Your task is to help him find the minimum number of characters of the first string he needs to change to enable him to make it an anagram of the second string.

Note: A word x is an anagram of another word y if we can produce y by rearranging the letters of x.

Input Format 
The first line will contain an integer, T, representing the number of test cases. Each test case will contain a string having length len(S1)+len(S2), 
which will be concatenation of both the strings described above in the problem.The given string will contain only characters from a to z.

Output Format 
An integer corresponding to each test case is printed in a different line, i.e. the number of changes required for each test case. Print −1 if it is not possible.

Constraints

1≤T≤100 
1≤len(S1)+len(S2)≤104
Sample Input

6
aaabbb
ab
abc
mnop
xyyx
xaxbbbxx
Sample Output

3
1
-1
2
0
1
Explanation 
Test Case #01: We have to replace all three characters from the first string to make both of strings anagram. Here, S1 = "aaa" and S2 = "bbb". 
So the solution is to replace all character 'a' in string a with character 'b'. 

Test Case #02: You have to replace 'a' with 'b', which will generate "bb". 

Test Case #03: It is not possible for two strings of unequal length to be anagram for each other. 

Test Case #04: We have to replace both the characters of first string ("mn") to make it anagram of other one. 

Test Case #05: S1 and S2 are already anagram to each other. 

Test Case #06: Here S1 = "xaxb" and S2 = "bbxx". He had to replace 'a' from S1 with 'b' so that S1 = "xbxb" and we can rearrange its letter to "bbxx" in order to get S2. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 10000

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,i;
    scanf("%d",&t);
    char str[size];
    int letter1[26],letter2[26];
    
    while(t--){
        scanf("%s",str);
        int n=strlen(str);
        if(n%2==1){
            printf("-1\n");
            continue;
        }
        for(i=0;i<26;i++){
        	letter1[i]=0;
        	letter2[i]=0;
    	}
        
        int index,count=0,dif;
        for(i=n/2;i<n;i++)
            letter2[str[i]-'a']++;
        
        for(i=0;i<n/2;i++)
                letter1[str[i]-'a']++;
        
        for(i=0;i<26;i++){
            if(letter2[i]){
            	if(letter1[i]<letter2[i])
            		count += abs(letter2[i]-letter1[i]);
            }
            	
    	}
        	//	else if(itwas[i]==0 && letter2[i]==0)count++;
            
        
        printf("%d\n",count);
   
    }
    return 0;
}
