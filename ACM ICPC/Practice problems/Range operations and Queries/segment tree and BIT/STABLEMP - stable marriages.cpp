/*There are given n men and n women. Each woman ranks all men in order of her preference (her first choice, her second choice, and so on). 
Similarly, each man sorts all women according to his preference. The goal is to arrange n marriages in such a way that if a man m prefers 
some woman w more than his wife, then w likes her husband more than m. In this way, no one leaves his partner to marry somebody else. 
This problem always has a solution and your task is to find one.

Input

The first line contains a positive integer t<=100 indicating the number of test cases. Each test case is an instance of the stable marriage 
problem defined above. The first line of each test case is a positive integer n<=500 (the number of marriages to find). The next n lines are 
the woman's preferences: ith line contains the number i (which means that this is the list given by the ith woman) and the numbers of men 
(the first choice of ith woman, the second choice,...). Then, the men's preferences follow in the same format.

Output

For each test case print n lines, where each line contains two numbers m and w, which means that the man number m and the woman number w 
should get married.*/

int ManPref[505][505], WomenPref[505][505];  // preference of each men and women
int Ranking[505][505];   // ranking of men as per each women
int CurrPartner[505];   // current partner of a woman
int NextNo[505];       // index of next prefered partner

int main() {
	int t; si(t);
	while(t--) {
		int N, m, w; si(N);
		rep(i,1,N+1){
			si(w);
			rep(j,1,N+1)
				si(WomenPref[w][j]);
		}

		rep(i,1,N+1){
			si(m);
			rep(j,1,N+1)
				si(ManPref[m][j]);
		}

		rep(i,1,N+1){
			rep(j,1,N+1)
				Ranking[i][WomenPref[i][j]] = j;
		}

		memset(CurrPartner, 0, sizeof(CurrPartner));

		queue<int> FreeMen;
		rep(i,1,N+1){
			FreeMen.push(i);
			NextNo[i] = 1;
		}

		while(!FreeMen.empty()) {
			m = FreeMen.front();
			w = ManPref[m][NextNo[m]++];
			if(CurrPartner[w] == 0){
				CurrPartner[w] = m;
				FreeMen.pop();
			}
			else if(Ranking[w][m] < Ranking[w][CurrPartner[w]]){
				CurrPartner[w] = m;
				FreeMen.pop();
				FreeMen.push(CurrPartner[w]);
			}
		}

		rep(w,1,N+1)
			printf("%d %d\n", CurrPartner[w], w);
	}
	return 0;
}

/*Stable Marriage Problem is the problem of finding a stable matching between two sets of elements given a set of preferences for each element. 
Formally, given a set M = {m1, m2, …, mn} of n men, a set W = {w1, w2, …, wn} of n women, a preference list (i.e., an ordering of n men) for 
each woman and a preference list (i.e., an ordering of n women) for each man, the problem is to find a set S of pairs (m,w) for some m ∈ M 
and w ∈ W such that

    Each m ∈ M and w ∈ W appears in exactly one pair in S
    If (m, w) ∈ S and (m’, w’) ∈ S, then it cannot be the case that m prefers w’ to w and w’ prefers m to m’

This problem comes up in several real-world scenarios from a self-enforcing college recruitment procedure to assignment of patients to 
hospitals. Mathematicians David Gale and Lloyd Shapley proved that, for any equal number of men and women, it is always possible to solve the
problem and make all marriages stable. The Gale-Shapley algorithm, as described in Algorithm Design by Kleinberg and Tardos, is as follows:

Initially all m ∈ M and w ∈ W are free
while ∃ m who is free and hasn't proposed to every woman:
  choose m
  Let w be the highest-ranked woman in m's preference list to whom m has not yet proposed
  if w is free:
    (m, w) become engaged
  elif w is currently engaged to m':
    if w prefers m' to m:
      m remains free
    else w prefers m to m':
      (m, w) become engaged
      m' becomes free
return the set S of engaged pairs*/
