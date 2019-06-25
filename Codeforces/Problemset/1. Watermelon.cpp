/*Pete and Billy are great fans of even numbers, that's why they want to divide the watermelon in 
such a way that each of the two parts weighs even number of kilos, at the same time it is not 
obligatory that the parts are equal. The boys are extremely tired and want to start their meal 
as soon as possible, that's why you should help them and find out, 
if they can divide the watermelon in the way they want. 
For sure, each of them should get a part of positive weight.

Input
The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) — the weight of the watermelon bought by the boys.

Output
Print YES, if the boys can divide the watermelon into two parts, each of them weighing even number of kilos; and NO in the opposite case.

Examples
inputCopy
8
outputCopy
YES*/

#include <iostream>
using namespace std;

int  main() {
	int w; cin >> w;
	if (w > 2 and (w&1) == 0) cout << "YES\n"; else cout << "NO\n";
}