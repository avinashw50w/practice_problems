/*Monk is a multi-talented person, and prepares results for his college in his free time. (Yes, he is still in love with his old college!) 
He gets a list of students with their marks. The maximum marks which can be obtained in the exam is 100.

The Monk is supposed to arrange the list in such a manner that the list is sorted in decreasing order of marks. 
And if two students have the same marks, they should be arranged in lexicographical manner.

Help Monk prepare the same!

Input format:
On the first line of the standard input, there is an integer N, denoting the number of students. 
N lines follow, which contain a string and an integer, denoting the name of the student and his marks.

Output format:
You must print the required list.

Constraints:
1 <= N <= 105
1 <= | Length of the name | <= 100 
1 <= Marks <= 100  */

bool comp(const pii &a,const pii &b){
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}
int main() {
	string s;
	int n,m;
	vector<pii> v;
	si(n);
	while(n--){
		cin>>s; si(m);
		v.push_back(make_pair(s,m));
	}
	sort(v.begin(),v.end(),comp);
	rep(i,0,v.size()){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}
