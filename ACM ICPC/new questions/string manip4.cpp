/*Xenny had a list of N strings of equal length. He wanted to sort them by the first M characters only. 
That means, while sorting the list of strings, he only wanted to consider the first M characters of each string.
Help Xenny to find out the Kth string in the list after he sorts them.
First line contains a single integer - T, which represents the number of testcases.
T testcases follow.
Each testcase is of the following format:
First line contains 3 space-separated integers - N, K and M.
N is the total number of strings Xenny has.
K is the index of the string in the list after sorting, which Xenny has to find.
M is the number of characters based on which sorting will be done by Xenny.
Then next N lines contain N strings ( each line will contain one string ) .*/


int N,K,M;
bool comp(string a, string b) {
	return a.substr(0, M) < b.substr(0, M);
}

int main()
{
	string s;
	vector<string> v;
	
	int t; cin>>t;
	while(t--) {
		cin>>N>>K>>M;
		
		v.clear();
		for(int i = 0; i < N; ++i) {
			cin>>s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), comp);
		
		cout << v[K-1] << endl;
	}
    return 0;
}

///////////////////////////////////////////////////
// python

T = int(input())
for t in xrange(T):
	N, M, K = map(int, input().split())
	a = [input() for i in xrange(N)]
	a = sorted(a, key = lambda x: x[:M-1])
	print(a[K-1])

///////////////////////////////////////
//another one
t=input()
for x in xrange(t):
	n,k,m=map(int,raw_input().split())
	a,li=[],[]
	for i in xrange(n):
		a.append(raw_input())
		li.append((a[i][:m],i))
	li.sort()
	print a[li[k-1][1]]