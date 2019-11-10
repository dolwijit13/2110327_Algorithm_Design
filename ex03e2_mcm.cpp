#include<bits/stdc++.h>
using namespace std;

int dp[105][105];
int a[105];

int f(int st,int ed)
{
    if((ed-st+1)==1) return dp[st][ed]=0;
    if(dp[st][ed]!=0) return dp[st][ed];
    if((ed-st+1)==2) return dp[st][ed]=a[st]*a[ed]*a[ed+1];
    int mid;
    dp[st][ed]=999999999;
    for(mid=st;mid<ed;mid++)
    {
        dp[st][ed]=min(dp[st][ed],f(st,mid)+f(mid+1,ed)+a[st]*a[mid+1]*a[ed+1]);
    }
    return dp[st][ed];
}

int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n+1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",f(1,n));
    return 0;
}
