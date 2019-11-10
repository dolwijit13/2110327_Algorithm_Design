#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    int n;
    int i,j;
    int x,y;
    vector<int>v{1,2,4,6};
    int next=4;
    int last=6;
    while(last > 0 && last<2000000000)
    {
        int freq=upper_bound(v.begin(),v.end(),next)-v.begin();
        last+=freq;
        v.push_back(last);
        next++;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",upper_bound(v.begin(),v.end(),n)-v.begin());
    }
    return 0;
}
