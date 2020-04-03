/* Sorting is often useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses, as well.

Challenge 
Given a list of unsorted integers, A={a1,a2,…,aN}, can you find the pair of elements that have the smallest absolute difference between them? If there are multiple pairs, find them all.

Input Format 
The first line of input contains a single integer, N, representing the length of array A. 
In the second line, there are N space-separated integers, a1,a2,…,aN, representing the elements of array A.

Output Format 
Output the pairs of elements with the smallest difference. If there are multiple pairs, output all of them in ascending order, all on the same line (consecutively) with just a single space between each pair of numbers. If there's a number which lies in two pair, print it two times (see the sample case #3 for explanation).

Constraints

2≤N≤200000
−107≤ai≤107
ai≠aj,where 1≤i<j≤N
Sample Input #1

10
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 
Sample Output #1

-20 30
Explanation 
(30) - (-20) = 50, which is the smallest difference.

Sample Input #2

12
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854 -520 -470 
Sample Output #2

-520 -470 -20 30
Explanation 
(-470) - (-520) = 30 - (-20) = 50, which is the smallest difference.

Sample Input #3

4
5 4 3 2
Sample Output #3

2 3 3 4 4 5
Explanation 
Here, the minimum difference will be 1. So valid pairs are (2, 3), (3, 4), and (4, 5). So we have to print 2 once, 3 and 4 twice each, and 5 once */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    unsigned int n;
    int64_t *a;
    
    cin>>n;
    
    if( n == 0) return 0;
    
    a = new int64_t[n];
    
    for(unsigned int i = 0 ; i < n; i++){
        cin>>a[i];
    }
    if( n == 1){
        cout<<a[0];
        delete[] a;
        return 0;
    }
  
    sort(a,a+n);
    int64_t mini = (1<<30);
    for(unsigned int i = 1 ; i < n;i++){
        int64_t curMin = abs(a[i-1] - a[i]);
        mini = min(mini,curMin);
        
    }
    
    for(unsigned int i = 1; i < n; i++){
        if(abs(a[i-1] - a[i]) == mini){
            cout<<a[i-1]<<" "<<a[i]<<" ";
        }
    }
    delete[] a;
    return 0;
}
