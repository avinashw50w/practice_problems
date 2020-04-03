#include <stdio.h>
#include <stdlib.h>
 
int *counts;
int *start;
int *end;
 
 
inline void scanint(int* x)
{
	register char c = getchar_unlocked();
	*x = 0;
	for(; (c<48)||(c>57);c = getchar_unlocked());
	for(; (c>47)&&(c<58);c = getchar_unlocked())
		*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);
}
 
int main()
{
	int T,N,H,i,l;
	long long int h,max;
	counts = (int*)malloc(sizeof(int)*1000010);
	start = (int*)malloc(sizeof(int)*1000010);
	end = (int*)malloc(sizeof(int)*1000010);
	scanint(&T);
	while(T--)
	{
		scanint(&N);
		scanint(&H);
 
		for(i = 0; i < N; ++i)
			counts[i] = start[i] = end[i] = 0;
 
		for(i = 0; i < N; ++i)
		{
			scanint(&l);
			++start[l];
			scanint(&l);			
			++end[l];
		}
 
		l = 0;
		for(i = 0; i < N; ++i)
		{
			l += start[i];
			counts[i] = l;
			l -= end[i];
		}
 
		h = 0;
		for(i = 0; i < H; ++i)
			h += (long long int)counts[i];
		max = h;
 
		for(i = H; i < N; ++i)
		{
			h += (long long int)counts[i] - counts[i-H];
			if(h > max) max = h;
		}
		printf("%lld\n", ((long long int)N*H) - max);
	}
 
	free(counts);
	free(start);
	free(end);
	return 0;
}
