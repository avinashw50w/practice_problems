#include <stdio.h>
int main()
{
	int t,i;
	char str[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		int ans = 0;
		for(i=0;str[i];i++)
			if(str[i]=='A'||str[i]=='D'||str[i]=='O'||str[i]=='P'||str[i]=='Q'||str[i]=='R') ans++;
			else if(str[i]=='B') ans+=2;
			printf("%d\n",ans);
	}
	return 0;
} 
