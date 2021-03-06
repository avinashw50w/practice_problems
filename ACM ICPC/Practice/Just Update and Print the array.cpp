/* You are given a 1-indexed array of size N. Initially, all elements of the array are zeros. You need to perform U updates to the array.
Each Update asks you to add 1 to the elements of the array at the indices specified by 'ax+b' for all non-negative integers x, where a and b are 
positive integers which specify an update query.
After performing all the updates to the array, print the array with every entry separated by space.
Input

First Line of the input contains 2 space separated integers N, U.
Each of the next U lines contains 2 space-separated integers: a and b, specifying an update.
Output

Output the array in a single line after all updates.
Constraints

1 = N = 105
1 = a, b = N
1 = U = 2*105
Example

Input:
7 4
1 3
7 7
7 3
2 2

Output:
0 1 2 2 1 2 2
Explanation

Array after first update : [0,0,1,1,1,1,1]

Array after second update : [0,0,1,1,1,1,2]

Array after third update : [0,0,2,1,1,1,2]

Array after fourth update : [0,1,2,2,1,2,2]
*/

int main()
{
	int n,u,i,j,p,x,y,temp;
	n=scan_d();
	u=scan_d();
	p=sqrt(n);
	vi a(n+1);
	vpii q;
	fr(i,u)
	{
		x=scan_d();
		y=scan_d();
		if(x>=p)
		{
			for(j=y;j<=n;j+=x)
				a[j]++;
		}
		else
			q.pb(mp(x,y));
	}
	sort(all(q));
	int pos=0;
	fu(j,1,p)
	{
		vi count(n,0);
		temp=1;
		fue(i,1,n)
		{
			while(pos<sz(q) and q[pos].ff==j and q[pos].ss<=i)
			{
				count[q[pos].ss%j]++;
				pos++;
			}
			if(temp>=j)
				temp-=j;
			a[i]+=count[temp];
			temp++;
		}
	}
	sp=' ';
	fue(i,1,n)
		printsp_d(a[i]);
	return 0;
}
