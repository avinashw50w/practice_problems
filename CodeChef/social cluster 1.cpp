#include<bits/stdc++.h>
using namespace std;
 
mt19937 g;
typedef uniform_int_distribution<int> uniform;
typedef unsigned long long ULL;
const ULL DEN=26771144400ULL;
const double DS=10.0/DEN;
int T=60;
ULL INV[26];
clock_t dl = clock() + 4.92*CLOCKS_PER_SEC;
int abs_arr[128],*Abs = abs_arr+64; 
 
 
class Unit{
	int x_initial[2048],y_initial[2048],l[2048];
	int cell[64][64],res[64][64];
	void weight(int[][64]);
	void crystallization(vector<int>&);
public:
	int N,K;
	ULL best_score,A,B;
	void read();
	void init();
	void show();
	void try_mid();
	void try_rand();
} unit[60];
 
void Unit::weight(int cell[][64]){
	A=B=0;
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
		if(cell[i][j]>0){
			int k=cell[i][j],n=0,s=0;
			A+= (Abs[x_initial[k]-i]+Abs[y_initial[k]-j])*INV[l[k]];
			for(int x:{i-1,i,i+1})
				for(int y:{j-1,j,j+1})if(cell[x][y]>0){
					n++;
					s+=Abs[l[cell[x][y]]-l[k]];
				}
			B+=s*INV[n];
		}
	ULL tmp=A*100+B;
	if(tmp<best_score){
		best_score=tmp;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				res[i][j]=max(0,cell[i][j]);
	}
}
 
