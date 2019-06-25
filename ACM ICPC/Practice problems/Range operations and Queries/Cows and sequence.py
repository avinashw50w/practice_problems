'''Bessie and the cows are playing with sequences and need your help. They start with a sequence, initially containing just the number 0, 
and perform n operations. Each operation is one of the following:

Add the integer xi to the first ai elements of the sequence.
Append an integer ki to the end of the sequence. (And hence the size of the sequence increases by 1)
Remove the last element of the sequence. So, the size of the sequence decreases by one. 
Note, that this operation can only be done if there are at least two elements in the sequence.
After each operation, the cows would like to know the average of all the numbers in the sequence. Help them!

Input
The first line contains a single integer n (1 ≤ n ≤ 2·105) — the number of operations. The next n lines describe the operations. 
Each line will start with an integer ti (1 ≤ ti ≤ 3), denoting the type of the operation (see above). If ti = 1, it will be 
followed by two integers ai, xi (|xi| ≤ 103; 1 ≤ ai). If ti = 2, it will be followed by a single integer ki (|ki| ≤ 103). 
If ti = 3, it will not be followed by anything.

It is guaranteed that all operations are correct (don't touch nonexistent elements) 
and that there will always be at least one element in the sequence.

Output
Output n lines each containing the average of the numbers in the sequence after the corresponding operation.

The answer will be considered correct if its absolute or relative error doesn't exceed 10^-6 '''

a=[0]
b=[0]
ans=0.
for j in range(input()):
	s=map(int,raw_input().split())
	if (s[0]==1):
		ans+=s[1]*s[2]
		b[s[1]-1]+=s[2]
	
	elif s[0]==2:
		ans+=s[1]
		a.append(s[1])
		b.append(0)
	
	else:
		t=b.pop()
		ans-=a.pop()+t
		b[-1]+=t
	
	print ans/len(a)

//////////////////////////////////////////////////////////////

int i,t,op,x,y,nr=1,a[200005],b[200005];
double sum;

int main()
{
  scanf("%d",&t);

  while(t--)
  {
    scanf("%d",&op);
    if(op==1) scanf("%d %d",&x,&y),b[x]+=y,sum+=x*y;
    if(op==2) scanf("%d",&x),a[++nr]=x,sum+=x;
    if(op==3) sum-=a[nr]+b[nr],b[nr-1]+=b[nr],a[nr]=b[nr--]=0;
    printf("%.6f\n",sum/nr);
  }

 return 0;
}