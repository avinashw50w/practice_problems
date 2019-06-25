/* Grapes of Coderpur are very famous. Devu went to the market and saw that there were N people selling grapes. He didn’t like it because things were not very structured. So, he gave a task to Dhinwa to make things better. If Dhinwa successfully completes the task, Devu will be happy.
Devu wants to change the number of grapes in a bucket of zero or more sellers in such a way that the GCD of all the number of grapes is divisible by K. Dhinwa can add or remove any number of grapes from each of the buckets. Adding or removing a grape will be counted as an operation. Also after the operation, none of the seller’s bucket should be empty.
Help Dhinwa in finding the minimum number of operations needed to make Devu happy.
Input

First line of input contains an integer T denoting the number of test cases.
For each test case, first line will contain an integer N denoting the number of buckets and integer K.
Next line contains N space separated integers denoting the number of grapes in each of the bucket.
Output

For each test case, print a single integer representing the answer of that test case.
Constraints

Subtask #1: 10 points
1 ≤ T ≤ 10, 1 ≤ N ,K ≤ 10, 1 ≤ number of grapes in a bucket ≤ 10
Subtask #2: 10 points
1 ≤ T ≤ 10, 1 ≤ N,K ≤ 100, 1 ≤ number of grapes in a bucket ≤ 100
Subtask #3: 80 points
1 ≤ T ≤ 10, 1 ≤ N ≤ 105, 1 ≤ K ≤ 109, 1 number of grapes in a bucket ≤ 109
Example

Input:
2
2 2
3 5
3 7
10 16 18

Output:
2
8
Explanation

For the first test case, add or remove 1 grape in each of the bucket.
For the second test case, remove three grapes in the first bucket, remove two grapes from the second bucket and add three grapes in the third bucket. 
Solution:
DIFFICULTY:
CAKEWALK

PREREQUISITES:
Greatest Common Divisor

PROBLEM:
Given an array A[] of n numbers and k. Find the minimum number of operation (adding or subtracting one from some array position) that should be performed on the array such that the gcd of all the numbers in the modified array is divisible by k.

EXPLANATION:
We are given an array A[], a number k and we can perform only one operation that is adding or subtracting one from some array position, repeatedly modifying the array until the gcd of all the numbers of the array is divisible by k. The problem is to find the minimum number of operation to achieve this. Note that if all the numbers in the array is already divisible by k, then we don't have to do anything and the answer will be 0.

Now consider the case where some numbers are not divisible by k (hence gcd is not divisible by k). In this case, pick up that number say a[i]=qk+r where r>0 and modify it to either qk or (q+1)k whichever takes minimum number of operations. One final point to note is that all the numbers in the modified array should be positive, so when a[i]<k, we can only increase its value to make it divisible by k. The time complexity of the above algorithm is clearly O(n). Refer to the following pseudo code for better understanding

for i = 0 to n
    r = a[i] mod k
    if(a[i] >= k) ans += min(r, k-r)
    else ans += k-r  
    */
    #include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    int t;
    cin>>t;
    assert(1<=t && t<=10);
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        assert(1 <= n && n <= 100000);
        assert(1 <= k && k <= 1000000000); 
        ll ans = 0;
        for(int i = 0 ; i< n ; i++)
        {
            ll x;
            cin>>x;
            if(!(0 <= x && x <= 1000000000))
                cout<<x<<endl;
            ans += min(x%k,k-x%k);
        }
        cout<<ans<<endl; 
    }
    return 0;
}
