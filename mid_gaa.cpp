#include<bits/stdc++.h>
using namespace std;

vector<int>dp;

bool f(int x)
{
    if(x==1) return 1;
    if(x<=3) return 0;

    int k=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
    x-=dp[k-1];
    if(x==1) return 1;
    if(x<=(k+3)) return 0;

    return f(x-(k+3));

}

int main()
{
    int n;
    scanf("%d",&n);
    int k=0;
    dp.push_back(3);
    while(dp[k]<n)
    {
        k++;
        dp.push_back(dp[k-1]*2+(k+3));
    }
    k--;
    if(f(n)) printf("g");
    else printf("a");
    return 0;
}
