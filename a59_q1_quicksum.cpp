#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int dp[1005][1005];

int main()
{
    int n,m,k;
    int i,j;
    int r1,c1,r2,c2;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        }
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        r2++;
        c2++;
        printf("%d\n",dp[r2][c2]-dp[r2][c1]-dp[r1][c2]+dp[r1][c1]);
    }
    return 0;
}
