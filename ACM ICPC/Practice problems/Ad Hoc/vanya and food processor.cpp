/*Vanya smashes potato in a vertical food processor. At each moment of time the height of the potato in the processor 
doesn't exceed h and the processor smashes k centimeters of potato each second. If there are less than k centimeters remaining, 
than during this second processor smashes all the remaining potato.

Vanya has n pieces of potato, the height of the i-th piece is equal to ai. He puts them in the food processor one by one 
starting from the piece number 1 and finishing with piece number n. Formally, each second the following happens:

If there is at least one piece of potato remaining, Vanya puts them in the processor one by one, 
until there is not enough space for the next piece.
Processor smashes k centimeters of potato (or just everything that is inside).
Provided the information about the parameter of the food processor and the size of each potato in a row, 
compute how long will it take for all the potato to become smashed.

Input
The first line of the input contains integers n, h and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ h ≤ 109) — 
the number of pieces of potato, the height of the food processor and the amount of potato being smashed each second, respectively.

The second line contains n integers ai (1 ≤ ai ≤ h) — the heights of the pieces.*/

#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll i,n,h,ans,x,cur_h,k;
int main()
{
	cin >> n >> h >> k;
	ans = 0;
	cur_h = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%I64d", &x);
		if (cur_h + x <= h)
		   cur_h += x;
		else
			ans++, cur_h = x;
		ans += cur_h/k;
		cur_h %= k;
	}
	ans += cur_h/k;
	cur_h %= k;
	ans += (cur_h>0);
	cout << ans << endl;
	return 0;
}