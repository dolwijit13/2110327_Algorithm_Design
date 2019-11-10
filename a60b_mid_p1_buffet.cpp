#include<bits/stdc++.h>
using namespace std;

vector<int>a;
int main()
{
    int f,w,n;
    scanf("%d %d %d",&f,&w,&n);
    int i,j;
    for(i=0;i<f;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int st=-999999999,ed=-999999999;
    int ans=0;
    i=0;
    for(j=1;j<=n;j++)
    {
        if(j-w <=st) ed=j+w;
        //printf("---%d %d\n",i,j);
        if(i>=f) break;
        if(a[i]==j)
        {
            //printf("%d %d\n",a[i],ed);
            if(a[i]>ed)
            {
                st=a[i];
                ed=a[i]+w;
                ans++;
            }
            i++;
        }
    }
    printf("%d",ans);
    return 0;
}
