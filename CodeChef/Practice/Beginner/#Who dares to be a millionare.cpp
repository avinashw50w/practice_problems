/* Chef is going to participate in a new quiz show: "Who dares to be a millionaire?"
According to the rules of the game, contestants must answer N questions. The quiz being famous for its difficulty, each question has 26 candidate answers,
 but only one of which is correct. Answers are denoted by capital Latin letters from A to Z. Chef knows all the questions that can be asked, and for each of 
 them he knows the answer candidate he will choose (some of them can be incorrect). For each question, we'll tell you Chef's answer to it.
The game goes on as follows. First, all the questions are shuffled randomly. Then, a contestant is asked these questions one-by-one in the new shuffled order. 
If the contestant answers any question incorrectly, the game is over. Total winnings of the contestant are calculated as follows. Let X denote the number of 
questions answered correctly by the contestant. Depending on this value, the winnings are determined: W0 dollars is the amount won for X = 0, W1 dollars is for X = 1,
 and so on till X = N. Note that the game was invented by a twisted mind, and so a case where Wi = Wi + 1 for some 0 = i = N - 1 is possible.
Chef is interested in finding the maximum possible winnings that he can amass.
Input

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of questions.
Next line contains N capital Latin letters denoting the correct answers to these questions.
Next line contains N capital Latin letters denoting answers given by Chef to these questions.
Next line contains N + 1 space-separated integers W0, W1, ..., WN denoting the winnings for 0, 1, ..., N correct answers.
Output

For each test case, output a single line containing the value of maximum possible winnings that Chef can get.
Constraints

1 = T = 500
1 = N = 1000
0 = Wi = 109
Subtasks

Subtask 1: (20 points)
1 = N = 8
Subtask 2: (80 points)
Original constraints
Example

Input:
3
5
ABCDE
EBCDA
0 10 20 30 40 50
4
CHEF
QUIZ
4 3 2 1 0
8
ABBABAAB
ABABABAB
100 100 100 100 100 100 100 100 100

Output:
30
4
100*/
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
	int t=input();
	string ans, chef_ans;
	while(t--){
		int n=input();
		cin>> ans >> chef_ans;
		int W[n+1];
		for(int i=0;i<=n;i++) W[i]=input();
		int maxx = 0,similar = 0,i;
		for(i=0;i<n;i++){
			if(chef_ans[i]==ans[i])
				similar++;
		}
		if(similar==n) cout << W[n] << endl;
		else cout << *max_element(W,W+similar+1) << endl;
	}
	return 0;
}

/* How to get 20 points
Let's generate all permutations of the order of the questions and calculate the score for each of them. Among the scores for all the orders, choose the maximal. 
Then just output the maximal obtained score. Since there are exactly N! permutations of the set of N questions and a check of a single order takes O(N) time, the complexity of such a solution is O(N!*N).

In C++ you can use STL routine next_permutation for simple generation of all the permutations.

This solution solves the first subtask, however, it is too slow to get the full points.

How to get 100 points
Let us calculate K - the number of the questions that would be answered correctly by Chef. Clearly, the ith question will be answered correctly 
if the ith sumbol in the first string equals to the ith symbol in the second string.

If K = N, there is no other option than Chef answers all the questions correctly and gets WN dollars of profit.

Otherwise, using any question than can be answered incorrectly, we can obtain any number of correct answers between 0 and K inclusively. 
Then the answer is, therefore, the maximal value of Wi for 0 = i = K.

The complexity of such a solution is O(N) for a single test case.*/
