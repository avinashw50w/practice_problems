/* Given NN integers, count the number of pairs of integers whose difference is KK.

Input Format

The first line contains NN and KK. 
The second line contains NN numbers of the set. All the NN numbers are unique.

Output Format

An integer that tells the number of pairs of integers whose difference is KK.

Constraints: 
N=10N=1055 
0<K<100<K<1099 
Each integer will be greater than 00 and at least KK smaller than 223131-1-1.

Sample Input

5 2  
1 5 3 4 2  
Sample Output

3
Explanation

There are 3 pairs of integers in the set with a difference of 2. */

#include<iostream>
#include<unordered_set>
using namespace std;

unordered_set<int> s;

int main()
{
    int n, k, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        s.insert(val);
    }
    int ans = 0;
    for (unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it)
        if (s.find(*it + k) != s.end()) ans++;
    cout << ans << endl;
    return 0;
}
