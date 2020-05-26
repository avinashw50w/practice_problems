/*The Constitution of a certain country states that the leader is the person with the name containing the greatest number of different alphabet letters. 
(The country uses the uppercase English alphabet from A through Z.) For example, the name GOOGLE has four different alphabet letters: E, G, L, and O. The name 
APAC CODE JAM has eight different letters. If the country only consists of these 2 persons, APAC CODE JAM would be the leader.

If there is a tie, the person whose name comes earliest in alphabetical order is the leader.

Given a list of names of the citizens of the country, can you determine who the leader is?
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line with an interger N, the number of people 
in the country. Then N lines follow. The i-th line represents the name of the i-th person. Each name contains at most 20 characters and contains at least one 
alphabet letter.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the name of the leader.
Limits

1 ≤ T ≤ 100.
1 ≤ N ≤ 100.*/
bool comp(const pii& a, const pii& b){ if(a.first!=b.first) return a.first>b.first; return a.second<b.second;  }

int f[26];
void solve(){
	int n; cin>>n;
	string s;
	vector<pair<int,string> > v;
	
	cin.ignore();
	rep(i,0,n) {
		getline(cin,s);
		mset(f,0);
		rep(j,0,s.size()) {
			if(s[j]>='A' && s[j]<='Z') f[s[j]-'A']=1;
		}
		int cnt = 0;
		rep(k,0,26) if(f[k]) cnt++;
		v.push_back(make_pair(cnt, s));
	}
	
	sort(v.begin(), v.end(), comp);
	cout<< v[0].second << endl;
}
int main() {
	#if 1
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	caset{
		printf("Case #%d: ",case_n++ );
		solve();
	}

	return 0;
}
