#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define go(i,a,b) for(int i=a;i<=(b);++i)
 
typedef long long ll;
const int p=1e9+7;
int L[204800],R[204800],K[204800];
 
ll pm(ll a,int n=p-2){
	ll r=1;
	for(;n;n>>=1,a=a*a%p)if(n&1)r=r*a%p;
	return r;
}
struct gg{
	int z[10240];
	int a[52][52],c[52],n,Km;
	void read(){
		int m;
		scanf("%d%d",&n,&m);
		rep(i,n)++a[i][i];
		rep(_,m){
			int x,y;
			scanf("%d%d",&x,&y);
			++a[--x][--y];++a[y][x];
		}
	}
	void pre(){
		static int M[2][52][52];
		auto R=&M[0][0],T=&M[1][0];
		rep(i,n)rep(j,n)R[i][j]=(i==j);
		z[0]=n;
		const int E=min(Km,n*2-1);
		go(r,1,E){
			ll tmp;
			rep(i,n)rep(j,n){
				tmp=0;
				rep(k,n)if(a[j][k])tmp+=R[i][k];
				T[i][j]=tmp%p;
			}
			swap(R,T);
			tmp=0;
			rep(i,n)tmp+=R[i][i];
			z[r]=tmp%p;
		}
		if(E<Km){
			rep(i,n){
				a[i][n]=z[i+n];
				rep(j,n)a[i][j]=z[i+j];
			}
			gauss();
			go(i,E+1,Km)rep(j,n)
				z[i]=(z[i]+c[j]*(ll)z[i+j-n])%p;
		}
	}
	void gauss(){
		rep(i,n){
			int k=-1;
			go(j,i,n-1)if(a[j][i]){k=j;break;}
			if(k==-1)a[i][i]=1;
			if(k!=i)go(j,i,n)swap(a[i][j],a[k][j]);
			ll t=pm(a[i][i]);
			go(j,i,n)a[i][j]=a[i][j]*t%p;
			go(j,i+1,n-1)if(a[j][i]){
				t=p-a[j][i];
				go(k,i,n)a[j][k]=(a[j][k]+t*a[i][k])%p;
			}
		}
		for(int i=n-1;~i;--i){
			c[i]=a[i][n];
			ll t=p-c[i];
			rep(j,i)a[j][n]=(a[j][n]+a[j][i]*t)%p;
		}
	}
} g[50];
const int Kf=10000,Kfl=Kf+100&~63;
 
int fact[Kfl],ifact[Kfl],bfact[Kfl];
 
typedef unsigned long long ull;
int afact[1<<15],x[1<<15],y[6<<15];
 
 
int Km[52][52],*res[52][52];
int Mem[2600000];
 
void karatsuba(int* a,int* b,int* res,int d){
	const int h=d>>1;
	static const int cut=16;
	if(d<=cut){
		static ull tmp[cut<<1];
		memset(tmp,0,sizeof(tmp[0]) * (d<<1));
		rep(i,d)rep(j,d)
			tmp[i+j]+=static_cast<ull>(a[i])*static_cast<ull>(b[j]);
		rep(i,(d<<1))res[i]=tmp[i]%p;
		return;
	}
	int *ar=a,*al=a+h,*br=b,*bl=b+h,*as=res+d*5,*bs=res+d*5+h,
		*x1=res,*x2=res+d,*x3=res+(d<<1);
	rep(i,h){
		as[i]=(al[i]+ar[i])%p;
		bs[i]=(bl[i]+br[i])%p;
	}
	karatsuba(ar,br,x1,h);
	karatsuba(al,bl,x2,h);
	karatsuba(as,bs,x3,h);
	rep(i,d) x3[i]= (unsigned(x3[i]+p-x1[i])+unsigned(p-x2[i]))%p;
	rep(i,d) res[i+h]=(res[i+h]+x3[i])%p;
}
 
void inv(const int N){
	go(i,0,N){
		int tmp=0;
		go(j,0,i) tmp=(tmp+x[j]*(ll)afact[i-j])%p;
		y[i]=tmp;
	}
}
 
unsigned dot(int *a,int *b,const int sz){
	ull res=0;
	for(int cnt=sz>>4;cnt--;a+=16,b+=16){
#define X(k) (*(a+k)*(ull)*(b+k))
		res+=*a*(ull)*b+X(1)+X(2)+X(3)+X(4)+X(5)+X(6)
			+X(7)+X(8)+X(9)+X(10)+X(11)+X(12)+X(13)+X(14)+X(15);
		res%=p;
	}
	for(int cnt=sz&15;cnt--;++a,++b)
		res+= (ull)*a * (ull)*b;
	return res%p;
}
int main(){
	for(int i=fact[0]=1;i<=Kf;++i)
		fact[i]=i*(ll)fact[i-1]%p;
	ifact[0]=ifact[1]=1;
	go(i,2,Kf)ifact[i]=ll(p-p/i)*ifact[p%i]%p;
	go(i,2,Kf)ifact[i]=ifact[i]*(ll)ifact[i-1]%p;
	go(i,0,Kf)afact[i]=(i&1)?p-ifact[i]:ifact[i];
	go(i,0,Kf)bfact[i]=afact[Kf-i];
	int T,q;
	scanf("%d",&T);
	rep(i,T)g[i].read();
	scanf("%d",&q);
	rep(i,q){
		scanf("%d%d%d",L+i,R+i,K+i);
		int &res=Km[--L[i]][--R[i]];
		res=max(res,K[i]);
	}
	rep(i,T){
		int &k=g[i].Km;
		go(l,0,i)go(r,i,T-1)k=max(k,Km[l][r]);
		g[i].pre();
	}
	int *z=Mem;
	rep(r,T)go(l,0,r){
		const int K=Km[l][r];
		go(i,0,K){
			x[i]=ifact[i];
			go(j,l,r)x[i]=x[i]*(ll)g[j].z[i]%p;	
		}
		int c=1;
		static const int L=1<<13;
		for(;c<=K;)c<<=1;
		karatsuba(x,afact,y,min(c,L));
		if(K>=L)go(i,L,K){
			const int c=i-L+1;
			y[i]=(dot(x+L,bfact+Kf+L-i,c)+dot(x,bfact+Kf-i,c)+(unsigned)y[i])%p;
		}
		res[l][r]=z-=1;
		for(int i=1,tmp=0;i<=K;++i)
			z[i]=tmp=(y[i]*(ll)fact[i]+tmp)%p;
		z+=K+1;
	}
	rep(i,q)printf("%d\n",res[L[i]][R[i]][K[i]]);
}
