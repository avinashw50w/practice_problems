/*If there are W words, word 1 is swapped with word W, word 2 is swapped with word W-1 and so on. 
The problem is that Nobita himself cannot verify the answer for large strings. Help him write a program to do so.
SAMPLE INPUT 
1
hello world
SAMPLE OUTPUT 
world hello */


int main()
{
    vector<string> v;
   	int t; cin>>t;
   	cin.ignore();
   	while(t--) {
   		v.clear();
   		string s;
   	
   		getline(cin, s);
   		stringstream ss(s);
   		while(ss) {
   			string tmp;
   			ss >> tmp;
   			v.push_back(tmp);
   		}
   		
   		int l = 0, r = v.size()-1;
   		while(l < r) swap(v[l], v[r]), l++, r--;
   		
   		for(int i = 0; i < v.size(); ++i) cout << v[i] << " ";
   		cout << endl;
   	}
    return 0;
}
