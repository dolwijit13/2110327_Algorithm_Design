#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second


int main()
{
    int n;
    scanf("%d",&n);
    vector<int>s(n);
    vector<pair<int,int> >a; ///(f,s)
    int i,j;
    for(i=0;i<n;i++) scanf("%d",&s[i]);
    for(i=0;i<n;i++)
    {
        int f;
        scanf("%d",&f);
        a.push_back(mp(f,s[i]));
    }
    sort(a.begin(),a.end());
    int ans=0;
    int last=0;
    for(i=0;i<n;i++)
    {
        if(last<=a[i].sd)
        {
            ans++;
            last=a[i].ft;
        }
    }
    printf("%d",ans);
}
