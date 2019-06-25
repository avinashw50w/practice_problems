/*Little kids, Jack and Evan like playing their favorite game Glass-and-Stone. 
Today they want to play something new and came across Twitter 
on their father's laptop. They saw it for the first time but were already getting 
bored to see a bunch of sentences having at most 140 characters each. 
The only thing they liked to play with it is, closing and opening tweets.
There are N tweets on the page and each tweet can be opened by clicking on it, 
to see some statistics related to that tweet. 
Initially all the tweets are closed. Clicking on an open tweet closes it and 
clicking on a closed tweet opens it. There is also a button to 
close all the open tweets. Given a sequence of K clicks by Jack, 
Evan has to guess the total number of open tweets just after each click. 
Please help Evan in this game.

Input

First line contains two integers N K, the number of tweets (numbered 1 to N) and 
the number of clicks respectively (1 ≤ N, K ≤ 1000). 
Each of the following K lines has one of the following.
CLICK X , where X is the tweet number (1 ≤ X ≤ N)
CLOSEALL

Output

Output K lines, where the ith line should contain the number of open tweets just after the ith click.

Example

Input:
3 6
CLICK 1
CLICK 2
CLICK 3
CLICK 2
CLOSEALL
CLICK 1

Output:
1
2
3
2
0
1*/

int main() {
	int n,k, cnt = 0, f[1010]={};
	string s;

	n=inp(); k=inp();
	
	while(k--){
		cin>>s;
		if(s == "CLICK"){
			int a=inp();
			f[a] = !f[a];
			if(f[a]) cnt++;
			else cnt--;
		}
		else { cnt = 0; memset(f, 0, sizeof(f)); }

		printf("%d\n", cnt);
	}
	return 0;
}
