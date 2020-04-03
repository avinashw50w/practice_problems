/*A Little Elephant from the Zoo of Lviv likes lucky strings, i.e., the strings that consist only of the lucky digits 4 and 7.

The Little Elephant has K favorite lucky strings A1, A2, ..., AK. He thinks that the lucky string S is good if either |S| ≥ 47 or for some j from 1 to K we have that Aj is a substring of S.

The Little Elephant has found N lucky strings B1, B2, ..., BN under the pillow. Now he wants to know which of them are good. Help him and find for each i from 1 to N whether the string Bi is good or not.

Notes.

Let S be some lucky string. Then
|S| denotes the length of the string S;
S[i] (1 ≤ i ≤ |S|) denotes the ith character of S (the numeration of characters starts from 1);
The string T of the length M is called a substring of S if for some k from 0 to |S| - M we have 
T[1] = S[k + 1], T[2] = S[k + 2], ..., T[M] = S[k + M].*/

bool check(string s, string a){
	int ls = s.size();
	int la = a.size();
	int cnt;
	rep(i,0,ls-la+1){
		cnt = 0;
		rep(j,0,la){
			if(s[i+j] == a[j]) cnt++;
		}
		if(cnt == la) return true;
	}
	return false;
}

int main() {
	int k,n,flag;
	string s, a[55];
	k=inp(); n=inp();
	rep(i,0,k) cin>> a[i];
	rep(i,0,n){
		flag=0;
		cin>>s;
		if(s.size() >= 47) { printf("Good\n"); continue; }
		rep(j,0,k) {
			if(s.find(a[j]) != string::npos) { flag=1; break; }
		}
		if(flag) printf("Good\n");
		else printf("Bad\n");
	}
	return 0;
}
