#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int p[10005];

int main()
{
    int n,k;
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    int ans=999999999;
    for(i=1;i<=n;i++)
    {
        if(i<=(k+1))
        {
            dp[i]=p[i];
            if(i>=(n-k)) ans=min(ans,dp[i]);
            continue;
        }
        dp[i]=999999999;
        for(j=(i-2*k-1);j<=(i-1);j++)
        {
            if(j<=0) continue;
            dp[i]=min(dp[j]+p[i],dp[i]);
        }
        if(i>=(n-k)) ans=min(ans,dp[i]);
    }
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",i,dp[i]);
    }
    printf("%d",ans);
}
