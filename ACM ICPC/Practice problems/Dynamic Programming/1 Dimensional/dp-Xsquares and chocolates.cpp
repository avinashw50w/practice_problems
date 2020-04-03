/*The problem in a statement is - You are given a string consisting of 2 types of characters (S and C, can also be called binary string). You need to find the 
longest contiguous sequence of, which when divided into block of three characters, no block has all same characters.
Approach
The brute force solution ofcourse is to iterate over all possible start points and end points of the string and check to see if it is valid section or not. 
But the complexity of this approach would be O(n2) which is very slow for the constraints given. We need to device a linear time algorithm.

Because we need to find a contiguous section of a string, this section must defintely have an end point (and a start point of course). So what we can do is 
iterate over all points and check if it could be the end point to our answer - the longest contigous section. Okay, but how do we test for that possiblity? 
Firstly we need to check if the end point(here referred to as i) meets the condition specified in the problem :

NOT(s[i] == s[i - 1] && s[i - 1] == s[i - 2]).
If the last three characters are not same, then this could be the end point of the section.
But what's the start point? Because we assume here that i is an end point, the start point could be s[i - 2] (only 3 characters section), or may be even 
beyond that. So if s[i - 3] was a valid end point, we could simply extend that section to include the last three characters and make i as the end point. 
But do we really need to recompute this stuff?? No. You already had figured out that s[i - 3] is end point or not when you iterated over all end points before i. 
Just save those computed information and use it now - the basis of dynamic programming.

So the approach to solve the problem is - Maintain an array which save the length of the longest section for every end point; i.e. dp[i] = longest section 
found in the string s[0..i]. Iterate through all end points, If last three meets the condition, then extend the window of the section, i.e.dp[i] = 3 + dp[i - 3]. 
Finally take the maximum of the dp array to get the longest contiguous section.*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000+1;
char s[maxn];
int dp[maxn];

bool valid(char a, char b, char c) {
	return !((a == b) && (b == c));
}

int main() {
	int t; cin>>t;

	while(t--) {
		scanf("%s", s+1);

		int n = strlen(s+1);

		memset(dp, 0, sizeof(dp));

		for(int i=3; i<=n; ++i){
			if(valid(s[i], s[i-1], s[i-2]))
				dp[i] = 3 + dp[i-3];
		}

		int ans = *max_element(dp,dp+n+1);

		cout << ( n - ans ) << endl;
	}
}