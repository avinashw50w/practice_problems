/* Alice recently started learning about cryptography and found that anagrams are very useful. 
Two strings are anagrams of each other if they have same character set and same length. 
For example strings "bacdc" and "dcbac" are anagrams, while strings "bacdc" and "dcbad" are not.

Alice decides on an encryption scheme involving 2 large strings where encryption is dependent on the minimum number 
of character deletions required to make the two strings anagrams. She need your help in finding out this number.

Given two strings (they can be of same or different length) help her in finding out the minimum number of 
character deletions required to make two strings anagrams. Any characters can be deleted from any of the strings.

Input Format 
Two lines each containing a string.

Constraints 
1 <= Length of A,B <= 10000 
A and B will only consist of lowercase latin letter.

Output Format 
A single integer which is the number of character deletions.

Sample Input #00:

cde
abc
Sample Output #00:

4
Explanation #00: 
We need to delete 4 characters to make both strings anagram i.e. 'd' and 'e' from first string and 'b' and 'a' from second string. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char str1[10000],str2[10000];
    scanf("%s",str1);
    scanf("%s",str2);
    int letter1[26],letter2[26];
    int i,n;
    int l1=strlen(str1);
    int l2=strlen(str2);
    if(l1>l2)
        n=l1;
    else n=l2;
    memset(letter1,0,sizeof(letter1));
    memset(letter2,0,sizeof(letter2));
    for(i=0;i<l1;i++)
        letter1[str1[i]-'a']++;
    for(i=0;i<l2;i++)
        letter2[str2[i]-'a']++;
    
    int count=0,dif;
    for(i=0;i<26;i++){
        dif=abs(letter1[i] - letter2[i]);
        if(dif>0)
            count+=dif;
    }
    printf("%d",count);
    return 0;
}

