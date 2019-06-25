#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char s[1000],ch;
//	scanf("%[^\n]",s);   it can also be used read a string with space between them
	fgets(s,1000,stdin);
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