void Unit::init(){
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(cell[i][j]){
				x_initial[cell[i][j]]=i;
				y_initial[cell[i][j]]=j;
			}
	for(int i=0;i<=N+1;++i)
		cell[0][i]=cell[i][0]=cell[i][N+1]=cell[N+1][i]=-1;
	best_score=numeric_limits<typeof(best_score)>::max();
}
 
 
void Unit::try_mid(){
	vector<int> v={N+1>>1 | (N+1>>1)<<16};
	crystallization(v);
	if( K*20 <= N*N && K >=60 && N>=40) {
		for(int i=N+1>>1,tm=7;tm--;++i){
			v.push_back(i<<16|i);
			v.push_back(i<<16|N+1-i);
			v.push_back(N+1-i<<16|i);
			v.push_back(N+1-i<<16|N+1-i);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		crystallization(v);
	}
}
 
void Unit::try_rand(){
	vector<int> v;
	if( (K<=10 || N*N >= K * 10 ) && uniform(0,5)(g)){
		const int k=uniform(1,K)(g);
		v.push_back( x_initial[k] << 16 | y_initial[k]);
	}else{
		const int x=uniform(1,N)(g),
				y=uniform(1,N)(g);
		v.push_back( x<<16 | y );
	}
	crystallization(v);
}
 
 
void Unit::crystallization(vector<int>& nucleation){
	static int x[2048],y[2048],d[2048],atom[2048];
	static vector<int> growth;
	for(int i=1;i<=N;++i)fill(cell[i]+1,cell[i]+N+1,0);
	shuffle(nucleation.begin(),nucleation.end(),g);
	growth.clear();
	for(int i=1;i<=K;++i)atom[i]=i;
	fill(d+1,d+1+K,0xFFFE);
	for(int p:nucleation){
		int x=p>>16,y=p&0xffff;
		cell[x][y]=-1;
		for(int i=1;i<=K;++i)
			d[i]=min(d[i],Abs[x-x_initial[i]]+Abs[y-y_initial[i]]);
	}
	ULL tmpA=0;
	for(int n=K;n;--n){
		int best=0xffff,now=-1,mult=0,cnt=0,pos=-1;
		for(int j=1;j<=n;++j){
			int i=atom[j];
			int tmp=best * l[i] - d[i] * mult;
			if(tmp>0){
				best=d[i];mult=l[i];cnt=1;now=j;
				if(!best)break;
			}else if(tmp==0){
				if(!(g()%++cnt)){
					best=d[i];mult=l[i];now=j;
				}
			}
		}
		assert(~now);
		swap(atom[now],atom[n]);
		now=atom[n];
		vector<int> &position=nucleation.size()?nucleation:growth;
		best=0xffff;
		for(int i=0;i<position.size();++i){
			int x=position[i]>>16,y=position[i]&65535,
				d=Abs[x-x_initial[now]]+Abs[y-y_initial[now]];
			if(d<best){
				best=d;pos=i;cnt=1;
				if(!best)break;
			}else if(d==best){
				if(!(g()%++cnt))pos=i;
			}
		}
		assert(~pos);
		cell[x[now]=position[pos]>>16][y[now]=position[pos]&65535]=now;
		tmpA+=best * INV[l[now]];
		if(tmpA * 100 >= best_score) return;
		position[pos]=position.back();
		position.pop_back();
		for(int a=x[now]-1;a<=x[now]+1;++a)
			for(int b=y[now]-1;b<=y[now]+1;++b)
			if(!cell[a][b]){
				cell[a][b]=-1;
				growth.push_back(a<<16|b);
				for(int j=1;j<n;++j){
					const int i=atom[j];
					d[i]=min(d[i],Abs[a-x_initial[i]]+Abs[b-y_initial[i]]);
				}
			}
	}
	for(int tm=5,i,ok=true;tm-- && ok;){
	for(i=1,ok=0;i<K;++i)
		for(int j=i+1;j<=K;++j){
#define dis(i,j) (abs(x[i]-x_initial[j])+abs(y[i]-y_initial[j]))
			int t=dis(i,j)*l[i]+dis(j,i)*l[j]-dis(i,i)*l[j]-dis(j,j)*l[i];
#undef dis
			if(t<0){
				swap(cell[x[i]][y[i]],cell[x[j]][y[j]]);
				swap(x[i],x[j]);
				swap(y[i],y[j]);
			}
		}
	}
	weight(cell);
}
 
#ifdef LOCAL
ULL Score;
int main(int argc,char* argv[]){
	if(argc>1){
		string s(argv[1]);
		seed_seq seed(s.begin(),s.end());
		cerr << "seed :=: \"" << s << "\"\n";
		g.seed(seed);
	}else{
		random_device rd;
		auto seed=rd();
		cerr << "seed :=: " << seed << endl;
		g.seed(seed);
	}
#else
int main(){
	scanf("%d",&T);
	random_device rd;
	g.seed(rd());
#endif
	for(int i=-63;i<=63;++i)Abs[i]=abs(i);
	for(int i=1;i<=25;++i)INV[i]=DEN/i;
	for(int i=0;i<T;++i){
		unit[i].read();
		unit[i].init();
	}
	for(int j=0;j<T;++j)
		unit[j].try_mid();
	for(int tm=4;tm--;)
	for(int j=0;j<T;++j)
		unit[j].try_rand(); 
	for(;clock()<dl;)
	for(int j=0;j<T;++j)
	if(unit[j].K * 5<= unit[j].N*unit[j].N ){
		unit[j].try_rand();
		if(unit[j].K * 8<= unit[j].N*unit[j].N && unit[j].K>=30){
			unit[j].try_rand();
			if(unit[j].K * 15<= unit[j].N*unit[j].N)
				unit[j].try_rand();
			if(unit[j].K * 20<= unit[j].N*unit[j].N)
				unit[j].try_rand();
			if(unit[j].K * 30<= unit[j].N*unit[j].N)
			for(int tm=2;tm--;)
				unit[j].try_rand();
		}
		if(clock()>=dl)break;
	}
	for(int j=0;j<T;++j)unit[j].show();
#ifdef LOCAL
	cerr << "Total :=: " << Score*DS << endl;
#endif
} 
 
#ifdef LOCAL
void Unit::read(){
	N=uniform(uniform(2,60)(g),60)(g);
	K=uniform(2,uniform(2,min(2000,N*N))(g))(g);
	static int empty[4096];
	for(int i=1;i<=N*N;++i)empty[i]=i;
	for(int i=1,c=N*N;i<=K;++i){
		int k=uniform(1,c)(g);
		swap(empty[k],empty[c]);
		cell[(empty[c]-1)/N+1][(empty[c]-1)%N+1]=i;
		c--;
	}
	uniform l_gen(1,25);
	for(int i=1;i<=K;++i)l[i]=l_gen(g);
}
void Unit::show(){
	weight(res);
	cerr<<" ID ="<< setw(4)<< (this-unit)+1
		<<"  N ="<< setw(4) << N
		<<"  K ="<< setw(6) << K
		<<"  A ="<< setw(9) << A*100*DS
		<<"  B ="<< setw(9) << B*DS
		<<"  S ="<< setw(9) << (A*100+B)*DS << endl;
	for(int i=1;i<=N;++i,cerr << endl)
		for(int j=1;j<=N;++j)
			cerr << char(res[i][j]?'A'+l[res[i][j]]-1:'.');
	Score += best_score;
}
#else
void Unit::read(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			scanf("%d",&cell[i][j]);
	for(int i=1;i<=K;++i)scanf("%d",l+i);
}
void Unit::show(){
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			printf("%d%c",res[i][j]," \n"[j==N]);
}
#endif
 
