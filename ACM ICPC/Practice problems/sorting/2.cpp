   //*+++++++++++++++++++++++++++++++++++++++++*//
  //           ~~~~~ @VIN@SH ~~~~~             //
 //          ~~~~ IIEST SHIBPUR ~~~~          //
//*+++++++++++++++++++++++++++++++++++++++++*//
#include <bits/stdc++.h>
using namespace std;
#define si(o) scanf("%d",&(o))
#define sl(o) scanf("%lld",&(o))
#define ss(o) scanf("%s",(o))
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define caset int __T,case_n=1;scanf("%d",&(__T));while(__T--)
typedef long long int ll;typedef vector<int> vi;typedef pair<int,int> pii;
/*========================================================================================*/
#define MAXN 10000+2
int a[MAXN], b[MAXN], Aux[MAXN], f[1000000+2];

void mergeFunc(int left,int mid,int right)
{
    int p=left,q=mid+1,k=0,coun=0;
    for(int i=left;i<=right;i++)
    {
        if(p>mid)
        {
            Aux[k++] = a[q++];
        }
        else if(q>right)
        {
            Aux[k++] = a[p];
            f[a[p]] += coun;
            p++;
        }
        else if(a[p] <= a[q])
        {
            Aux[k++] = a[p];
            f[a[p]] += coun;
            p++;
        }
        else
        {
            Aux[k++] = a[q++];
            coun++;
        }
    }
    for(int i=0;i<k;i++)
    {
        a[left++] = Aux[i];
    }
}
void mergeSort(int left,int right)
{
    if(left<right)
    {
        int mid = (left+right)/2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);
        mergeFunc(left,mid,right);
    }
}
int main() {
	caset{
		int n; si(n);
		memset(f,0,sizeof f);
		rep(i,0,n){
			si(a[i]);
			b[i]=a[i];
		}
		mergeSort(0,n-1);

		rep(i,0,n){
			printf("%d ", f[b[i]]);
		}
		printf("\n");
	}
	return 0;
}
