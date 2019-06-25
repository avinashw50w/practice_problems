/*Longest common subsequence with permutations allowed
Given two strings in lowercase, find the longest string whose permutations are subsequences of given two strings. 
The output longest string must be sorted.

Examples:

Input  :  str1 = "pink", str2 = "kite"
Output : "ik" 
The string "ik" is the longest sorted string 
whose one permutation "ik" is subsequence of
"pink" and another permutation "ki" is 
subsequence of "kite". 

Input  : str1 = "working", str2 = "women"
Output : "now"

Input  : str1 = "geeks" , str2 = "cake"
Output : "ek"
The idea is to count characters in both strings.

calculate frequency of characters for each string and store them in their respective count arrays, say count1[] for str1 and count2[] for str2.
Now we have count arrays for 26 characters. So traverse count1[] and for any index ‘i’ append character 
(‘a’+i) in resultant string ‘result’ by min(count1[i], count2[i]) times.
Since we traverse count array in ascending order, our final string characters will be in sorted order.*/

void longestString(string str1, string str2)
{
    int count1[26] = {0}, count2[26]= {0};
 
    // calculate frequency  of characters
    for (int i=0; i<str1.length(); i++)
        count1[str1[i]-'a']++;
    for (int i=0; i<str2.length(); i++)
        count2[str2[i]-'a']++;
 
    // Now traverse hash array
    string result;
    for (int i=0; i<26; i++)
 
        // append character ('a'+i) in resultant
        // string 'result' by min(count1[i],count2i])
        // times
        for (int j=1; j<=min(count1[i],count2[i]); j++)
            result.push_back('a' + i);
 
    cout << result;
}
 