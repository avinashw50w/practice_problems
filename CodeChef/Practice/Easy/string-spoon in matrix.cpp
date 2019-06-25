/* find the word spoon (it is case insesitive) in the matrix */
/*Constraints

1 ≤ T ≤ 100

1 ≤ R, C ≤ 100

Sample Input

3
3 6
abDefb
bSpoon
NIKHil
6 6
aaaaaa
ssssss
xuisdP
oooooo
ioowoo
bdylan
6 5
bdfhj
cacac
opqrs
ddddd
india
yucky
Sample Output

There is a spoon!
There is a spoon!
There is indeed no spoon!*/


string s[101];

int main() {
	int t, r, c;
	string pat = "spoon";
	t=inp();
	while(t--){
		r=inp();
		c=inp();
		rep(i,0,r) { cin >> s[i]; }
		bool found = false;
		rep(i,0,r){
			rep(j,0,c-4){
				int flag=0;
				rep(k,0,5){
					if((s[i][j+k] != pat[k]) && (s[i][j+k] != toupper(pat[k]))){
						flag = 1;
						break;
					}
				}
				if(!flag) { 
					found = true;
					break;
				}
			}
			if(found) break;
		}

		if(!found){
			rep(i,0,c){
				rep(j,0,r-4){
					int flag=0;
					rep(k,0,5){
						if((s[j+k][i] != pat[k]) && (s[j+k][i] != toupper(pat[k]))){
							flag = 1;
							break;
						}
					}
					if(!flag){
						found = true;
						break;
					}
				}
				if(found) break;
			}
		}

		if(found) puts("There is a spoon!");
		else puts("There is indeed no spoon!");
	}
	return 0;
}
