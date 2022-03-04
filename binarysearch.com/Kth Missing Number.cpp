/*Given a list of sorted unique integers nums and an integer k, return the kth (0-indexed) 
missing number from the first element of the list.

Constraints

n ≤ 100,000 where n is the length of nums.
Example 1
Input
nums = [5, 6, 8, 9]
k = 0
Output
7
Explanation
7 is the first missing number.

Example 2
Input
nums = [5, 6, 8, 9]
k = 3
Output
12
Explanation
The first four missing numbers are [7, 10, 11, 12]*/
int solve(vector<int>& a, int k) {
    int n = a.size();
    k++;
    for (int i = 0; i < n-1; ++i) {
        int j = a[i]+1;
        while (k && j < a[i+1]) j++, k--;
        if (k == 0) return j-1;
    }

    return a[n-1] + k;
}