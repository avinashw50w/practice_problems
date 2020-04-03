/*Mike takes part in programming contests. His favourite topic is dynamic programming(DP). As he said, 
that he likes problems on DP, because "you spend a lot of time on thinking and a little time on coding".

In this problem you are to solve a version of the knapsack problem(link), one of the most famous examples of DP problem.

You are given N items, each has two parameters: a weight and a cost. Let's define M as the sum of the weights of all the items.

Your task is to determine the most expensive cost of a knapsack, which capacity equals to 1, 2, ..., M. 
A cost of a knapsack equals to the sum of the costs of all the elements of the knapsack. Also, when you have 
a knapsack with a capacity is equal to C, then you can fill it with items, whose sum of weights is not greater than C.

Input
The first line of the input contains one integer N, denoting the number of the items.

The next N lines contain two integers W and C each, denoting the weight and the cost of the corresponding item.

Output
For each capacity C (1 ≤ C ≤ M) of the knapsack, output a single integer - the most expensive cost for that capacity.

Constraints
3 ≤ N ≤ 100000;

1 ≤ W ≤ 2, for each item;

1 ≤ C ≤ 109, for each item.

Example
Input:
5
1 1
2 2
2 3
2 4
2 5

Output:
1 5 6 9 10 12 13 14 15 
Explanations
In the test case, M equals to 9.
For C = 1, it's optimal to choose {1} items;
For C = 2, it's optimal to choose {5} items;
For C = 3, it's optimal to choose {1, 5} items;
For C = 4, it's optimal to choose {4, 5} items;
For C = 5, it's optimal to choose {1, 4, 5} items;
For C = 6, it's optimal to choose {3, 4, 5} items;
For C = 7, it's optimal to choose {1, 3, 4, 5} items;
For C = 8, it's optimal to choose {2, 3, 4, 5} items;
For C = 9, it's optimal to choose {1, 2, 3, 4, 5} items.*/

const int mod = 1000000007;
const int MAXN = 100000+9;
 
vector<int> W1, W2; 
int N, W, C, TW;
 
ll ans[2 * MAXN];
 
void solve_for_even_weight(int start, int val) {
	ll C1, C2, tmp = val;
	int flag;
 
	for(int i=start; i<=TW; i+=2) {
		C1 = C2 = flag = 0;
 
		if(W2.size() >= 1) C2 = W2.back();
 
		if(W1.size() >= 2) C1 = W1.back() + W1[W1.size()-2], flag = 1; 
 
		else if(W1.size() == 1) C1 = W1.back();
 
		if(C2 > C1) tmp += C2, W2.pop_back(); 
		else {
			tmp += C1;
			if(flag) W1.pop_back(), W1.pop_back(); 
			else W1.pop_back();
		}
 
		ans[i] = tmp;
	}
}
 
int main() {
	BOOST;
	cin>>N;
 
	rep(i,0,N) {
		cin>>W>>C;
		if(W == 1) W1.push_back(C);
		else W2.push_back(C);
 
		TW += W;
	}
 
	sort(all(W1));
	sort(all(W2));
 
	vector<int> W1_cpy, W2_cpy;
	W1_cpy = W1;
	W2_cpy = W2;
 
	// for even weights //
	
	solve_for_even_weight(2, 0);
	
 
	// for odd weights //
 
	W1 = W1_cpy; 
	W2 = W2_cpy;
 
	if(W1.size() >= 1) ans[1] = W1.back(), W1.pop_back();
 
	solve_for_even_weight(3, ans[1]);
 
	rep(i,1,TW+1) cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
 
/*EXPLANATION
For a weight W, can you find the most expensive cost of the knapsack ?

Assume that W is even, we can first select the most expensive items with sum of weights <= 2. We can do his in following ways.

Take the most expensive item of weight 2.
Or take the at most two most expensive item of weight 1.
Note that after picking most expensive items with sum of weights <= 2, we will remove the items taken and will
 recursively select the items to fill the knapsack with most expensive elements.

Note that if W is odd, then we can simply select the most expensive knapsack of weight 1. 
Now we won't consider this item again. Now we have to select at most W - 1 most expensive weights from the remaining items. 
Note that W - 1 is even, we can solve this problem similar to previous problem.

Note that during finding the most expensive cost for the knapsack of weight W, we also find the answer for W - 2. 
So we can find answer for all the even W's in single iteration. We will use another iteration to find answer for odd weights. 
Please view the pseudo code to understand more about it.*/