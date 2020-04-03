/*Given two integers ‘n’ and ‘m’, find all the stepping numbers in range [n, m]. A number is called stepping number if all adjacent digits have an absolute 
difference of 1. 321 is a Stepping Number while 421 is not.

Examples:

Input : n = 0, m = 21
Output : 0 1 2 3 4 5 6 7 8 9 10 12 21

Input : n = 10, m = 15
Output : 10, 12 */

/*he idea is to use a Breadth First Search/Depth First Search traversal.

How to build the graph?
Every node in the graph represents a stepping number; there will be a directed edge from a node U to V if V can be transformed from U. (U and V are Stepping 
Numbers) A Stepping Number V can be transformed from U in following manner.

lastDigit refers to the last digit of U (i.e. U % 10)
An adjacent number V can be:

U*10 + lastDigit + 1 (Neighbor A)
U*10 + lastDigit – 1 (Neighbor B)
By applying above operations a new digit is appended to U, it is either lastDigit-1 or lastDigit+1, so that the new number V formed from U is also a Stepping 
Number.
Therefore, every Node will have at most 2 neighboring Nodes.

Edge Cases: When the last digit of U is 0 or 9

Case 1: lastDigit is 0 : In this case only digit ‘1’ can be appended.
Case 2: lastDigit is 9 : In this case only digit ‘8’ can be appended.

What will be the source/starting Node?

Every single digit number is considered as a stepping Number, so bfs traversal for every digit will give all the stepping numbers starting from that digit.
Do a bfs/dfs traversal for all the numbers from [0,9].
Note: For node 0, no need to explore neighbors during BFS traversal since it will lead to 01, 012, 010 and these will be covered by the BFS traversal starting 
from node 1.*/

// using bfs //
void bfs(int n, int m, int num) {
	queue<int> q;

	q.push(num);

	while(!q.empty()) {
		int stepNum = q.front();
		q.pop();

		if(n<=stepNum and stepNum<=m) cout << stepNum << " ";

		if(num == 0 or stepNum>m) continue;

		int lastdigit = stepNum%10;

		int stepNumA = stepNum*10 + lastdigit - 1;
		int stepNumB = stepNum*10 + lastdigit + 1;

		if(lastdigit == 0) q.push(stepNumB);

		else if(lastdigit == 9) q.push(stepNumA);

		else {
			q.push(stepNumA);
			q.push(stepNumB);
		}
	}
}

// using dfs //
void dfs(int n, int m, int stepNum) {
	if(n<=stepNum and stepNum<=m) cout << stepNum << " ";

	if(stepNum == 0 or stepNum>m) return;

	int lastdigit = stepNum%10;

	int stepNumA = stepNum*10 + lastdigit - 1;
	int stepNumB = stepNum*10 + lastdigit + 1;

	if(lastdigit == 0) dfs(n, m, stepNumB);

	else if(lastdigit == 9) dfs(n, m, stepNumA);

	else {
		dfs(n, m, stepNumA);
		dfs(n, m, stepNumB);
	}
}

void displaySteppingNumbers(int n, int m) {

	for(int i = 0; i <= 9; ++i) bfs(n, m, i);
}