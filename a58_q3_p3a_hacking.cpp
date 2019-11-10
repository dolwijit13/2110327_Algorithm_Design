#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int c[20005];
int dp[20005];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,j;
    queue<int>q;
    for(i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        q.push(x);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        dp[i]=999999999;
    }
    vector<int>v[20005];
    for(i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    priority_queue<pair<int,int> >pq;///-d x
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        pq.push(mp(-c[x],x));
    }
    int ans=0;
    while(!pq.empty())
    {
        int w=-pq.top().ft;
        int x=pq.top().sd;
        //printf("%d %d\n",w,x);
        pq.pop();
        if(dp[x]<=w) continue;
        dp[x]=w;
        ans=max(ans,w);
        for(i=0;i<v[x].size();i++)
        {
            int nxt=v[x][i];
            if(dp[nxt]<=w+c[nxt]) continue;
            pq.push(mp(-w-c[nxt],nxt));
        }
    }
    printf("%d",ans);
    return 0;
}
