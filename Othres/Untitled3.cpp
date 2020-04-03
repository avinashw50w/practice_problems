#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   // vector<pair<int,pair<int,int>>> v;
    int arr[100002],count[100002],subset=0;
    float pr=1.0,sum=0,p[100002];
    memset(count,0,sizeof(count));
    int n,var,t,j;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %f",&arr[i],&p[i]);
       // v.push_back(make_pair(i,make_pair(var,p/100)));
        for(int i=1;i<=n;i++){
            if(count[i]==0){
              t=i;j=i;pr=1;
                while(arr[t]!=j){
                	count[t]++;
                	if(count[t]==2){
                		if(arr[arr[t]]==t){
						
                		pr*=(float)(p[t]/100);
                		pr*=(float)(p[arr[t]]/100);
                	}
                		break;
					}
                    pr*=(float)(p[t]/100);
                   // cout<<pr<<endl;
                t=arr[t];
            }
                if(count[t]==0){
                count[t]++;
                if(pr!=0){
                pr*=(p[t]/100);
                subset++;
                sum+=pr;
            	}
            }
        }
    }
   cout<<"S="<<subset<<endl;
        printf("%.2f",sum);
    return 0;
}

