#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second


double v[100005];
vector<pair<double,pair<double,double> > >a; ///pair(-v/w,v,w)
int main()
{
    double m;
    int n;
    scanf("%lf %d",&m,&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%lf",&v[i]);
    }
    for(i=1;i<=n;i++)
    {
        double x;
        scanf("%lf",&x);
        a.push_back(mp(-v[i]/x,mp(v[i],x)));
    }
    double cur=0;
    double ans=0;
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
        if(cur+a[i].sd.sd<=m)
        {
            cur+=a[i].sd.sd;
            ans+=a[i].sd.ft;
        }
        else
        {
            double nkr=(m-cur);
            ans+=(nkr/a[i].sd.sd)*a[i].sd.ft;
            break;
        }
    }
    printf("%.4f",ans);
    return 0;
}
