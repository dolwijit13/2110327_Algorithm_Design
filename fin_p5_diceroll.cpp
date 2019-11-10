#include<bits/stdc++.h>
using namespace std;

int a[10];
class int2
{
public:
    int i;
    int2()
    {
        i=999999999;
    }

    int2(int x)
    {
        i=x;
    }

    int2 operator+(int2 a,int2 b)
    {
        return int2(a.i+b.i);
    }

    int2 operator>(int2 a,int2 b)
    {
        return a.i>b.i;
    }

    int2 operator<(int2 a,int2 b)
    {
        return a.i<b.i;
    }
};
map<vector<int>,int2>dp[15][15];

vector<int> change(vector<int>before,char s[5])
{
    vector<int>order;
    if(s[0]=='u') order={4,5,2,3,1,0};
    else if(s[0]=='l') order={3,2,0,1,4,5};
    else if(s[0]=='r') order={2,3,1,0,4,5};
    else if(s[0]=='d') order={5,4,2,3,0,1};
    for(int i=0;i<6;i++) order[i]=before[order[i]];
    for(int i=0;i<6;i++) before[i]=order[i];
    return before;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<6;i++) scanf("%d",&a[i]);
    vector<int>tmp{0,1,2,3,4,5};
    dp[0][0][tmp]=int2(0);
    for(i=1;i<=n*m*6*4;i++)
    {

    }
    return 0;
}
