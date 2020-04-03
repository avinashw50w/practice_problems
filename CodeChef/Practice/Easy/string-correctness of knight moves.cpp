/*Chef develops his own computer program for playing chess. He is at the very beginning. At first he needs to write the module that will receive moves written by the players and analyze it. The module will receive a string and it should report at first whether this string represents the correct pair of cells on the chess board (we call such strings correct) and then report whether it represents the correct move depending on the situation on the chess board. Chef always has troubles with analyzing knight moves. So at first he needs a test program that can say whether a given string is correct and then whether it represents a correct knight move (irregardless of the situation on the chess board). The cell on the chessboard is represented as a string of two characters: first character is a lowercase Latin letter from a to h and the second character is a digit from 1 to 8. The string represents the correct pair of cells on the chess board if it composed of 5 characters where first two characters represent the cell where chess figure was, 3rd character is the dash "-" and the last two characters represent the destination cell.

Input

The first line contains a single integer T <= 50000, the number of test cases. T test cases follow. The only line of each test case contains a non-empty string composed the characters with ASCII-codes from 32 to 126. The length of the string is not greater than 10.

Output

For each test case, output a single line containing the word "Error" if the corresponding string does not represent the correct pair of cells on the chess board. Otherwise output "Yes" if this pair of cells represents the correct knight move and "No" otherwise.

Example

Input:
4
a1-b3
d2-h8
a3 c4
ErrorError

Output:
Yes
No
Error
Error*/

void doThis(){
   char line[15];
	int diffx,diffy;
		gets(line);
		if(((line[0]>='a') && (line[0]<='h')) && ((line[1]>='1') && (line[1]<='8')) && (line[2]=='-') && 
			((line[3]>='a') && (line[3]<='h')) && ((line[4]>='1') && (line[4]<='8')) && (line[5]=='\0'))
		{
			diffx=line[3]-line[0];
			diffy=line[4]-line[1];
			if(diffx<0)
				diffx*=-1;
			if(diffy<0)
				diffy*=-1;
			if(((diffx==2) && (diffy==1)) || ((diffx==1) && (diffy==2)))
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("Error");
}

int main() {
	char s[15];
	int t; scanf("%d",&t);
	getchar();
	while(t--){
		doThis();
	}
	return 0;
}
