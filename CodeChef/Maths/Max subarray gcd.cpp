/* Problem Statement

Given an array of size 'N' of integers with each element denoted as array[i] . 
In this problem we are given a parameter 'K' and we are supposed to find the size of the largest contiguous subarray whose GCD is atleast 'K' 
If there is no subarray whose GCD is atleast 'K' , print 0
Constraints


1 <= N <= 500000 

1 <= array[i] , K <= 1000000
Input Format

The first line contains 2 integers 'N' and 'K' the size of the array and the parameter as described in the problem statement 
The second line containts 'N' space separated integers denoting the array
Output Format

Print a single integer in a single line denoting the maximum contiguous subarray size whose GCD is atleast 'K'
Sample

Input
5 9
10 20 5 15 45
Output
2
Explaination
GCD(1 , 2) is 10 and since its greater than 0 and there is no other subarray larger that this with GCD atleast 9 , so the answer is 2 . Alternatively the subarray (4 , 5) is also having GCD 15 but since it also has a size 2 the answer remains 2 only. 
Input
6 10
15 30 10 20 30 40
Output
5 
 
 Solution:
 Prerequisites : Binary Search , GCD Properties

Difficulty : Easy - Medium

Expected Complexity : O(N * logn * p) , p = max number of steps to calculate GCD.

Editorial :

The most basic property of GCD is : gcd(i , j , k) = gcd(i , gcd(j , k)). Also , gcd(i,gcd(j,k)) <= gcd(j,k). Most part of our solution is based on this.

The first thing we can see is that if a subarray of size Q has gcd value >= K , then we can for sure find a subarray of size < Q whose gcd value is >= K. Once we know this , we can binary search on the length of the subarray in the following way :

SOLVE(L , R):
    mid = (L + R + 1) / 2
    if poss(mid , K) :
        return SOLVE(mid , R)
    else :
        return SOLVE(L , mid - 1)
Now, we just need to create our poss() function , which takes in the length of subarray we are checking for and the minimum gcd value we are looking for as parameters. For every index i in [0,N - length] , we need to check if the subarray [i , i + length - 1] has a gcd value >= K. If there is any index which satisfies , we will return true. Else we return false.

To check , we could use a segment tree which stores gcd value for every segment. The overall complexity would be O(N * logn * logn * p) , which would eventually TLE as segment tree comes with a high constant factor. We can also calculate this in O(N * p) using a very simple trick.

Divide the entire array into blocks of "length of subarray". Maintain two arrays suffix and prefix. Suffix[i] denotes the value of gcd from [i .. j] , where j is the end index of the block in which i lies. Similarly , Prefix[i] denotes the value of gcd from [a .. i] , where a denotes the starting index of the block in which i lies. This can be calculated easily in linear time.

Now how does this exactly help us ? For any index i , we can calculate the GCD of the subarray [i .. i + length - 1] by calculating the gcd of [i .. j] and [j + 1 .. i + length - 1] , where j is the ending of the block in which i lies. Thus for every index i , gcd value is gcd(suffix[i] , prefix[i + length - 1]). Our poss() function works in O(N * p) and we are calling it at most logN times , hence the total time complexity is O(N * logN * p).  

We can perform a binary Search on answer

while l < r: mid = (l + r) / 2 if check(mid): l = mid + 1 else: r = mid

Now we just need to write an efficient check function Now suppose we want to check if any subarray of size 'X' exists which has GCD >= K , To do this , we divide the array in blocks of size 'X' and calculate the prefix and suffix GCD for each block , this will help us calculating the GCD of any block of size 'X' in O(1) time with O(N) pre processing. The complexity of this solution is O(N * LOGN * P) where P is time taken for calculating GCD  */

#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , k;
int arr[N];
int pre[N];
int suf[N];
int gcd(int a , int b){
    while(b){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
bool check(int val){
    for(int i = 1 ; i <= n ; i += val){
        int l = i;
        int r = min(n , i + val - 1);
        pre[l] = arr[l];
        for(int j = l + 1 ; j <= r ; ++j){
            pre[j] = gcd(pre[j - 1] , arr[j]);
        }
        suf[r] = arr[r];
        for(int j = r - 1 ; j >= l ; --j){
            suf[j] = gcd(suf[j + 1] , arr[j]);
        }
    }
    for(int i = 1 ; i + val - 1 <= n ; ++i){
        if(gcd(suf[i] , pre[i + val - 1]) >= k){
            return 1;
        }
    }
    return 0;
}
int solve(){
    int l = 1;
    int r = n + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l - 1;
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    printf("%d\n" , solve());