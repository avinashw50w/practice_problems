/*You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| <= 15007 , 1 <= N <= 50000 ). A query is defined as follows: 
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x <= i <= j <= y }. 
Given M queries, your program must output the results of these queries. */
#include <iostream>
 
using namespace std;
 
struct node{
    long best,sum,prefix,suffix;
    void init(long a){
        best 	= a;
        sum 	= a;
        prefix 	= a;
        suffix 	= a;
    }
    void merge(node left, node right){
        prefix = max(left.prefix, left.sum + right.prefix);
        suffix = max(right.suffix, right.sum + left.suffix);
        sum    = left.sum + right.sum;
        best   = max( max(left.best,right.best), left.suffix + right.prefix);
    }
} tree[200005];
 
int sn,n,arr[50005];
 
 
node query(int i,int l,int r,int ql,int qr){
    if(ql==l && qr==r){
        return tree[i];
    }
    int mid = (l+r)/2;
    if(qr<=mid)
        return query(2*i, l, mid, ql, qr);
    if(ql>mid)
        return query(2*i+1, mid+1, r, ql, qr);
    
    node a,b,temp;
    a = query(2*i, l, mid, ql,mid);
    b = query(2*i+1, mid+1, r, mid+1, qr);
    temp.merge(a,b);
    return temp;
}
 
void build(int i,int l,int r){
    if(l == r){
        tree[i].init(arr[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*i, l, mid);
    build(2*i+1, mid+1, r);
    tree[i].merge(tree[2*i], tree[2*i+1]);
}
 
 
int main()
{
    int q,a,b;
    node temp;
   	scanf("%d",&n);
   	for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);
   	
   	build(1,1,n);
   	
   	scanf("%d",&q);
   	while(q--){
       scanf("%d%d",&a,&b);
       temp = query(1,1,n,a,b);
       printf("%ld\n",temp.best);
   }
   return 0;
}