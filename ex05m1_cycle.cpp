#include<bits/stdc++.h>
using namespace std;

bool chk[1005];
bool ans;
vector<int>v[1005];

void dfs(int p,int x)
{
    if(chk[x])
    {
        ans=1;
        return;
    }
    chk[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==p) continue;
        dfs(x,v[x][i]);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        ans=0;
        int i;
        for(i=0;i<n;i++)
        {
            chk[i]=0;
            v[i].clear();
        }
        for(i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(i=0;i<n;i++)
        {
            if(!chk[i]) dfs(-1,i);
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
