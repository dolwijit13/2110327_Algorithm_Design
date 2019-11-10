#include<bits/stdc++.h>
using namespace std;

vector<int>v[100005];
int a[100005];
bool chk=0;

void dfs(int p,int x,int d)
{
    //printf("%d %d %d\n",p,x,d);
    if(chk) return;
    if(a[x]!=0)
    {
        printf("%d",d-a[x]);
        chk=1;
        return;
    }
    a[x]=d;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==p) continue;
        dfs(x,v[x][i],d+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(-1,0,1);
    return 0;
}
