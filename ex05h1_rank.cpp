#include<bits/stdc++.h>
using namespace std;

bool chk[5005];
bool chk_t[5005];
bool chk_sn[5005];
vector<int>v[5005];
vector<int>v_t[5005];
stack<int>tp;
stack<int>tp_t;
int idx=0;
int p[5005]; ///idx of super node
int sn[5005]; ///number of node in super_node[i]
int rnk[5005]; ///rank of super_node
int ans[5005];

void dfs_t(int x) ///find scc
{
    if(chk_t[x]) return;
    chk_t[x]=1;
    for(int i=0;i<v_t[x].size();i++)
    {
        dfs_t(v_t[x][i]);
    }
    //printf("aa%d\n",x);
    tp_t.push(x);
}

int to_super_node(int _p,int x) ///cycle -> super node
{
    if(chk_sn[x]) return 0;
    chk_sn[x]=1;
    int ans=1;
    for(int i=0;i<v[x].size();i++)
    {
        ans+=to_super_node(_p,v[x][i]);
    }
    p[x]=_p;
    return sn[_p]=ans;
}

void dfs(int x) ///find tp
{
    //printf("%d\n",x);
    if(chk[x]) return;
    chk[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i]);
    }
    tp.push(x);
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    int x,y;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v_t[y].push_back(x);
    }
    for(i=0;i<n;i++)
    {
        dfs_t(i);
        dfs(i);
    }
    while(!tp_t.empty())
    {

        to_super_node(tp_t.top(),tp_t.top());
        tp_t.pop();
    }
    while(!tp.empty())
    {
        int u=tp.top();
        int _u=p[u];
        //printf("%d %d\n",u,_u);
        tp.pop();
        rnk[_u]=max(rnk[_u],1);
        for(i=0;i<v[u].size();i++)
        {
            int _v=p[v[u][i]];
            if(_u==_v) continue;
            rnk[_v]=max(rnk[_v],rnk[_u]+1);
        }
    }
    for(i=0;i<n;i++)
    {
        //printf("--%d %d %d\n",i,p[i],rnk[i]);
        if(rnk[i]==0) continue;
        ans[rnk[i]]+=sn[i];
    }
    for(i=1;i<=n;i++)
    {
        if(ans[i]==0) break;
        printf("%d ",ans[i]);
    }
    return 0;
}
