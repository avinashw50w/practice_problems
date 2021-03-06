/* Chota Pendrive likes to play with strings a lot. For a given string s, he obtains its compressed string in the following way:
In a single operation, he takes any two consecutive equal characters of s, and removes one of them.
He keeps doing this operation as long as possible.
The resulting string will be the compressed string of s. e.g. if the initial string is "abaaabb", its compressed form is "abab".
Two strings s and t are said to be similar if their compressed strings are equal.
You have to find the number of ordered pairs of similar strings (s, t) having length at least one and at most N. Both s, t contain lower case English alphabet. As the answer could be large, print it modulo 1000000007 (109 + 7).
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a single integer N.
Output
For each test case, print a single integer corresponding to the answer of the problem.
Constraints
1 = T, N = 5000
Sample
Input

2
1
2
Output

26
754
Explanation

In the first example,
s and t will be equal and will contain the same character. There are 26 possibilities for that from 'a' to 'z'.
In the second example, we can count the possible (s, t) similar pairs in the following way.
Case 1: s is same as t, there are 26 (each string contains 1 character) + 26 * 26 (each string contains 2 characters) possibilites for that.
Case 2: s is of type aa and t is of type a, where a is some character. There are 26 possible cases for this.
Case 3: s is of type a and t is of type aa, where a is some character. There are 26 possible cases for this.
So, in total, there are 26 + 26 * 26 + 26 + 26 = 754 ordered (s, t) pairs.  */


