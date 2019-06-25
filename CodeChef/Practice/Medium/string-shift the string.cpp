/*You are given two strings A and B of the same length. Each string contains N Lower case Latin character (from 'a' to 'z'). A shift operation will remove the 
first character of a string and add the same character at the end of that string. For example after you perform a shift operation on a string 'abcd', the new 
string will be 'bcda'. If you perform this operation two times, the new string will be 'cdab'. You need to use some (maybe none) shift operations on the string 
B to maximize the length of the longest common prefix of A and B. If more than one result can be found pick the one that use smallest number of shift operations.

Input

The first line of the input contains a single integer N. The second and the third lind contains the string A and B respectively.

 

Output

Contains a single integer which is the number of shift operations.
1 ≤ N ≤ 106
Example

Input:
5
ccadd
bddcc

Output:
3  */

/*Let's say we append string B at the end of string B. We get: B1,B2...BNB1,B2...BN. The thing worth noting is that after K shift operations we get
 BK+1,BK+2...BN,B1,B2...BK. This string(which we get after K shift operations) is now a substring of the new string that we got by appending B at the end of B. 
So we'll now search all prefixes of A in B.B(means concatanation of B with B) which will help us in knowing which prefixes of A are present in B.B. 
Let's say we have to search a string A of length M in a string B of length N. What we can do is generate hash of all substrings of B which are of length M and 
search for hash of string A in the generated hashes. 
A hash function of string S could be say Summation[i=0 to length][26i*(S[i]-'a')] modulo some prime P. If we have the hash of a substring of length N say 
S[i,i+N], we can easily generate hash of S[i+1,i+N+1] by using inverse modulo since we are using a prime for modulo operations.

How to get 100 points
You need to know string matching algorithm KMP to get full points. You can learn KMP here, here, or anywhere you like to :).
KMP helps us in finding all prefixes of a string X in string Y. So we'll search A in B.B(means concatanation of B with B) which will help us in knowing which 
prefixes of A are present in B.B. We'll choose an answer that gives us the largest prefix, also it'll give the index at which that prefix matches, from which we 
can find the number of shifts required.*/


int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int N;
	string A, B;
	cin>> N;
	cin >> A >> B;

	B.append(B);

	// x = the amount of shift operations, 
	// i = the length of the prefix
	// shift = amount of shift operations
	// maxx = maximum length of prefix
	int i, j, k, x, shift=0, maxx=0;

	for(x = 0; x < N; x += i) { 
		i = j = 0;
		// find the first appearance of the 0th character of A in string B
		for(k = x; k < N; ++k) {
			if(B[k] != A[0]) x++;

			else break;
		}
		// if the 0th character of A is found in B 
		// continue comparing the other charcters
		for(k = x; k < 2*N; ++k) {
			if(B[k] == A[j++]) i++;
			else break;
		}
		// update the maximum length of the prefix and the number of shift operations 
		// required to do so.
		if(maxx < i) {
			maxx = i;
			shift = x;
		}
	}

	cout << shift << endl;

	return 0;
}
