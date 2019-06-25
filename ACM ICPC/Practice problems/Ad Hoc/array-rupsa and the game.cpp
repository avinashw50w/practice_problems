/*Princess Rupsa saw one of her friends playing a special game. The game goes as follows:

N+1 numbers occur sequentially (one at a time) from A0 to AN.
You must write the numbers on a sheet of paper, such that A0 is written first. The other numbers are written 
according to an inductive rule — after Ai-1 numbers have been written in a row, then Ai can be written at either 
end of the row. That is, you first write A0, and then A1 can be written on its left or right to make A0A1 or A1A0, and so on.
Ai must be written before writing Aj, for every i < j.
For a move in which you write a number Ai (i>0), your points increase by the product of Ai and its neighbour. 
(Note that for any move it will have only one neighbour as you write the number at an end).
Total score of a game is the score you attain after placing all the N + 1 numbers.
Princess Rupsa wants to find out the sum of scores obtained by all possible different gameplays. 
Two gameplays are different, if after writing down all N + 1 numbers, when we read from left to right, 
there exists some position i, at which the gameplays have aj and ak written at the ith position such that j ≠ k. 
But since she has recently found her true love, a frog Prince, and is in a hurry to meet him, 
you must help her solve the problem as fast as possible. Since the answer can be very large, print the answer modulo 109 + 7.

Input

The first line of the input contains an integer T denoting the number of test cases.
The first line of each test case contains a single integer N.
The second line contains N + 1 space-separated integers denoting A0 to AN.
Output

For each test case, output a single line containing an integer denoting the answer.
Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ Ai ≤ 109 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

int n, A[100000+2];
ll suffix_sum[100000+2];

int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n;
		
		for(int i=0;i<=n;++i) cin>>A[i];

		ll two = 1;

		for(int i=n; i>=0; --i) {
			suffix_sum[i] = (A[i] * two) % mod;

			if(i < n) suffix_sum[i]  = (suffix_sum[i] + suffix_sum[i+1]) % mod;

			two  = (two * 2) % mod;
		}

		ll ans = 0;
		two = 1;
		for(int i=0; i<n; ++i) {

			ll partial_sum = (A[i] * two)%mod;

			ans += partial_sum * suffix_sum[i+1];

			ans %= mod;

			if(i >= 1)
				two = (two*2)%mod;
		}

		cout << (2 * ans)%mod << endl;
	}
}

/*Subtask 1
Subtask 1 can be solved by directly simulating the given problem. In other words, we can directly append the number 
coming in at either ends and check the sum for each possible arrangement. There can at maximum be 2^N different sequences. 
Therefore, the time complexity is O(2^N) per test case. This is sufficient for this subtask.

Subtask 2
Let us start by thinking of simpler sequences in which observing patterns could be easier. 
A trick is to take something like 1, 1, 1, ...., 1, 5 as the sequence. 
And then the 5 can be shuffled around to different positions to observe how many times a position is taken into account.

Nevertheless, we are going to take a more mathematical approach in this editorial. 
Let's see what happens when kth number, i.e., A[k] appears in the stream. 
It can be appended to either of the two ends of the already existing sequence. 
But how many already existing sequence are there? Clearly, 2^(k−1). 
Let us say for now that A[k] is appended to the right of already existing sequence. 
Now, consider some pth number A[p] coming after A[k]. 
How many sequences exist such that the A[p] will be multiplied by A[k]? 
For A[p] to be multiplied by A[k], all numbers coming in between 
these two must not go to the side that A[k] is on, i.e., they should be put on the 
left in all the 2^(k−1) sequences where A[k] has been appended on the right. 
If this happens, then when A[p] comes, it will be multiplied by A[k] when placed 
on the right of it. The (p+1)th up till Nth numbers can be arranged in any order after that. 
So how many sequences in total will have the product of A[k] and A[p]? 
Clearly, 2^(k−1)*2^(N−p). Thus, total value that gets added to the answer is 
(A[k]*2^(k−1))*(A[p]*2^(N−p)).

We now have a way to calculate the required answer. Below is the pseudocode of the same.

let possible_future_prod[i] = A[i] * 2^(N-i)

let answer = 0; //accumulator variable
for i = 0 to N-1
{
    ways_to_arrange_prefix = 2^(i-1); //if i = 0, then 1

    //multipying A[i] with the number of possible prefixes
    partial_prod = (ways_to_arrange_prefix * A[i]);

    //iterating over elements coming after i
    for j = i+1 to N
    {
        total_prod = partial_prod * possible_future_prod[j];

        //adding total_prod to the accumulator variable
        ans += total_prod;
    }
}

//recall, we had only taken the case when an element is
//appended to the right.
//for taking symmetrical cases into account, multiply by 2.
return 2*ans
This algorithm runs in O(N^2).

Subtask 3
The algorithm stated in subtask 2 can be made O(N) by precalculating the suffix sum of the 
possible_future_sequences array. 
Once we have the suffix_sumsuffix_sum array, the inner loop given above in the pseudocode can be reduced to:

//calculating the suffix_sum array
suffix_sum[n] = possible_future_prod[n]
for i = N-1 downto 0
    suffix_sum[i] = possible_future_prod[i] + suffix_sum[i-1];

let answer = 0; //accumulator variable
for i = 0 to N-1
{
    ways_to_arrange_prefix = 2^(i-1); //if i = 0, then 1

    //multipying A[i] with the number of possible prefixes
    partial_prod = (ways_to_arrange_prefix * A[i]);

    //calculating the sum that can be achieved by
    //multiplying A[i] with numbers coming after it
    total_prod = (partial_prod * suffix_sum[i+1]);

    //adding total_prod to the accumulator variable
    ans += total_prod;
}

//for taking symmetrical cases into account, multiply by 2
return 2*ans*/