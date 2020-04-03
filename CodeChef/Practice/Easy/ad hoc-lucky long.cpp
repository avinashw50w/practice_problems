/*Chef loves lucky numbers. Everybody knows that lucky numbers are positive integers whose decimal representation contains only the lucky digits 4 and 7. 
For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
Chef has a positive integer N. He can apply any of the following operations as many times as he want in any order:
Add 1 to the number N.
Take some digit of N and replace it by any non-zero digit.
Add any non-zero leading digit to N.
Find the minimum number of operations that is needed for changing N to the lucky number.*/

inline int solve(){
	int cnt=0,c;
	c=getchar_unlocked();
	while(c<'0' or c>'9') c=getchar_unlocked();
	while(c>='0' and c<='9'){
		if(c!='4' and c!='7') cnt++;
		c=getchar_unlocked();
	}
	return cnt;
}
int main() {
	int t; si(t);
	while(t--){
		printf("%d\n", solve());
	}
	return 0;
}
