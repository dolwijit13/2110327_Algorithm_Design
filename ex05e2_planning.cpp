#include<bits/stdc++.h>
using namespace std;

bool chk[1005];

bool a[1005][1005]; ///a[u][v]=1 -> u can go v
stack<int>tp;
int n;

void dfs(int u)
{
    //printf("start %d\n",u);
    for(int i=0;i<n;i++)
    {
        if(!a[u][i]) continue;
        if(chk[i]) continue;
        chk[i]=1;
        dfs(i);
    }
    tp.push(u);
    //printf("end %d\n",u);
}

int main()
{
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        int m;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            a[x][i]=1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(!chk[i])
        {
            chk[i]=1;
            dfs(i);
        }
    }
    while(!tp.empty())
    {
        printf("%d ",tp.top());
        tp.pop();
    }
    return 0;
}
