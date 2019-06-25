/*
Oh, no! Chef’s in trouble. He’s got himself stuck in a cave (we don’t know how) and is looking for a way out. The bigger problem is that he needs to get his 
tractor out of the cave (don't ask why Chef owns a tractor!). He currently faces a large block of height N cells and length N cells, and needs to get his tractor
 across this block. The block is made up of vertical columns of soil, each of which is one cell long. Each column has a continuous vertical gap, with the ith 
 column having its gap from the lith cell to the hith cell (starting from the bottom, 0-indexing). That is, in the ith column, there is no soil from the lith 
 cell to the hith cell (both inclusive). Chef can build additional gaps by clearing some cells of soil. His tractor has height H, and therefore, he needs to 
 build a horizontal corridor of height H passing through all the columns. That is, some consecutive H rows must have no soil. Please see the figures in the
  example and explanation sections for more details.
Chef is able to clear one cell of soil by spending one unit of energy. Chef is smart, and will figure out a way to build the horizontal corridor while spending
 the minimum possible amount of energy. To estimate how many of his tasty dishes he will still be able to cook for you tonight, find out what is the minimum 
 possible energy he needs to spend.
Input
First line of input contains one integer T - number of test cases. T test cases follow.
Each test case starts with two integers N and H – size of the cave and height of the tractor, respectively. 
In each of the next N lines are two integers li and hi, respectively indicating lowest and highest number of cell for the gap in the ith column.

Output
One integer – minimum energy required.*/

#include<stdio.h>
#include<string.h>
 
#ifdef ONLINE_JUDGE
    #define gc getchar_unlocked
#else
    #define gc getchar
#endif
 
int read() {
    int num = 0;
    char c = gc();
    while( !(c>='0' && c<='9') ) c = gc();
    while(c>='0' && c<='9') {
        num = (num<<3)+(num<<1)+c-'0';
        c = gc();
    }
    return num;
}
 
 
int main() {
 
   int t, n, h, i, d, temp, sum[1000001];
   int long long ans, tSum;
   t = read();
 
   while( t-- ) {
 
        tSum = 0;
        n = read();
        h = read();
 
        for(i=0; i<=n; i++)
            sum[i]=0;
 
        for(i=0; i<n; i++ ) {
            sum[read()]++;
            sum[read()+1]--;
        }
 
        for(i=1; i<n; i++)
            sum[i] += sum[i-1];
 
        for(i=0; i<h; i++)
            tSum += sum[i];
        ans = tSum;
 
        for(i=1; i+h-1<n; i++) {
            tSum = tSum + sum[i+h-1] - sum[i-1];
            if( tSum > ans ) ans = tSum;
        }
       
        printf("%lld\n",(long long int)h*n -  ans);
   }
 
   return 0 ;
}


///////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
int main(){
	int t;
	
	scanf("%d",&t);
	while(t--){
		long long int n,h,i,j,sum=0,max=0,s,e,start=1;
		scanf("%lld %lld",&n,&h);
		long long int arr[n],l[n],u[n];
		for(i=0;i<n;i++){
			arr[i]=0;
			l[i]=0;
			u[i]=0;
		}
		for(i=0;i<n;i++){
			scanf("%lld %lld",&s,&e);
			l[s]++;
			u[e]++;
		}
		arr[0]=l[0];
		for(i=1;i<n;i++){
			l[i] = l[i] + l[i-1] - u[i-1];
			arr[i]=l[i]; 
		}
	for(i=0;i<h;i++){
		sum+=arr[i];
		max=sum;
		while(start<=(n-h)){
			sum+=arr[i] - arr[start-1];
			if(sum>max)
			max=sum;
			i++;
			start++;
		}
	}
	printf("%lld\n",(n*h)-max);
	}
	return 0;
}
