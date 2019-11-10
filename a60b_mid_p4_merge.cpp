#include<bits/stdc++.h>
using namespace std;

int k;
int cnt=1;
int a[100005];

int main()
{
    int n;
    scanf("%d %d",&n,&k);
    if(k%2==0)
    {
        printf("-1");
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            a[i]=i+1;
        }
        queue<pair<int,int> >q;
        q.push(make_pair(0,n));
        while(cnt<k && !q.empty())
        {
            int l=q.front().first;
            int r=q.front().second;
            q.pop();
            if(cnt==k) break;
            if(l==r) break;

            int mid=(l+r)/2;
            if(mid==l || mid==r) break;
            cnt+=2;
            int ft=mid;
            if((r-l)%2==1) ft++;
            queue<int>tmp;
            for(int i=ft;i<r;i++)
            {
                tmp.push(a[i]);
            }
            for(int i=l;i<ft;i++)
            {
                tmp.push(a[i]);
            }
            for(int i=l;i<r;i++)
            {
                a[i]=tmp.front();
                tmp.pop();
            }
            q.push(make_pair(l,mid));
            q.push(make_pair(mid,r));
        }
        if(cnt==k)
        {
            for(int i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
        }
        else
        {
            printf("-1");
        }

    }
    return 0;
}
