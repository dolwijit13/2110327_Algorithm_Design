#include<bits/stdc++.h>
using namespace std;

vector<int>v[10005];
int ans=0;

int f(int x,int p)
{
    int sz=v[x].size();
    if(sz<=1 && p!=-1) return 1;
    int tmp=0;
    priority_queue<int>pq;
    for(int i=0;i<sz;i++)
    {
        if(v[x][i]==p) continue;
        int c=f(v[x][i],x);
        tmp=max(tmp,c);
        pq.push(c);
    }
    int c=0;
    int i=1;
    while(!pq.empty() && i<=2)
    {
        c+=pq.top();
        pq.pop();
        i++;
    }
    ans=max(ans,c+1);
    return tmp+1;
}

int main()
{
    int n;
    int i,j;
    int x,y;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=0;i<n;i++)
    {
        if(v[i].size()==1)
        {
            f(i,-1);
            break;
        }
    }
    printf("%d",ans-1);
}
