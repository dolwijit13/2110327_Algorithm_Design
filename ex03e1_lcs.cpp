#include<bits/stdc++.h>
using namespace std;

int dp[505][505];

int main()
{
    int n,m;
    int i,j;
    char s1[505],s2[505];
    scanf("%s %s",s1,s2);
    n=strlen(s1);
    m=strlen(s2);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0) continue;
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s1[i-1]==s2[j-1]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}
