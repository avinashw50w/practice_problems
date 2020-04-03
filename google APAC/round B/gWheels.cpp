/*A typical mountain bike has two groups of gears: one group connected to the pedals, and one group connected to the rear tire. A gear group consists of many gears, 
which usually have different numbers of teeth. A chain connects one of the gears in the pedal gear group to one of the gears in the tire gear group, and this determines 
the ratio between the cyclist's pedaling speed and the tire speed. For example, if the chain connects a gear with 5 teeth on the pedals to a gear with 10 teeth on the tires, 
the ratio will be 1/2, since the cyclist needs to make the pedal gear rotate twice to make the tire rotate once. The cyclist can change the chain to connect any one gear 
from the pedal group to any one gear from the tire group.

You have just bought a special new mountain bike with three groups of gears: one connected to the pedals, one connected to the tire, and one extra group in between. 
This mountain bike has two chains; the first chain must always connect one gear from the pedal gear group to one gear on the extra gear group, and the second chain 
must always connect one gear from the extra gear group to one gear on the tire gear group. Moreover, the two chains cannot both use the same gear from the extra gear group.

Given the numbers of teeth on the available gears on the pedals, extra, and tire groups, is it possible to make the ratio (between pedaling speed and tire speed) be 
exactly P/Q? For a given set of gears, you may need to answer multiple such questions.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each begins with one line with 3 integers Np, Ne, and Nt, representing the numbers 
of gears on the pedals, extra, and tire groups. Then, three more lines follow. These contain Np, Ne, and Nt integers, respectively, representing the numbers of teeth 
on the different gears on the pedals, extra, and tire gear groups, respectively. (It is guaranteed that the numbers of teeth on the gears within a group are all distinct.) 
The next line after that consists of one integer, M, the number of questions. Finally, there are M lines, each with 2 integers, P and Q, representing the target ratio. 
(It is not guaranteed that this ratio is a reduced fraction.)

Output

For each test case, first output one line containing "Case #x:", where x is the test case number (starting from 1). Then output one line for each question within the 
test case, in the order that the questions were presented: Yes if it's possible to make the ratio P/Q, and No if it's impossible.

Limits

1 ≤ T ≤ 100.
1 ≤ the number of teeth on each gear ≤ 10000.
1 ≤ all values of P, Q ≤ 109.
1 ≤ M ≤ 10.
Small dataset

1 ≤ Np, Nt ≤ 10.
2 ≤ Ne ≤ 10.
Large dataset

1 ≤ Np, Nt ≤ 2000.
2 ≤ Ne ≤ 2000.
Sample


Input 
 	
Output 
 
1
1 2 3
5
4 6
3 5 7
2
1 1
5 2
Case #1:
No
Yes
For the first question in the test case, it's impossible to get the ratio 1/1 since this would require both chains to be on the same gear in the extra gear group, 
which is not allowed.

For the second question in the test case, you can make the first chain connect the 5-tooth gear on the pedal gear group to the 4-tooth gear on the extra gear group, 
and make the second chain connect the 6-tooth gear on the extra gear group to the 3-tooth gear on the tire gear group. With this setup, the ratio is 5/2.
ie, 5:4 :: 3:6  => 5/4 = 3/6  => 5/3 = 4/6. Now, store all the possible ratios of pedal to tyre gears int store1 and that of extra to extra gears in store2.

notice that (5/3)/(4/6) = 5/2 , => (5/3)/(5/2) = 4/6 , => (5/3) * (2/5) = 4/6 */

#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

int main(){

	int test;
	scanf("%d", &test);
	REP(i, 0, test){
		int NP, NT, NE;
		cin >> NP >> NE >> NT;
		vector<int> P(NP), T(NT), E(NE);

		REP(j, 0, NP){
			cin >> P[j];
		} REP(j, 0, NE) {
			cin >> E[j];
		} REP(j, 0, NT) {
			cin >> T[j];
		}

		map<ii, int> store1, store2;

		REP(a, 0, NP){
			REP(d, 0, NT){
				int num = P[a], den = T[d];
				int gcd = __gcd(num, den);
				num /= gcd, den /= gcd;

				store1[ii(num, den)];
			}
		}


		REP(b, 0, NE){
			REP(c, 0, NE){
				if(b == c) continue;
				int num = E[b], den = E[c];
				int gcd = __gcd(num, den);
				num /= gcd, den /= gcd;
				store2[ii(num, den)];
			}
		}


		printf("Case #%d:\n", i+1);
		int K;
		cin >> K;
		while(K--){
			int P, Q;
			cin >> P >> Q;
			string ans = "No";
			for(map<ii, int> :: iterator it = store1.begin(); it != store1.end(); it++){
				LL a = (it->first).first, b = (it->first).second;
				b *= P;
				a *= Q;
				LL gcd = __gcd(b, a);

				b /= gcd, a /= gcd;

				if(store2.count(ii(b, a))) { ans = "Yes"; break; }
			}
			cout << ans << endl;
		}
	}
	
	return 0;
}
