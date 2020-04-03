#include<cstdio>
using namespace std;
#define MOD 1000000007
int main()
{
    int t;
    scanf("%d",&t);
    int arr[t+2][102];
    for(int tcase=0;tcase<t;tcase++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int g[n+2][n+2];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        g[i][j]=0;
        for(int j=0;j<m;j++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            u=u-1;v=v-1;
            g[u][v]=1;
            g[v][u]=1;
        }
        int dp[n+2][n+2][102];
        for(int k=0;k<=100;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j][k]=0;
                    if(k==0&&i==j)
                        dp[i][j][k]=1;
                    if(k==1&&g[i][j])
                    dp[i][j][k]=1;
                    if(k>1)
                    {
                        for(int p=0;p<n;p++)
                        {
                            if(g[i][p])
                            {
                                dp[i][j][k]=dp[i][j][k]+dp[p][j][k-1];
                                if(dp[i][j][k]>=MOD)
                                dp[i][j][k]=dp[i][j][k]%MOD;
                            }
                        }
                    }
                }
            }
        }
       	int count=0;
        for(int j=1;j<=100;j++)
        {
            for(int i=0;i<n;i++)
            {
                count=count+dp[i][i][j];
                if(count>=MOD)
                    count=count%MOD;
            }
            arr[tcase][j]=count;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int l,r,ki;
        scanf("%d %d %d",&l,&r,&ki);
        --l;--r;
        printf("%d\n",arr[l][ki]);
    }
    return 0;
}
