#include<bits/stdc++.h>
using namespace std;

vector<int>u[100005];
vector<int>w[100005];
bool chk[100005];
int n;

int dfs(int p,int x)
{
    if(chk[x]) return 0;
    chk[x]=1;
    int i;
    for(i=0;i<u[x].size();i++)
    {
        if(u[x][i]==p) continue;
        w[x].push_back(n-dfs(x,u[x][i]));
    }
    int nkr=n-1;
    for(i=0;i<w[x].size();i++) nkr-=w[x][i];
    w[x].push_back(nkr);
    return nkr;
}

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        u[x].push_back(y);
        u[y].push_back(x);
    }
    dfs(-1,0);
    for(i=0;i<n;i++)
    {
        long long ans=0;
        for(j=0;j<w[i].size();j++)
        {
            long long x,y;
            x=w[i][j];
            y=n-w[i][j]-1;
            ans+=(x*y);
        }
        printf("%lld\n",ans/2+n-1);
    }
    return 0;
}
