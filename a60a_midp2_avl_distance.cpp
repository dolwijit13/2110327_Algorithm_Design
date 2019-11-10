#include<bits/stdc++.h>
using namespace std;

vector<int>v[50005];
bool chk[50005];
int root;
int ans=0;
int k;

void printVec(int p,vector<int>x)
{
    printf("%d\n",p);
    for(int i=0;i<x.size();i++)printf("%d ",x[i]);
    printf("\n%d\n\n",ans);
}

vector<int> f(int p)
{
    vector<int>ch1,ch2;
    vector<int>ansV;
    int sz=v[p].size();
    if(sz==0) return vector<int>{1};

    if(sz==1)
    {
        ch1=f(v[p][0]);
        if(k-1<ch1.size()) ans+=ch1[k-1];
        ansV.push_back(1);
        for(int i=0;i<ch1.size();i++) ansV.push_back(ch1[i]);
        //printVec(p,ansV);
        return ansV;
    }

    ch1=f(v[p][0]);
    ch2=f(v[p][1]);
    int mx=max(ch1.size(),ch2.size());
    for(int i=1;i<=k-1;i++)
    {
        int j=(k-i);
        if(i>ch1.size() || j>ch2.size()) continue;
        //printf("aaa%d %d %d\n",i-1,ch1[i-1],ch2[i-1]);
        ans+=ch1[i-1]*ch2[j-1];
    }
    if(k-1<ch1.size()) ans+=ch1[k-1];
    if(k-1<ch2.size()) ans+=ch2[k-1];

    ansV.push_back(1);
    for(int i=0;i<mx;i++) ansV.push_back(0);
    for(int i=0;i<ch1.size();i++) ansV[i+1]+=ch1[i];
    for(int i=0;i<ch2.size();i++) ansV[i+1]+=ch2[i];
    //printVec(p,ansV);
    return ansV;
}

int main()
{
    int n;
    int i,j;
    int x,y;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        chk[y]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(!chk[i])
        {
            root=i;
            break;
        }
    }
    f(root);
    //printVec(999,f(root));
    printf("%d",ans);
    return 0;
}
