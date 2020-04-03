#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll max(ll a, ll b){return (a>b)?a:b;}
long long int S[400005];
struct trie
{
    long long int val;
    struct trie *left;
    struct trie *right;
};
struct trie *root;
int maxsize = 33;
struct trie *initialise()
{
    struct trie *node;
    node = new trie();
    node->val = -1;
    node->left = NULL;
    node->right = NULL;
    return node;
};
void insert(int n)
{
    struct trie *node;
    node = root;
    int i;
 
    for(i = maxsize - 1; i >= 0; i--) {
        if(n&(1 << i)) {
            if(node->right == NULL) {
                node->right = initialise();
            }
            node = node->right;
        }
        else {
            if(node->left == NULL) {
                node->left = initialise();
            }
            node = node->left;
        }
    }
    node->val = n;
}
long long int query(long long int n)
{
    int i;
    struct trie *node;
    node = root;
 	//long long int maxxor=0,x;
    for(i = maxsize - 1; i >= 0; i--) {
        if(n & (1 << i)) {
            if(node->left != NULL) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        else {
            if(node->right != NULL) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
    }
    return node->val;
}

int main(){
	int n;
	root=initialise();
	long long int sum1,sum2,sum,maxi=0,maxi2=0,y,maxxor=0,maxS=0,index=0;
	scanf("%d",&n);
//	int x=0,y;
S[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&S[i]);
		S[i]^=S[i-1];
	}
	ll A[4000],B[4000];
	for(int k=0;k<n;k++){
		insert(S[k]);
		y=query(S[k]);
		y=y^S[k];
		if(y>maxi)
		maxi=y;
		A[k]=maxi;
	}
	free(root);
	root=initialise();
	for(int k=n;k>0;k--){
		insert(S[k]);
		y=query(S[k]);
		y=y^S[k];
		if(y>maxi2)
		maxi2=y;
		B[n-k]=maxi2;
	}
free(root);
ll ans;
for(int i=0;i<=n;i++)
ans= max(ans,A[i]+B[i+1]);
	printf("%lld\n",ans);
	return 0;
}
