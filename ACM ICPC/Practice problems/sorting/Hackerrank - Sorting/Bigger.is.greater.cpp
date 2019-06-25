/* Given a word w, rearrange the letters of w to construct another word s in such a way that s is lexicographically greater than w.
 In case of multiple possible answers, find the lexicographically smallest one among them.

Input Format

The first line of input contains t, the number of test cases. Each of the next t lines contains w.

Constraints 
1≤t≤105 
1≤|w|≤100 
w will contain only lower-case English letters and its length will not exceed 100.

Output Format

For each testcase, output a string lexicographically bigger than w in a separate line. In case of multiple possible answers, print the lexicographically smallest one, and if no answer exists, print no answer.

Sample Input

5
ab
bb
hefg
dhck
dkhc
Sample Output

ba
no answer
hegf
dhkc
hcdk 
*/

#include <cmath>  
 #include <cstdio>  
 #include <vector>  
 #include <iostream>  
 #include <algorithm>  
 #include <string.h>  
 using namespace std;  
 int main() {  
   int t;  
   cin>>t;  
   while(t--){  
     char a[101];    
     cin>>a;  
     int n = strlen(a);  
     if(next_permutation(a,a+n)){  
       cout<<a<<endl;  
     }else{  
       cout<<"no answer"<<endl;  
     }  
   }  
   return 0;  
 }  