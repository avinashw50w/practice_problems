#include<stdio.h>
#include<stdlib.h>
long a[1234567];
	long  freq[1234567];
	
	//long long ba[n];
	int right[1234567];
	int stack[1234567];
	int count[1234567];
void swap(long* a, long* b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}
  int binaryceil(long  *arr,int low,int high,long  x)
	{
		if(x>=arr[high])
		{
			return -1;
		}
		while(low<high)
		{
			int mid=low+(high-low)/2;
			if(arr[mid]<=x && arr[mid+1]>x)
			{
				return mid+1;
			}
			else if(arr[mid]>x)
			{
				high=mid;
			}
			else
			{
				low=mid+1;
			}
			
		}
		return -1;
	}
int binarysearch(long  arr[], int l, int r, long  x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    if (arr[m] == x) return m;  // Check if x is present at mid
 
    if (arr[m] < x) l = m + 1; // If x greater, ignore left half
 
    else r = m - 1; // If x is smaller, ignore right half
  }
  return -1; // if we reach here, then element was not present
}
	  int binaryfloor(long  *arr,int low,int high,long  x)
	{
		if(x<=arr[low])
		{
			return -1;
		}
		if(x>arr[high])
		{
			return high;
		}
		//int count=0;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			
			if(mid-1>=0 && arr[mid-1]<x && arr[mid]>=x)
			{
				return mid-1;
			}
			else if( arr[mid]<x && arr[mid+1]>=x )
			{
				return mid;
			}
			else if(arr[mid]>=x)
			{
				high=mid-1;
			}
			else
			{
				low=mid;
			}
			
		}
		return -1;
	}
 
int partition (long  *arr,long  *b ,int l, int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
 	int j;
    for ( j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
			swap(&b[i],&b[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);
	swap(&b[i+1],&b[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSort(long  *arr,long  *b, int l, int h)
{
    if (l < h)
    {
        int p = partition(arr,b, l, h); /* Partitioning index */
        quickSort(arr, b, l,p - 1);
        quickSort(arr,b, p + 1, h);
    }
}
void merge(long  arr[],long  b[] ,int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    long  L[n1], R[n2];
 	long  L2[n1],R2[n2];
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
    {
    
        L[i] = arr[l + i];
        L2[i]=b[l+i];
    }
    for(j = 0; j < n2; j++)
    {
    
        R[j] = arr[m + 1+ j];
        R2[j]=b[m+1+j];
    }
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            b[k]=L2[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            b[k]=R2[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        b[k]=L2[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        b[k]=R2[j];
        j++;
        k++;
    }
}
void mergesort(long  a[],long  b[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,b,l,m);
		mergesort(a,b,m+1,r);
		merge(a,b,l,m,r);
	}
}
int main()
{
	char win[]="CD";
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%li",&a[i]);
		freq[i]=0;
		count[i]=0;
	}
	int top=-1;
	for(i=n-1;i>=0;i--)
	{
		while(top!=-1 && a[stack[top]]<=a[i])
		{
			top--;
		}
		if(top!=-1)
		{
			right[i]=stack[top];
		}
		else
		{
			right[i]=n;
		}
		top++;
		stack[top]=i;
	}
	for(i=0;i<n;i++)
	{
		freq[i]+=(right[i]-i)*1l*(count[i]+1);
		count[right[i]]+=count[i]+1;
	}
	/*printf("before merging\n");
		for(i=0;i<n;i++)
	{
		printf("%lld %lld\n",a[i],freq[i]);
	}
	printf("after merging\n");*/
	//mergesort(a,freq,0,n-1);
	//quickSort(a,freq,0,n-1);
	mergesort(a,freq,0,n-1);
	/*for(i=0;i<n;i++)
	{
		printf("%lld %lld\n",a[i],freq[i]);
	}*/
	//long long prefix[n];
	int cc=0;
	int temp=0;
	while(temp<n)
	{
		a[cc]=a[temp];
		freq[cc]=freq[temp];
		int ttt=temp+1;
		while(ttt<n && a[ttt]==a[temp])
		{
			freq[cc]+=freq[ttt];
			ttt++;
		}
		temp=ttt;
		cc++;
	}
	for(i=1;i<cc;i++)
	{
		freq[i]+=freq[i-1];
	}
	/*for(i=0;i<cc;i++)
	{
		printf(" number is %lld & prefix is %lld\n",ba[i],prefix[i]);
	}*/
 
	//char aa[m+1];
	//printf(" m is %d",m);
	char si[2],fst[2];
	long  k;
	//char winer;
	//getchar();
	for(i=0;i<m;i++)
	{
	//printf("for loop %d\n",i);
	scanf("%s %li %s",si,&k,fst);
 
	//printf(" ch is %c",ch);
	if(si[0]=='=')
	{
		
		int w=0;
		if(fst[0]==win[1])
		{
			w=1;
		}
		int x=binarysearch(a,0,cc-1,k);
		long  ans=0;
		if(x!=-1)
		{
			if(x!=0)
			{
				ans=freq[x]-freq[x-1];
			}
			else
			{
				ans=freq[x];
			}
		
		}
		//printf("ans is %d  x is %d\n",ans,x);
			if(ans%2==0)
				{
				printf("%c",win[1-w]);
				}	
				else
				{
					printf("%c",win[w]);
				}
		
	}
	else if(si[0]=='>')
	{
		//printf("from graterthan\n");
		int w=0;
		if(fst[0]==win[1])
		{
			w=1;
		}
		int x=binaryceil(a,0,cc-1,k);
		long  ans=0;
		if(x!=-1)
		{
			if(x!=0)
			{
				ans=freq[cc-1]-freq[x-1];
			}
			else
			{
				ans=freq[cc-1];
			}
				
		}
		//printf("ans is %d\n",ans);
		//printf("ans is %d  x is %d\n",ans,x);
			if(ans%2==0)
				{
				printf("%c",win[1-w]);
				}	
				else
				{
					printf("%c",win[w]);
				}
	}
	
	else
	{
		//printf("from less than\n");
		int w=0;
		if(fst[0]==win[1])
		{
			w=1;
		}
		int x=binaryfloor(a,0,cc-1,k);
		long  ans=0;
		if(x!=-1)
		{
			ans=freq[x];
		}
		//printf("ans is %d\n",ans);
		//printf("ans is %d  x is %d\n",ans,x);
		if(ans%2==0)
				{
				printf("%c",win[1-w]);
				}	
				else
				{
					printf("%c",win[w]);
				}
	}
	}
	//aa[m]='\0';
	//printf("%s",aa);
	
} 
