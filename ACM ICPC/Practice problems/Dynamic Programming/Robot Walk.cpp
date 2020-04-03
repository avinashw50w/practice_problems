/*Chef has recently learned robotics and has now been able to construct a robot that's much better than his robots from last year. It's still 
somewhat limited, but it's definitely more flexible than before. Here are its properties:

The robot can only move forward towards the direction it faces, and can only face either horizontally or vertically.
The robot can only turn at 90 degree angles.
The robot is designed to turn exactly N times.
In addition, this robot is programmable. You can feed it 2N+1 values: a0, f1, a1, f2, a2, ..., fN, aN, where each ai is a positive integer and 
each fi is either L or R, and then it will perform the following actions:

Initially face north.
Move forward by a0 steps.
If f1 is L, turn left 90 degrees; if f1 is R, turn right 90 degrees.
Move forward by a1 steps.
If f2 is L, turn left 90 degrees; if f2 is R, turn right 90 degrees.
Move forward by a2 steps.
...
If fN is L, turn left 90 degrees; if fN is R, turn right 90 degrees.
Move forward by aN steps.
Now, Chef wants to test his new robot. Chef has already prepared the 2N+1 values to feed to the robot. However, Chef is very lazy and doesn't 
want to move, so he wants the robot to return to its starting point exactly. To do so, he can change some of the values, but some changes need 
time. Specifically,

Chef can increase or decrease any ai by 1, but this takes 1 second. Also, this change is only allowed if the new ai value is positive.
Chef can replace any fi by L or R. This takes 0 seconds.
Now, Chef wants to know the minimum number of seconds he needs to accomplish this task. Since Chef is lazy, he asks you to solve this problem 
for him.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N. The second line contains 2N+1 space-separated values 
a0, f1, a1, f2, a2, ..., fN, aN.*/

/*EXPLANATION:
Horizontal and vertical
The fact that you can only turn 9090 degrees either clockwise or counterclockwise tells us quite a few details about the directions of the 
iith movement. This is due to the fact that the iith movement is perpendicular to the (i+1)(i+1)th movement, which means:

The 00th movement is vertical. (In fact, it's always upward.)
The 11st movement is horizontal.
The 22nd movement is vertical.
The 33rd movement is horizontal.
The 44th movement is vertical.
etc.
And since we can select which way to turn at every point (at no cost), we can select which (vertical or horizontal) direction each movement 
goes to, except the 00th movement which is always upward. But we want the robot to return the starting point, which means the overall 
horizontal and vertical movement must be 0 individually. Formally, this is the same as giving signs to the movements so that the overall 
sum is 0.

This reduces our problem to two separate subproblems, one for the list [a0,a2,a4,…],and another for [a1,a3,a5,…].The subproblems are identical in nature:

Given a list [b1,b2,b3,…,bm], what is the minimum number of modifications needed so that it's possible to give signs to them 
so that the overall sum is 0.*/
/*========================================================================================*/
int N;
bitset<500 * 500> bit;

int solve(vector<int> &A){
	int S = accumulate(A.begin(),A.end(),0);
	bit.reset();
	bit[0] = 1;
	rep(i,0,A.size()) bit |= (bit<<A[i]);
	
	int ans = S;
	for(int i=S/2;i>=0;--i) // more the nearer to S/2 lesser will be the answer //
		if(bit.test(i)) {
			ans = S - 2*i; 
			break;
		}

	return ans;
}

int main() {
	caset{
		vector<int> A[2];
		int x; char c;
		si(N); 
		si(x); 
		A[0].push_back(x); 
		for(int i=0;i<N;++i) {
			scanf(" %c %d",&c, &x); // here space before %c is important to escape the space character before it //
			A[1-(i&1)].push_back(x);
		}

		if(N < 3) { printf("NO\n"); continue; }

		printf("%d\n", solve(A[0]) + solve(A[1]));
	}
	return 0;
}
