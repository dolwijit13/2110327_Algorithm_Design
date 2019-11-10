#include<bits/stdc++.h>
using namespace std;

int ans=0;
vector<int>v[10005];
bool chk[10005];

void dfs(int x)
{
    if(chk[x]) return;
    chk[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        if(!chk[i])
        {
            dfs(i);
            ans++;
        }

    }
    printf("%d",ans);
    return 0;
}
