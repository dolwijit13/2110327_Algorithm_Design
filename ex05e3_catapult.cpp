#include<bits/stdc++.h>
using namespace std;

vector<int>v[1005];
vector<int>v_t[1005];
stack<int>f;
bool chk[1005];
bool chk_t[1005];

void dfs_t(int x)
{
    if(chk_t[x]) return;
    chk_t[x]=1;
    for(int i=0;i<v_t[x].size();i++)
    {
        dfs_t(v_t[x][i]);
    }
    f.push(x);
}

int dfs(int x)
{
    chk[x]=1;
    int ans=1;
    for(int i=0;i<v[x].size();i++)
    {
        int j=v[x][i];
        if(!chk[j])
        {
            ans+=dfs(j);
        }
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(j=1;j<=m;j++)
        {
            int x;
            scanf("%d",&x);
            v[i].push_back(x);
            v_t[x].push_back(i);
        }
    }
    for(i=0;i<n;i++) dfs_t(i);
    vector<int>ans;
    while(!f.empty())
    {
        printf("%d\n",f.top());
        if(!chk[f.top()])
        {
            ans.push_back(dfs(f.top()));
        }
        f.pop();
    }
    sort(ans.begin(),ans.end());
    for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
    return 0;
}
