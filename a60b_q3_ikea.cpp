#include<bits/stdc++.h>
using namespace std;

int a[1005];
bool chk[1005][1005];
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);
    int i,j,k;
    int x,y;
    for(i=1;i<=e;i++)
    {
        scanf("%d %d",&x,&y);
        chk[x][y]=1;
    }
    //*
    for(i=1;i<=5;i++)
    {
        bool z=1;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            for(k=1;k<j && z;k++)
            {
                if(chk[a[j]][a[k]])
                {
                    z=0;
                    break;
                }
            }
        }
        if(z) printf("SUCCESS\n");
        else printf("FAIL\n");
    }
    //*/
    return 0;
}
