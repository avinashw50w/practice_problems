/*The game is simple and is played on a piece of paper. Sumit writes down a long list of names on that paper and passes it to Rohil. 
Rohil gets confused on seeing so many names on that paper and asks Sumit about the game. So, Sumit explains him the rules of the game. 
Rohil is supposed to partition the names into groups, such that:

Each name belongs to exactly one group.
Names that belong to the same group are pairwise anagrams.
The first character of all the names in the same group are equal.
The last character of all the names in the same group are equal.
The number of groups is minimum possible.

Input:
The first line contains a single integer N indicating the size of the list. This is followed by N lines where each line contains a name listed by Sumit.

Output:
In a single line print minimum number of groups in a partition that satisfy above conditions*/

set<string>s;
set<string>::iterator it,it1,it2;
int main(){
	int i,n;
	string name;
	cin>>n;
	int cnt=0;
	while(cin>>name){
		cnt++;
		s.insert(name);
		}
	
	for(it=s.begin();it!=s.end();it++){
		name=*it;
		it1=it;
		it1++;
		string sortname=name;
		sort(all(sortname));	
		while(it1!=s.end()){
			string tmp=*it1;
			
			if(name.length()!=tmp.length()){
				it1++;
				continue;
			}
			if(name[0]!=tmp[0]){
				it1++;
				continue;
			}
			if(name[name.length()-1]!=tmp[tmp.length()-1]){
				it1++;
				continue;
			}
			sort(all(tmp));
			if(sortname==tmp){
				it2=it1;
				it2++;
				s.erase(it1);
				it1=it2;
			}
			
		}
		
	}
		
	cout<<s.size()<<endl;
//	fclose(stdout);
	return 0;
}