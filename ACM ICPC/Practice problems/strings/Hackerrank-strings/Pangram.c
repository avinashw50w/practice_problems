/* Roy wanted to increase his typing speed for programming contests. So, his friend advised him to 
type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. 
(Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence s, tell Roy if it is a pangram or not.

Input Format

Input consists of a string s.

Constraints 
Length of s can be at most 103 (1≤|s|≤103) and it may contain spaces, lower case and upper case letters. Lower-case and upper-case instances of a letter are considered the same.

Output Format

Output a line containing pangram if s is a pangram, otherwise output not pangram.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char s[1000],ch;
	scanf("%[^\n]",s);   // read a string with space between them
	int l=strlen(s);
	int i=0,arr[26],index,total=0;
	for(i=0;i<26;i++)
	arr[i]=0;
	
	for(i=0;i<l;i++){
		ch=s[i];
		if('A'<=ch && ch<='Z')
		index = ch-'A';
		else if('a'<=ch && ch<='z')
		index = ch-'a';
		else
		continue;
		total+=!arr[index];
		arr[index]=1;
		
	}
	if(total==26)
	printf("pangram");
	else printf("not pangram");
	return 0;
	
}
