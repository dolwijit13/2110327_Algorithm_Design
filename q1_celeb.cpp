#include<bits/stdc++.h>
using namespace std;

int qsnon[1005];
int qstang[1005];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int x,y;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            qsnon[i]+=x;
            qstang[j]+=x;
        }
    }
    int ans=0;
    for(j=1;j<=n;j++)
    {
        if(qsnon[j]==0 && qstang[j]==(n-1))
        {
            ans=j;
            break;
        }
    }
    printf("%d",ans);
}
