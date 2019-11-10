#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define mp make_pair

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,p;
    int x,y;
    vector<int>v(n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        v[i]=x;
    }
    vector<pair<int,pair<int,int> > >sum;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum.push_back(mp(v[i]+v[j],mp(i,j)));
        }
    }
    int sz= sum.size();
    sort(sum.begin(),sum.end());
    while(m--)
    {
        scanf("%d",&x);
        ///v[j]+v[k] = y
        ///v[i]+v[j]+v[k] = x
        bool chk=0;
        for(i=0;i<n;i++)
        {
            int y=x-v[i];
            int p=lower_bound(sum.begin(),sum.end(),mp(y,mp(0,0)))-sum.begin();
            if(p>=sz) continue;
            while(sum[p].sd.ft == i || sum[p].sd.sd==i) p++;
            if(v[i]+sum[p].ft == x)
            {
                printf("YES\n");
                chk=1;
                break;
            }
        }
        if(!chk) printf("NO\n");
    }
    return 0;
}
