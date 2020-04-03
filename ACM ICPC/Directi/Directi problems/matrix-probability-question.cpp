/*A matrix probability question
Given a rectangular matrix, we can move from current cell in 4 directions with equal probability. 
The 4 directions are right, left, top or bottom. Calculate the Probability that after N moves 
from a given position (i, j) in the matrix, we will not cross boundaries of the matrix at any point.*/
#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for(int i=a;i<b;++i)
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

float findProb(int R, int C, int x, int y, int N) {

	if(x<0 or x>=R or y<0 or y>=C) return 0.0;

	if(N == 0) return 1.0;

	float prob = 0.0;

	REP(i, 0, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		prob += findProb(R, C, nx, ny, N-1) / 4.0;
	}

	return prob;
}

int main() {
	int R = 5, C = 5;

	int N = 2;

	int i = 1, j = 1;

	cout << findProb(R, C, i, j, N);
}

