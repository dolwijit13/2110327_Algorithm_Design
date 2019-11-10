#include<bits/stdc++.h>
using namespace std;

int a[505][505];
int dp[505][505];

int main()
{
    int n,m;
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j]=a[i][j];
            if(i!=1)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i][j]);
            }
            if(j!=1)
            {
                dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i][j]);
            }
            if(i!=1 && j!=1)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2*a[i][j]);
            }
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
