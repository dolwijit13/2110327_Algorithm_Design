#include<bits/stdc++.h>
using namespace std;

char a[150005];
char b[150005];

bool dq(int st1,int ed1,int st2,int ed2)
{
    int i,j;
    int n=(ed1-st1+1);
    if(n==1)
    {
        //printf("%c %c\n",a[st1],b[st2]);
        if(a[st1]==b[st2]) return true;
        return false;
    }
    bool chk=1;
    for(i=0;i<n;i++)
    {
        if(a[st1+i]!=b[st2+i])
        {
            chk=0;
            break;
        }
    }
    if(chk) return true;
    int mid1=(st1+ed1)/2;
    int mid2=(st2+ed2)/2;
    //printf("%d %d\n",mid1,mid2);
    int tmp[5][27]; ///a1 a2 b1 b2
    for(i=1;i<=4;i++)
    {
        for(j=0;j<26;j++) tmp[i][j]=0;
    }
    for(i=st1;i<=mid1;i++) tmp[1][a[i]-'a']++;
    for(i=mid1+1;i<=ed1;i++) tmp[2][a[i]-'a']++;
    for(i=st2;i<=mid2;i++) tmp[3][b[i]-'a']++;
    for(i=mid2+1;i<=ed2;i++) tmp[4][b[i]-'a']++;
    bool chk1=1;
    for(j=0;j<26;j++)
    {
        if(tmp[1][j] != tmp[3][j]) chk1=0;
        if(tmp[2][j] != tmp[4][j]) chk1=0;
    }
    bool chk2=1;
    for(j=0;j<26;j++)
    {
        //printf("--%d %d\n",tmp[1][j],tmp[4][j]);
        if(tmp[1][j] != tmp[4][j]) chk2=0;
        if(tmp[2][j] != tmp[3][j]) chk2=0;
    }
    bool ans=0;
    if(chk1) ans|= (dq(st1,mid1,st2,mid2)&dq(mid1+1,ed1,mid2+1,ed2));
    if(chk2) ans|= (dq(st1,mid1,mid2+1,ed2)&dq(mid1+1,ed1,st2,mid2));
    //printf("%d %d %d   %d %d %d %d\n",ans,chk1,chk2,st1,ed1,st2,ed2);
    return ans;
}

int main()
{
    scanf("%s",a);
    scanf("%s",b);
    if(dq(0,strlen(a)-1,0,strlen(b)-1)) printf("YES");
    else printf("NO");
    return 0;
}
