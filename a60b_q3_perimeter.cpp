#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

vector<int>v[1005];
int d[1005];
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,j;
    int ans=0;
    int x,y;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    priority_queue<pair<int,int> >pq;
    pq.push(mp(-0,0));/// -distance last_location
    while(!pq.empty())
    {
        int w;
        w=-pq.top().ft;
        x=pq.top().sd;
        pq.pop();
        if(d[x]!=0) continue;
        d[x]=w;
        if(w==k) ans++;
        for(i=0;i<v[x].size();i++)
        {
            if(v[x][i]!=0) pq.push(mp(-w-1,v[x][i]));
        }
    }
    printf("%d",ans);
}
