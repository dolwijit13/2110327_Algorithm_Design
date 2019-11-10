#include<bits/stdc++.h>
using namespace std;

int dp[15][10005];
int a[15];

int main()
{
    int n,m;
    int i,j,k;
    scanf("%d %d",&n,&m);
    int mi=INT_MAX;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++) dp[i][j]=INT_MAX;
    }
    dp[0][0]=0;

    for(i=1;i<=n;i++)
    {
        for(j=m;j>=0;j--)
        {
            for(k=1;k<=100;k++)
            {
                if(dp[i-1][j]!=INT_MAX && k*k+j <=m)
                {
                    dp[i][k*k+j]=min(dp[i][k*k+j],dp[i-1][j]+(a[i]-k)*(a[i]-k));
                }

            }
        }
    }
    if(dp[n][m]==INT_MAX) printf("-1");
    else printf("%d",dp[n][m]);
}
