/* Tomya is a girl. She loves Chef Ciel very much.
Tomya like a positive integer p, and now she wants to get a receipt of Ciel's restaurant whose total price is exactly p. The current menus of Ciel's restaurant are shown the 
following table.
Name of Menu	price
eel flavored water	1
deep-fried eel bones	2
clear soup made with eel livers	4
grilled eel livers served with grated radish	8
savory egg custard with eel	16
eel fried rice (S)	32
eel fried rice (L)	64
grilled eel wrapped in cooked egg	128
eel curry rice	256
grilled eel over rice	512
deluxe grilled eel over rice	1024
eel full-course	2048
Note that the i-th menu has the price 2i-1 (1 = i = 12).
Since Tomya is a pretty girl, she cannot eat a lot. So please find the minimum number of menus whose total price is exactly p. Note that if she orders the 
same menu twice, then it is considered as two menus are ordered. (See Explanations for details)
Input

The first line contains an integer T, the number of test cases. Then T test cases follow. Each test case contains an integer p.
Output

For each test case, print the minimum number of menus whose total price is exactly p.
Constraints

1 = T = 5
1 = p = 100000 (105)
There exists combinations of menus whose total price is exactly p.*/
#include <cstdio>
using namespace std;
void solve(int i){
	int ans = 0;
	if(i>=2048) ans += i/2048, i %= 2048;
	if(i>=1024) ans += i/1024, i %= 1024;
	if(i>=512) ans += i/512, i %= 512;
	if(i>=256) ans += i/256, i %= 256;
	if(i>=128) ans += i/128, i %= 128;
	if(i>=64) ans += i/64, i %= 64;
	if(i>=32) ans += i/32, i %= 32;
	if(i>=16) ans += i/16, i %= 16;
	if(i>=8) ans += i/8, i %= 8;
	if(i>=4) ans += i/4, i %= 4;
	if(i>=2) ans += i/2, i %= 2;
	ans += i;
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}

//////////////////////////////////////////////////

int main(){
	int price[] = {2048,1024,512,256,128,64,32,16,8,4,2};
	int t;cin>>n;
	while(t--){
		int n;cin>>n;
		int ans = 0;
		for(int i=0;i<11;++i){
			if(n>=price[i]){
				ans += n/price[i];
				n %= price[i];
			}
		}
		ans += n;
		cout<< ans <<endl;
	}
}
