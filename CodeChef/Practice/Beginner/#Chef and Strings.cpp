/*Chef likes playing with strings. The most interesting game are named "CHEF in string". The move of the game consists of the following: 
Chef takes a subsequence of string's letters that form the word "CHEF" and then he removes that symbols. The goal of the game is to make the maximal 
number of moves. Please, help Chef and tell him the maximal possible number of moves that he is able to make for the given string S.
Input

The first line of each test case contains a given string. This string consists of uppercase letters from the set {"C", "H", "E", "F"}.
Output

Output a single line containing the maximal possible number of moves.
Constraints

1 = |S| = 100000
Example

Input:
CHEFCHEFFFF

Output:
2

Input:
CHHHEEEFFCC

Output:
1*/

#include <stdio.h>
#define gc getchar_unlocked
int main(){
	long long int c=0, h=0, e=0, f=0;
	char s=gc();
	while(s!=-1){
		switch(s){
			case 'C' : c++; break;
			case 'H' : if(h<c) h++; break;
			case 'E' : if(e<h) e++; break;
			case 'F' : if(f<e) f++; break;
		}
		s=gc();
	}
	printf("%lld\n",f);
	return 0;
}
