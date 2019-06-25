#include<bits/stdc++.h>
using namespace std;
template<typename P> struct Cmp
{
    bool operator()(const P &p1, const P &p2)
    {
        if(p1.first < p2.first) return true;
        if(p1.first == p2.first) return (p1.second).first > (p2.second).first;
        return false;
    }
};
 
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
            int i,n,x,y;
        vector<pair<int,pair<int, int > > > coor_x;
        vector<pair<int,pair<int, int > > > coor_y;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            coor_x.push_back(make_pair(x,make_pair(y,i)));
            coor_y.push_back(make_pair(y,make_pair(x,i)));
           // normal.push_back(make_pair(x,y));
        }
        sort(coor_x.begin(),coor_x.end());
        sort(coor_y.begin(),coor_y.end(),Cmp<pair<int, pair<int, int > > >());
        int min_x=coor_x[0].first;
        int max_x=coor_x[n-1].first;
        int min_y=coor_y[0].first;
        int max_y=coor_y[n-1].first;
      //  printf("%d %d %d %d\n",max_x,min_x,max_y,min_y);
      /*  for(i=0;i<n;i++){
            printf("%d %d %d | %d %d %d\n",coor_x[i].first,(coor_x[i].second).first,(coor_x[i].second).second,coor_y[i].first,(coor_y[i].second).first,(coor_y[i].second).second);
        }*/
        if(coor_x[n-1].first==max_x && (coor_x[n-1].second).first==max_y){
            printf("1\n%d SW\n",(coor_x[n-1].second).second+1);
        }
        else  if(coor_y[0].first==min_y && (coor_y[0].second).first==max_x){
            printf("1\n%d NW\n",(coor_y[0].second).second+1);
        }
        else  if(coor_y[n-1].first==max_y && (coor_y[n-1].second).first==min_x){
            printf("1\n%d SE\n",(coor_y[n-1].second).second+1);
        }
        else  if(coor_x[0].first==min_x && (coor_x[0].second).first==min_y){
            printf("1\n%d NE\n",(coor_x[0].second).second+1);
        }
        else{
            if((coor_x[n-1].second).first>=(coor_x[0].second).first){
                printf("2\n%d SW\n%d NE\n",(coor_x[n-1].second).second+1,(coor_x[0].second).second+1);
            }
            else{
                printf("2\n%d NW\n%d SE\n",(coor_x[n-1].second).second+1,(coor_x[0].second).second+1);
            }
        }
    }
    return 0;
}
