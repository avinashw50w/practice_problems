#include<iostream>
#include<fstream>
#include<vector>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cmath>
#include<ios>
#include<ctime>
using namespace std;
 
int main() 
{
	vector <int> k(1000001,0);
	int T,j;
	long int n=0,bytes_read;
	char f;
	
	cin>>T;
	char buff[100000];
	while((bytes_read=fread(buff, 1, sizeof(buff), stdin))>0) 
	{
    for (j=0; j<bytes_read; j++) 
    {
    if (buff[j]=='\n') { k[n]++; n=0; }
    else n=n*10+(buff[j]-'0');
    }
    }
    k[n]++;
    k[0]--;
/*	while(T--)
	{
		cin>>n;
		k[n]++;
	}*/
	int i=0,m=0;
	while(i<k.size())
	{
	while(m<sizeof(buff)-10&&i<k.size())
	{
		if(k[i]>0)
		{
			if(i/1000000)
			{
				buff[m++]='0'+(i/1000000);
				buff[m++]='0'+(i%1000000)/100000;
				buff[m++]='0'+(i%100000)/10000;
				buff[m++]='0'+(i%10000)/1000;
				buff[m++]='0'+(i%1000)/100;
				buff[m++]='0'+(i%100)/10;
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i/100000)
			{
				buff[m++]='0'+(i/100000);
				buff[m++]='0'+(i%100000)/10000;
				buff[m++]='0'+(i%10000)/1000;
				buff[m++]='0'+(i%1000)/100;
				buff[m++]='0'+(i%100)/10;
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i/10000)
			{
				buff[m++]='0'+(i/10000);
				buff[m++]='0'+(i%10000)/1000;
				buff[m++]='0'+(i%1000)/100;
				buff[m++]='0'+(i%100)/10;
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i/1000)
			{
				buff[m++]='0'+(i/1000);
				buff[m++]='0'+(i%1000)/100;
				buff[m++]='0'+(i%100)/10;
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i/100)
			{
				buff[m++]='0'+(i/100);
				buff[m++]='0'+(i%100)/10;
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i/10)
			{
				buff[m++]='0'+(i/10);
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			else if(i)
			{
				buff[m++]='0'+(i%10);
				buff[m++]='\n';
			}
			k[i]--;
		}
		else
			i++;
	}
	fwrite(buff,sizeof(char),m,stdout);
	m=0;
	}
	return 0;
} 
