/*Digory Kirke and Polly Plummer are two kids living next door to each other. The attics of the two houses are connected to each other through a passage. 
Digory's Uncle Andrew has been secretly doing strange things in the attic of his house, and he always ensures that the room is locked. Being curious, Digory suspects 
that there is another route into the attic through Polly's house, and being curious as kids always are, they wish to find out what it is that Uncle Andrew is secretly up to.

So they start from Polly's house, and walk along the passageway to Digory's. Unfortunately, along the way, they suddenly find that some of the floorboards are missing, 
and that taking a step forward would have them plummet to their deaths below.

Dejected, but determined, they return to Polly's house, and decide to practice long-jumping in the yard before they re-attempt the crossing of the passage. It takes them 
exactly one day to master long-jumping a certain length. Also, once they have mastered jumping a particular length L, they are able to jump any amount less than equal to L as well.

The next day they return to their mission, but somehow find that there is another place further up the passage, that requires them to jump even more than they had practiced for. 
So they go back and repeat the process.

Note the following:

At each point, they are able to sense only how much they need to jump at that point, and have no idea of the further reaches of the passage till they reach there. 
That is, they are able to only see how far ahead is the next floorboard.
The amount they choose to practice for their jump is exactly the amount they need to get across that particular part of the passage. That is, if they can currently jump 
upto a length L0, and they require to jump a length L1(> L0) at that point, they will practice jumping length L1 that day.
They start by being able to "jump" a length of 1.
Find how many days it will take them to cross the passageway. In the input, the passageway is described as a string P of '#'s and '.'s. A '#' represents a floorboard, 
while a '.' represents the absence of a floorboard. The string, when read from left to right, describes the passage from Polly's house to Digory's, and not vice-versa.

Input

The first line consists of a single integer T, the number of testcases.
Each of the next T lines consist of the string P for that case.

Output

For each case, output the number of days it takes them to cross the passage.

Constraints

1 ≤ T ≤ 1,000,000 (106)
1 ≤ |P| ≤ 1,000,000 (106)
The total length of P will be ≤ 5,000,000 (5 * 106)across all test-cases of a test-file
P will consist of only the characters # and .
The first and the last characters of P will be #.
Example

Input:
4
####
##.#..#
##..#.#
##.#....#

Output:
0
2
1
2*/
#include <bits/stdc++.h>
using namespace std;
#ifdef __WIN32__
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
inline int inp(){register int n,c;c=getchar_unlocked();while(c<'0' or c>'9')c=getchar_unlocked();
while(c>='0' and c<='9'){n = (n<<3) + (n<<1) + c-48;c = getchar_unlocked();}return n;}

char _str[10];
#define WRITE_INT(_x)	\
{register int _i = 0;int _tmp = (_x);do{*(_str + _i++) = _tmp % 10 + 48;_tmp /= 10;  \
} while (_tmp != 0);for (_i--; _i >= 0; _i--) putchar_unlocked(*(_str + _i));}	     \
typedef long long int ll;

int main() {
	int t=inp();
	int cnt, maxx, ans;
	char c;
	while(t--){
		maxx = ans = 0;
		while((c=getchar_unlocked())!='\n'){
			cnt = 0;
			while(c=='.'){ cnt++; c = getchar_unlocked(); }
			if(cnt>maxx){ maxx = cnt; ans++; }
		}
		WRITE_INT(ans);
		putchar_unlocked('\n');
	}
	return 0;
}
