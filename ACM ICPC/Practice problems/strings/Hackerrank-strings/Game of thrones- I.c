/* Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.

door

But, to lock the door he needs a key that is an anagram of a certain palindrome string.

The king has a string composed of lowercase English letters. Help him figure out whether any anagram of the string can be a palindrome or not.

Input Format 
A single line which contains the input string.

Constraints 
1≤ length of string ≤105 
Each character of the string is a lowercase English letter.

Output Format 
A single line which contains YES or NO in uppercase.

Sample Input : 01

aaabbbb
Sample Output : 01

YES
Explanation 
A palindrome permutation of the given string is bbaaabb. 

Sample Input : 02

cdefghmnopqrstuvw
Sample Output : 02

NO
Explanation 
You can verify that the given string has no palindrome permutation. */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void findPalind(char*); 
void findPalind(char *arr)
{
     
    int flag;
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    int letter[256];
    memset(letter,0,sizeof(letter));
    int n=strlen(arr);
    int i,count=0;
    for(i=0;i<n;i++)
        letter[arr[i]]++;
    
    for(i=0;i<256;i++){
        if(letter[i]%2==1 || letter[i]==1)
            count++;
    }
    if(count==1 || count==0)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
