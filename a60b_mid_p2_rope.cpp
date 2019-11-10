#include<bits/stdc++.h>
using namespace std;

int n,a,b,c;
int dp[4005];

int f(int x)
{
    if(x<0) return -999999999;
    if(x==a || x==b || x==c) return dp[x]=max(max(max(f(x-a),f(x-b)),f(x-c))+1,1);
    if(dp[x]!=0) return dp[x];
    return dp[x]=max(max(f(x-a),f(x-b)),f(x-c))+1;
}

int main()
{
    scanf("%d %d %d %d",&n,&a,&b,&c);
    printf("%d",f(n));
    return 0;
}
