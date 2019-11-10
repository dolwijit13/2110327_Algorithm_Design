#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int n,m;
int idx(int x,int y)
{
    return x*m+y;
}

int main()
{
    scanf("%d %d",&n,&m);
    vector<int>v;
    vector<int>ans(n*m);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
    }
    priority_queue<pair<int,pair<int,int> > >pq;///-d x y
    pq.push(mp(0,mp(0,0)));
    while(!pq.empty())
    {
        int d=-pq.top().ft;
        int x=pq.top().sd.ft;
        int y=pq.top().sd.sd;
        pq.pop();
        if(ans[idx(x,y)]!=0) continue;
        ans[idx(x,y)]=d;
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if(abs(i+j)!=1) continue;
                if(x+i <0 || x+i>=n || y+j<0 || y+j>=m) continue;
                if(ans[idx(x+i,y+j)]!=0) continue;
                pq.push(mp(-d-v[idx(x+i,y+j)],mp(x+i,y+j)));
            }
        }

    }
    for(i=0;i<n*m;i++)
    {
        if(i==0)
        {
            printf("0 ");
            continue;
        }
        if(i%m==0) printf("\n");
        printf("%d ",ans[i]);
    }
}
