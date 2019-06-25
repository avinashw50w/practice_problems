/* Given a squared sized grid G of size N in which each cell has a lowercase letter. Denote the character in the ith row and in the jth column as G[i][j].

You can perform one operation as many times as you like: Swap two column adjacent characters in the same row G[i][j] and G[i][j+1] for all valid i,j.

Is it possible to rearrange the grid such that the following condition is true?

G[i][1]≤G[i][2]≤⋯≤G[i][N] for 1≤i≤N and 
G[1][j]≤G[2][j]≤⋯≤G[N][j] for 1≤j≤N
In other words, is it possible to rearrange the grid such that every row and every column is lexicographically sorted?

Note: c1≤c2, if letter c1 is equal to c2 or is before c2 in the alphabet.

Input Format

The first line begins with T, the number of testcases. In each testcase you will be given N. The following N lines contain N lowercase english alphabet each, describing the grid.

Output Format

Print T lines. On the ith line print YES if it is possible to rearrange the grid in the ith testcase or NO otherwise.

Constraints 
1≤T≤100 
1≤N≤100 
Gij will be a lower case letter

Sample Input

1
5
ebacd
fghij
olmkn
trpqs
xywuv
Sample Output

YES
Explanation

The grid in the first and only testcase can be reordered to

abcde
fghij
klmno
pqrst
uvwxy
This fulfills the condition since the rows 1, 2, ..., 5 and the columns 1, 2, ..., 5 are all lexicographically sorted. */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        char grid[n+1][n+1];
        for(int i=0;i<n;i++){
             scanf("%s",grid[i]);
             sort(grid[i],grid[i]+n);
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(f) break;
            for(int j=0;j<n-1;j++){
                if(grid[j][i]>grid[j+1][i]){
                    f=1; break;
                }
            }
        }
        if(f==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
