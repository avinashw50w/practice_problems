/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
/*
Note: This Google Doodle does not exactly match the rules of the Snake game we will describe below. It is only intended to give you a general idea of what the game looks like.

Alex just learned how to program and wants to develop his own version of Snake, with the following rules:

The game board has R rows and C columns. The top left cell of the board has coordinates (1, 1), and the bottom right cell has coordinates (R, C).
At the start of the game, in every cell with coordinates (r, c) such that r + c is odd, there is one piece of food. No other cells have food.
The snake's body is always an ordered, connected sequence of one or more cells on the board. The first cell of the sequence is called the "head" of the snake. The second cell (if any) shares an edge (not just a corner) with the first cell, and so on. The last cell in the sequence is called the "tail" of the snake.
The snake's head is always facing in one of four directions: left, up, right, or down.
At the start of the game, the snake is at cell (1, 1) and has a length of one (that is, the snake consists of only a head), and the head faces right.
At each integer time (1 second, 2 seconds, etc.), the head of the snake will move into the adjacent cell that its head is facing toward. The board is cyclic, i.e., trying to move off an edge will cause the head to appear on the opposite edge of the board. For example, if the snake is at (1, C) and its head is facing right, the head will next move to (1, 1). If the snake is at (1, C) and its head is facing up, the head will next move to (R, C).
When the snake's head moves into a cell with no food, the snake does not grow. The snake's second cell (if any) moves to the place where the snake's head was, the snake's third cell (if any) moves to the place where the second cell was, and so on.
When the snake's head moves into a cell with a piece of food, it eats the food (meaning that cell no longer has food), and grows its body. A new head is created in the cell where the food was. The cell that was the snake's head becomes the snake's second cell, the cell that was the snake's second cell (if any) becomes the snake's third cell, and so on.
If, after a move is complete, the snake's head is in the same place as one of another of its cells, the snake dies and the game ends immediately. (Note that if the snake's head moves toward a cell where its tail was, the game will not end, because the tail will move out of the way before the move is complete.)
In the game, the player can let the snake perform some turn actions. Each action Ai will happen between the Tith and Ti+1 th seconds. There are two possible actions: "L" and "R". An "L" action will turn the head 90 degrees to the left, so, for example, if the snake had been facing down before, it would face right after. An "R" action will turn the head 90 degrees to the right, so, for example, if the snake had been facing down before, it would face left after.
The game has a time limit: it will end after the move on the 109th second is complete (if the game has even gone on that long!)
To test the game, Alex has written a series of TURN actions. Your task is to simulate that series of actions, and tell Alex the final length of the snake when the game is over. Remember that the game can end either because the snake's head and another cell of its body are in the same place after a move is complete, or because time runs out. In the former case, you should count both the head and the overlapping cell of its body as two separate cells, for the purpose of determining length.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test cases starts with three integers S, R, and C, where S gives the number of turn actions and R and C represent the number of rows and columns of the board. S lines follow; the ith of these lines has an integer Xi, then a character Ai that is either L or R. Each of these lines corresponds to performing an action between Xith and Xi+1 th seconds. It's guaranteed that the actions are given in time order and there will never be more than one action between the same two seconds. However, you should note that the game may end before the snake gets to execute all of these actions.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the length of the snake when the game is over.

Limits

1 = T = 10.
Small dataset

1 = R, C = 100;
1 = S = 100;
1 = Xi = 2000.
Large dataset

1 = R, C = 100000;
1 = S = 100000;
1 = Xi = 1000000.

Input 
2
3 3 3
1 R
2 L
3 R
5 3 3
2 R
4 R
6 R
7 R
8 R
output
Case #1: 3
Case #2: 5

*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define MOD 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
deque<pii >Q;
set<pii >snake,food;
int alright,direction,T,R,C;
void play(){
	pii head = Q.front();
	pii to;
	switch(direction){
	case 1:
		to = mpa(head.fi-1,head.se);
		break;
	case 2:
		to = mpa(head.fi,head.se+1);
		break;
	case 3:
		to = mpa(head.fi+1,head.se);
		break;
	case 4:
		to = mpa(head.fi,head.se-1);
		break;
	}
	if(to.fi==0)
		to.fi=R;
	if(to.fi==R+1)
		to.fi=1;

	if(to.se==0)
		to.se=C;
	if(to.se==C+1)
		to.se=1;
	int x = to.fi;
	int y = to.se;
	if((x+y)%2==1 and food.find(to)==food.end()){
		food.insert(to);
		if(snake.find(to)!=snake.end()){
			alright=0;
			return;
		}
		Q.push_front(to);
		snake.insert(to);
	}
	else{
		pii tail = Q.back();
		if(snake.find(to)!=snake.end() and to!=tail){
			alright = 0;
			return;
		}
		snake.erase(tail);
		snake.insert(to);
		Q.pop_back();
		Q.push_front(to);
	}
}
int what[1000000+100000+5];
void init(){
	alright=1;
	direction = 2;

	T = 1000000+100000;
	for(int i=1;i<=T;++i)
		what[i]=0;
	while(not Q.empty())
		Q.pop_back();
	snake.clear();
	food.clear();
}
lld solve(){
	int S;
	init();

	Q.push_front(mpa(1,1));
	snake.insert(mpa(1,1));

	cin>>S>>R>>C;
	int t;
	char c;
	for(int i=1;i<=S;++i){
		cin>>t>>c;
		if(c=='R')
			what[t] = 1;
		else
			what[t] = -1;
	}
	for(int i=1;i<=T and alright;++i){
		play();

		if(what[i]!=0){
			direction = direction + what[i];
			if(direction==0)
				direction = 4;
			if(direction==5)
				direction=1;
		}
		//cout<<i<<' '<<direction<<endl;
		//cout<<i<<'\t'<<Q.front().fi<<' '<<Q.front().se<<'\t'<<Q.back().fi<<' '<<Q.back().se<<endl;
	}
	return Q.size();
}
int main()
{
	freopen("0.in","r",stdin);
	freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		printf("Case #%d: %lld\n",test,solve());
	}
}
