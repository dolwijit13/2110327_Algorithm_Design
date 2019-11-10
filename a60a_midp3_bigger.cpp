#include<bits/stdc++.h>
using namespace std;

int a[10005];
int dp[10005];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=-1;
    for(i=1;i<=n;i++)
    {
        dp[i]=a[i];
        for(j=i-6;j<i-2;j++)
        {
            if(j<=0) continue;
            dp[i]=max(dp[i],dp[j]+a[i]);
        }
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}
