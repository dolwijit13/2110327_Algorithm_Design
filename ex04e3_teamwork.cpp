#include<bits/stdc++.h>
using namespace std;

double a[105];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    double x;
    double s=0;
    vector<double>v;
    for(int i=0;i<m;i++)
    {
        scanf("%lf",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        a[i%n]+=v[i];
        s+=a[i%n];
    }
    printf("%.3f",s/m);
}
