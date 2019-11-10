#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int d[105];

int main()
{
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    int i,j,k;
    vector<pair<pair<int,int>,int> >e; /// e[v]= {(u,v,w)}
    for(i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        e.push_back(mp(mp(x,y),w));
    }
    for(i=0;i<n;i++) d[i]=999999999;
    d[s]=0;
    bool chk;
    for(k=1;k<=n;k++)
    {
        chk=false;
        for(i=0;i<m;i++)
        {
            int u=e[i].ft.ft;
            int v=e[i].ft.sd;
            int w=e[i].sd;
            if(d[u]+w < d[v])
            {
                d[v]=d[u]+w;
                chk=true;
            }
        }
    }
    if(chk) printf("-1");
    else
    {
        for(i=0;i<n;i++) printf("%d ",d[i]);
    }
    return 0;
}
