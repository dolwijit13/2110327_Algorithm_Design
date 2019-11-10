#include<bits/stdc++.h>
using namespace std;

int dp[10005];
int a[25];
int n,m;

int f(int x)
{
    if(x==0) return 0;
    if(dp[x]!=0) return dp[x];
    int i;
    dp[x]=999999999;
    for(i=1;i<=n;i++)
    {
        if(x==a[i]) return dp[x]=1;
        if(x<a[i]) continue;
        dp[x]=min(dp[x],f(x-a[i])+1);
    }
    return dp[x];
}

int main()
{
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",f(m));
    for(i=1;i<=m;i++)
    {
        printf("%d %d\n",i,dp[i]);
    }
}
