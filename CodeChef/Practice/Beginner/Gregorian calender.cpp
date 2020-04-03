/* According to Gregorian Calendar, it was Monday on the date 01/01/2001. If any year is input, 
Write a program to display what is the day on the 1st January of this year. 
Input

The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer year.
Output

Display the day on the 1st January of that year in lowercase letter.
Constraints

1 = T = 1000
1900= A,B,C =2500
Example

Input

3 
1994
1991
2014

Output

saturday
tuesday
wednesday*/

#include <iostream>
#include <algorithm>
#define ll long long int
#define gc getchar_unlocked
inline ll input(){
	int n = 0;
	register int ch = gc();
	while(ch==' '||ch=='\n') ch = gc();
	while(ch>='0'&&ch<='9'){
		n = (n<<3)+(n<<1)+ch-48;
		ch = gc();
	}
	return n;
}

using namespace std; 

int main(){
	char *day[] = {"sunday\n",
				   "monday\n",
				   "tuesday\n",
				   "wednesday\n",
				   "thursday\n",
				   "friday\n",
				   "saturday\n"};
	int t=input();
	int offset;
	while(t--){
		int y = input();
		y--;
		offset = (1 + (y % 4) * 5 + ((y % 100) << 2) + (y % 400) * 6) % 7;
      fputs_unlocked(day[offset], stdout);
	}
	return 0;
}
