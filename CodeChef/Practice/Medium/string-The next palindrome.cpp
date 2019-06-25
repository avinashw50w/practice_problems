/*A positive integer is called a palindrome if its representation in the decimal system is the same when read from left to right and from right 
to left. For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output. 
Numbers are always displayed without leading zeros.

Input

The first line contains integer t, the number of test cases. Followed by t lines containing integers K.

Output

For each K, output the smallest palindrome larger than K.

Example

Input:
2
808
2133
Output:
818
2222*/

int main() {
	#if 0
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string s;
	caset{
		cin>>s;
		int n=s.size();

		// check for 99999999...
		int flag = 1;
		rep(i,0,n){ 
			if(s[i]!='9') { flag=0; break; } 
		}

		if(flag) { 
			cout<<1; 
			rep(i,0,n-1) cout<<0; 
			cout<<1 << endl; 
			continue; 
		}
		// end of case 99999999...

		flag = 0;
		rep(i,0,n>>1) {
			if(s[i] < s[n-i-1]) flag = -1;
			else if( s[i] > s[n-i-1]) flag = 1;

			s[n-i-1] = s[i];
		}

		int mid = (n&1) ? n/2: n/2-1;

		if(flag == 0 or flag == -1){
			int i = 0;
			while(s[mid-i] == '9'){
				s[n-(mid-i)-1] = s[mid-i] = '0';
				i++;
			}
			s[mid-i]++;
			s[n-(mid-i)-1] = s[mid-i];
		}
		cout << s << endl;
	}
	return 0;
}
