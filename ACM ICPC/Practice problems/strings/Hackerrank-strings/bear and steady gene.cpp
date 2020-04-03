/*A gene is represented as a string of length n(where n is divisible by 4), composed of the letters A, C, T, and G. It is considered to be steady if each 
of the four letters occurs exactly n/4 times. For example, GACT and  are both steady genes.

Bear Limak is a famous biotechnology scientist who specializes in modifying bear DNA to make it steady. Right now, he is examining a gene represented 
as a string s. It is not necessarily steady. Fortunately, Limak can choose one (maybe empty) substring of s and replace it with any substring of the same length.

Modifying a large substring of bear genes can be dangerous. Given a string S, can you help Limak find the length of the smallest possible substring 
that he can replace to make  a steady gene?

Note: A substring of a string  is a subsequence made up of zero or more consecutive characters of .

Input Format

The first line contains an interger  divisible by , denoting the length of a string . 
The second line contains a string  of length . Each character is one of the four: , , , .

Constraints

 is divisible by 
Subtask

 in tests worth  points.
Output Format

On a new line, print the minimum length of the substring replaced to make  stable.

Sample Input

8  
GAAATAAA
Sample Output

5
Explanation

One optimal solution is to replace a substring  with , resulting in . The replaced substring has length , so we print  on a new line.*/
#include <bits/stdc++.h>
using namespace std;
int n, cnt[4]={};
char s[500000+2];
const char g[5] = "ACTG";

int idx(int i){
    for(int k=0;k<4;++k){
        if(s[i] == g[k])
            return k;
    }
    return -1;
}

bool valid(){
    for(int i=0;i<4;++i){
        if(cnt[i] > n/4)
            return false;
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;++i)
        cnt[idx(i)]++;
    
    if(valid()){
        puts("0"); return 0;
    }
    
    int ans = n, i, j = 0;
    for(int i=0;i<n;++i){
        while(j<n and !valid())
            cnt[idx(j++)]--;
        if(valid()) ans = min(ans,j-i);
        cnt[idx(i)]++;
    }
    printf("%d\n",ans);
    return 0;
}
