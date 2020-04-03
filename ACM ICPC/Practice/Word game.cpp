/* Alex and Bob are playing a game of Atlas. As you might know, in this game both players take turns 
in naming a country starting with the same letter as the ending letter
 of the last country named by the other player. Only their game is slightly different.
In this game, there is a shared list of words (not necessarily a country), and both players can only pick from words listed here. 
To begin, Alex selects a word from the first K words listed in the array. Let's say he selects word a[i]. 
Then Bob selects a word from the next K entries in the array (ie. having index between i+1 and i+K inclusive)
such that Bob's word has the same starting letter as the last letter of word a[i]. The game continues in this manner. 
If at any point, a person cannot select any country, he loses.
Given the list of wordsA[], and integer K, your task is to tell who will win the game? 
Input

The first line of each test file contains a single integer T, the number of test cases. Then follow the T test cases.
The first line of every test case contains two integers N and K. Then N lines follow, where the ith line contains the word a[i]. 
The words contain only lowercase English alphabets.
Output

For each test case, print a single line containing the name of the player who will win the game, assuming both players play optimally.
Constraints

1 <= T <= 10
1 <= N <= 10^5
Length of word |a[i]| <= 10
Example

Input:
1
3 2
indian
programming
community

Output:
Alex
 
Input:
1
6 3
welcome
to
team
enigma
online
magic

Output:
Bob
 
Explanation

Example case 1. To begin, Alex can select either indian or programming. In either case, Bob can not continue the game and therefore loses the game.
Example case 2. To begin, Alex can select either welcome, to or team. In his turn, depending on what Alex picks, Bob can choose the word enigma, 
online or magic respectively. Alex will be left with no option after this. Bob will thus win the game.*/

int n, k;
char f[100010], l[100010];
bool dp[100010];
int cnt[26], cnt_lose[26];
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(NULL));
	#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#else
	/*freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);*/
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
	#endif
 
	int CASE;
	scanf("%d", &CASE);
	while (CASE--)
	{
		scanf("%d %d\n", &n, &k);
		for (int i = 1; i <= n; ++i)
		{
			char s[20];
			scanf("%s", s);
			int len = strlen(s);
			f[i] = s[0];
			l[i] = s[len - 1];
		}
 
		memset(dp, false, sizeof dp);
		memset(cnt, 0, sizeof cnt);
		memset(cnt_lose, 0, sizeof cnt_lose);
 
		dp[n] = true;
		++cnt_lose[f[n] - 'a'];
		++cnt[f[n] - 'a'];
		for (int i = n - 1; i >= 1; --i)
		{
			if (!cnt_lose[l[i] - 'a'])
				dp[i] = true;
			if (dp[i])
				++cnt_lose[f[i] - 'a'];
			++cnt[f[i] - 'a'];
			if (i + k <= n && dp[i + k])
				--cnt_lose[f[i + k] - 'a'];
			if (i + k <= n)
				--cnt[f[i + k] - 'a'];
		}
 
		bool good = false;
		for (int i = 1; i <= k; ++i)
			good |= dp[i];
		printf("%s", good ? "Alex\n" : "Bob\n");
	}
 
	my_return(0);
} 
Comments 

