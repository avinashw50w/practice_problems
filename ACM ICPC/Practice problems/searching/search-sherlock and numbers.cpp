/*Watson gives to Sherlock a bag of numbers [1, 2, 3 ... N] and then he removes K numbers A1, A2 ... AK from the bag. He now asks Sherlock to find the P'th 
smallest number in the bag.

Input
First line contains T, the number of test cases. Each test case consists of N, K and P followed by K integers in next line denoting the array A.

Output
For each test case, print P'th smallest number in the bag. If no such number exists output -1.

Constraints
1 ≤ T ≤ 10
20% testdata: 1 ≤ N ≤ 103
20% testdata: 1 ≤ N ≤ 105
60% testdata: 1 ≤ N ≤ 109
0 ≤ K ≤ min(N, 105)
1 ≤ P ≤ N*/

/*
Problem Description

Mathematically, the problem can be formulated as : Let S be a set of first N natural numbers, i.e. S = {1, 2,..., N} and S' = {A1, A2.. Ak} be another set. 
Then, find the Pth smallest number in the set S - S'.

The naive approach is certainly to make an array of first N numbers, and mark all the numbers from S' in the array. Run another loop, decrementing P's value 
everytime an unmarked cell is seen in the array. When the value of P becomes 0, we get the desired answer.

Sounds good, but eh, the value of N can be upto 109, and unfortunately, we aren't given so much memory to play with. Of course we can modify the algorithm to 
run nested for loops, in order to avoid the array part, but then that would take too much of time. In such situation, we should try taking hints from the 
problem constraints. The value of K can be upto 105, which means we can run a linear time algorithm (or may be even O(KlogK)) and get to our goal.

Okay, so now that we know we need to do something with the K element array A, lets sort it first. We do this for a reason that will be clear in this paragraph. 
After renumbering our variables, A1 is the smallest, while AK is the largest. We can now traverse A, from smallest to largest, and at each instance, increase 
the count of the numbers we have seen. For eg, if A was {3, 5, 9}, then at first iteration, we have already seen (3 - 0 - 1) = 2 numbers. At 2nd iteration, 
we see (5 - 3 - 1 = 1) more number, and finally (9 - 5 - 1 = 3) numbers. So if P was, say, 5, then at the 3rd iteration, we know that our number belongs to 
the range (5, 9), more precisely, the 2nd number in this range.*/

int main() {
	caset{
		int n, k, p;

		cin>>n>>k>>p;

		int a[k+1];

		rep(i,1,k+1) cin>>a[i];

		a[0] = 0;

		sort(a, a+k+1);

		int i;

		for(i=1; i<=k; ++i) {
			int c = a[i] - a[i-1] - 1;
			if(p <= c) {
				break;
			}
			else p -= c;
		}
		if(a[i-1] + p <= n) cout<< a[i-1] + p;
		else cout<<-1;
		cout<<endl;
	}
	
	return 0;
}
