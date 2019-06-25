/*Steve has a string, s, consisting of  lowercase English alphabetic letters. In one operation, he can delete any pair of 
adjacent letters with same value. For example, string "aabcc" would become either "aab" or "bcc" after operation.

Steve wants to reduce  as much as possible. To do this, he will repeat the above operation as many times as it can be performed. 
Help Steve out by finding and printing 's non-reducible form!

Note: If the final string is empty, print Empty String .*/

#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    if(s == "") return "Empty String";
    
    string res = "";
    int cnt = 1, i;
    for(i = 1; i < s.size(); ++i) {
        if(s[i] == s[i-1]) cnt++;
        else
        {
            if(cnt&1) res += s[i-1];
            cnt = 1;
        }
    }
    if(cnt&1) res += s[i-1];
    
    if(res == s)
    	return res;
    else
     return super_reduced_string(res);
   
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}


/*Another solution : In this problem, to get the fully reduced string, we have to use stack. Suppose we are at ith character 
of string.Suppose we are at ith position of the string. If character at top of the stack is same as S[i] , 
we pop the top element of stack and move to i+1th position. Otherwise if stack is empty or top element 
of the stack is not equal to S[i] , we will push S[i] to top of the stack and then move to i+1th position. 
Our final answer is all the elements present in the stack from bottom to top. See the setter's code for implementation details.*/