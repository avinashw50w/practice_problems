/*There are many great athletes in the world, and it's very hard to say who is the best in the world at a particular sport, especially when different athletes have won different competitions. Here's one possible system for ranking athletes:

1. Determine the number P of finishing places in any competition that will be worth points for athletes, and how many points Si each of those finishing places is worth. For example, for P = 3, one possible assignment would be 1000 points for 1st place, 500 for 2nd place, and 300 for 3rd place, and 0 for anything below that. (We assume there are no ties within competitions.)

2. Since not all competitions are equally important, assign a weight Wi to each one. The score gained by an athlete for a competition will be the points from step 1, modified by the weight for that competition. For example, we may decide that Olympics has a weight of 5, and, continuing with our example from above, the winner of the Olympics would receive 5 * 1000 = 5000 points.

3. Since we don't want to reward athletes simply for participating in many competitions, we count only the M highest scores received by an athlete across all competitions. For example, if M = 2 and an athlete earns scores of 1000*5, 500*1, and 300*3 in three different competitions, only the 5000 and 900 would be counted.

You are given the points per finishing place, the weights of the competitions, and the results of the competitions. Can you rank all of the athletes who appeared in the competitions? If multiple athletes have the same score, they will share the same rank and listed in alphabetical order of their names.

Input

The first line of the input gives the number of test cases, T. T test cases follow; each test case consists of the following:

1. One line with an integer P, the number of top places for which points are awarded.
2. One line consists with P integers representing the scores Si for the top places, starting with first place and continuing down the places.
3. One line with an integer N, the number of competitions. 4. N lines, each of which represents a competition. Each line begins with Wi, the weight of this competition, and continues with the P names of the athletes who finished in the top P places. They are listed in descending order starting from first place.
5. One line with an integer M, the maximum number of competitions counted toward an athlete's score.
Output

For each test case, output one line containing "Case #x:", where x is the test case number (starting from 1). Then output one line for each athlete, from highest rank to lowest rank, with the format r: name, where r is the rank of the athlete and name is the name of the athlete. You need to rank all of the athletes that appeared in the input.
Limits

1 ≤ T ≤ 10.
1 ≤ Si ≤ 1000.
Si > Si+1.
1 ≤ Wi ≤ 1000.
Each name consists only of characters A through Z, and is at most 10 characters long.

Small dataset

1 ≤ P ≤ 10.
1 ≤ N ≤ 10.
1 ≤ M ≤ 10.
Large dataset

1 ≤ P ≤ 100.
1 ≤ N ≤ 100.
1 ≤ M ≤ 100.
Sample


Input 
 	
Output 
 
1
2
1000 500
6
5 BOLT GAY
4 GAY BOLT
1 GAY TIANBING
1 GAY PEIMENG
1 TIANBING LARRY
1 PEIMENG LARRY
2
Case #1:
1: BOLT
2: GAY
3: PEIMENG
3: TIANBING
5: LARRY
In the first case, Bolt scored a total of 7000 in his two competitions. Gay would have scored a total of 8500 if all competitions were counted, but since only the top 2 competitions are counted in this case, Gay scored 6500 and ranked second. Since Peimeng and Tianbing both scored 1500, they both ranked 3rd and listed by their names. Larry is last, since he scored only 1000.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; ++kase) {
		int p;
		cin >> p;
		vector<int> w(p);
		for(int i = 0; i < p; ++i)
			cin >> w[i];
		int n;
		cin >> n;
		map<string, vector<int>> scores;
		for(int i = 0; i < n; ++i) {
			int s;
			cin >> s;
			for(int j = 0; j < p; ++j) {
				string name;
				cin >> name;
				scores[name].push_back(s * w[j]);
			}
		}
		int m;
		cin >> m;
		vector<pair<int, string>> ranks;
		for(auto &it : scores) {
			sort(it.second.begin(), it.second.end(), greater<int>());
			int sum = 0;
			for(size_t i = 0; i < it.second.size() and i < m; ++i)
				sum += it.second[i];
			ranks.emplace_back(sum, it.first);
		}
		sort(ranks.begin(), ranks.end(), [](pair<int, string> a, pair<int, string> b) {
			if(a.first != b.first) return a.first > b.first;
			return a.second < b.second;
		});
		printf("Case #%d:\n", kase);
		int r = 0;
		for(size_t i = 0; i < ranks.size(); ++i) {
			if(i == 0 or ranks[i].first < ranks[i - 1].first)
				r = i + 1;
			printf("%d: %s\n", r, ranks[i].second.c_str());
		}
	}
	return 0;
}