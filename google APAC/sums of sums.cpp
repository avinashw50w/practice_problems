/*Alice presented her friend Bob with an array of N positive integers, indexed from 1 to N. She challenged Bob with many queries 
of the form "what is the sum of the numbers between these two indexes?" But Bob was able to solve the problem too easily.

Alice took her array and found all N*(N+1)/2 non-empty subarrays of it. She found the sum of each subarray, and then sorted 
those values (in nondecreasing order) to create a new array, indexed from 1 to N*(N+1)/2. For example, for an initial array 
[2, 3, 2], Alice would generate the subarrays [2], [3], [2], [2, 3], [3, 2], and [2, 3, 2] (note that [2, 2], for example, 
is NOT a subarray). Then she'd take the sums -- 2, 3, 2, 5, 5, 7 -- and sort them to get a new array of [2, 2, 3, 5, 5, 7].

Alice has given the initial array to Bob, along with Q queries of the form "what is the sum of the numbers from index Li to Ri, 
inclusive, in the new array?" Now Bob's in trouble! Can you help him out?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with one line with 
two space-separated integers N and Q, denoting the number of elements in the initial array and the number of Alice's queries. 
Then, there is one line with N space-separated integers, denoting the elements of Alice's initial array. Finally, there are Q 
more lines with two space-separated integers each: Li and Ri, the inclusive index bounds for the i-th query.

Output

For each test case, output one line with Case #x:, where x is the test case number (starting from 1). Then output Q more lines, 
each with one integer, representing the answers to the queries (in the order they were asked).

Limits

1 = T = 10.
1 = Q = 20.
1 = each element of the initial array = 100.
1 = Li = Ri = N*(N+1)/2.
Small dataset

1 = N = 103.
Large dataset

1 = N = 200000.
Sample


Input 
 	
Output 
 
1
5 5
5 4 3 2 1
1 1
1 10
1 15
3 8
4 11

Case #1:
1
45
105
26
48
In sample case #1, Alice's new array would be: [1, 2, 3, 3, 4, 5, 5, 6, 7, 9, 9, 10, 12, 14, 15].*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

long long int a[200005];
long long int tot=0,n;
long long int b[200005],small;

long long int cal(long long int index){
	long long int low=small,high=tot,mid,greater,equal,less,l1,eq1,i,j,ans;
	while(low<high)
	{
		j=0;
		less=0;
		equal=0;
		mid=(low+high)>>1;
		for(i=1;i<=n;i++)
		{
			while(j<i && (a[i]-a[j])>mid)
			{
				j++;
			}
			if(i!=j)
			{
				if((a[i]-a[j])==mid)
					less+=(i-j-1);
				else
					less+=(i-j);
			}
			if((a[i]-a[j])==mid)
				equal++;
		}
		if((less+equal)<index)
			low=mid+1;
		else
		{
			high=mid;
			l1=less;
			eq1=equal;
		}
	}
	ans=(index-l1)*low;
	j=0;
	for(i=1;i<=n;i++)
	{
		while(j<i && (a[i]-a[j])>low)
		{
			j++;
		}
		if(i!=j)
		{
			if((a[i]-a[j])<low)
			{
				ans=ans+(i-j)*a[i]-(b[i-1]-b[j-1]);
			}
			else
			{
				ans=ans+(i-j-1)*a[i]-(b[i-1]-b[j]);
			}
		}
	}
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	long long int t,T,q,i,j,k,sum,l,r,ans;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld %lld",&n,&q);
		a[0]=0;
		tot=0;
		
		small=200;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			small=min(small,a[i]);
			a[i]+=a[i-1];
			tot+=a[i];
			b[i]=tot;
		}
		printf("Case #%lld:\n",t);
		for(i=0;i<q;i++){
			scanf("%lld %lld",&l,&r);
			ans=cal(r)-cal(l-1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
