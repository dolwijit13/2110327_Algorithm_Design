#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int p[5005];

int _find(int x)
{
    if(p[x]==x) return x;
    return p[x]=_find(p[x]);
}

bool _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return false;
    p[x]=y;
    return true;
}

int ans[5005];


int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int d=n,now=0;
    int i,j;
    priority_queue<pair<int,pair<int,int> > >pq;///-w,u,v
    for(i=0;i<n;i++) p[i]=i;
    for(i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        pq.push(mp(-w,mp(x,y)));
    }
    while(!pq.empty())
    {
        int x,y,w;
        w=-pq.top().ft;
        x=pq.top().sd.ft;
        y=pq.top().sd.sd;
        pq.pop();
        if(_union(x,y))
        {
            now=max(now,w);
            d--;
            ans[d]=now;
        }
    }
    while(q--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}
