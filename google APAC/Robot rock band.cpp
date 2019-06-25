/*You're the manager of Xorbitant, the world's first robot rock band. There will be four positions in the band, and there are N robots 
auditioning for each position. (No robot is auditioning for more than one position.) Every robot has a number, and multiple robots might have 
the same number, just as two people can have the same name.

You know from market research that your robot audiences won't care how well the robot band members make music, how handsome they are, or what 
scandalous things the tabloids say about them. Instead, the audience will be checking to see whether the four members' numbers, when bitwise 
XORed together, equal a certain trendy number K.

How many different sets of four robots (one for each position) is it possible to choose so that the band will have this property? More 
specifically, given four lists A, B, C, D containing N numbers each, how many ways are there to choose one number a from list A, one number b 
from list B, and so on, such that a^b^c^d = K? (Here ^ represents the bitwise XOR operation.)

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each case begins with one line with two space-separated 
integers, N and K, as described above. Then, four more lines follow. Each has N space-separated integers and represents the ID numbers of the 
robots auditioning for a certain position in the band.

Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the number of different 
bands that meet the conditions.

Limits

1 ≤ T ≤ 10.
0 ≤ K ≤ 109.
0 ≤ all robot numbers ≤ 109.
Small dataset

1 ≤ N ≤ 50.
Large dataset

1 ≤ N ≤ 1000.
Sample


Input 
 	
Output 
 
2
2 3 
0 0
2 0
0 0
0 1
2 0
1 10
1 10
1 10
1 10

Case #1: 4
Case #2: 8
In sample case #1, in order to get a combined bitwise XOR of 3, the robot chosen from the second list must be 2, and the robot chosen from 
the fourth list must be 1. For the first and third lists, either of the two 0 robots can be chosen, so there are 2 * 2 = 4 possible bands that 
meet the criteria. Note that even though all of these bands are of the form (0, 2, 0, 1), they are considered different because the selections 
from the lists were different.*/
map<int,ll> m;
int a[4][1001];

int main() {
	#if 1
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	caset{
		printf("Case #%d: ",case_n++);
		m.clear();
		drii(n,k);

		rep(i,0,4) rep(j,0,n) si(a[i][j]);

		rep(i,0,n) rep(j,0,n) m[a[0][i]^a[1][j]]++;
		
		ll ans = 0;
		rep(i,0,n){
			rep(j,0,n){
				int x = k^a[2][i]^a[3][j];
				if(m.find(x) != m.end()) ans += m[x];
			}
		}
		printf("%lld\n", ans);
	}


	return 0;
}
