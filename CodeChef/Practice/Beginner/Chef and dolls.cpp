/* Chef is fan of pairs and he likes all things that come in pairs. He even has a doll collection in which all dolls have paired.One day while going 
through his collection he found that there are odd number of dolls. Someone had stolen a doll!!!
Help chef find which type of doll is missing..
Input

The first line contains the number of test cases. 
Second line of the input contains the number of elements in the array. 
The next n lines are the types of each doll that is left.
Output

Find the type of doll that doesn't have a pair
Constraints

1<=T<=10 
1<=N<=100000 (10^5) 
1<=ti<=100000
Input:
1
3
1 
2
1


Output:
2
Input:
1
5
1
1
2
2
3
Output:
3

idea is to take the xor of all elements, the even no of elements will give 0 and the odd one will be the result */
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int t;cin>>t;
	while(t--){
		int n; cin>>n;
		int x = 0;
		while(n--){
			int a;cin>>a;
			x ^= a;
		}
		cout<< x <<endl;
	}
	return 0;
}


