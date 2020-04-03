/*Chocolate Distribution Problem
Given an array of n integers where each value represents number of chocolates in a packet. Each packet can have variable 
number of chocolates. There are m students, the task is to distribute chocolate packets such that :

Each student gets one packet.
The difference between the number of chocolates in packet with maximum chocolates and packet with minimum chocolates 
given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} 
        m = 3
Output: Minimum Difference is 2
We have seven packets of chocolates and
we need to pick three packets for 3 students
If we pick 2, 3 and 4, we get the minimum
difference between maximum and minimum packet
sizes. */

/* sort the array and find the subarray of size m whose diff between the first and the last element is minimum */

int solve(int A[], int N, int M) {
	sort(A, A+N);

	int ans = INT_MAX;

	REP(i, 0, N-M+1)
		ans = min(ans, A[i+M-1] - A[i]);


	return ans;
}