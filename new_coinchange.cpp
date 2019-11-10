#include<stdio.h>
#include<algorithm>

using namespace std;

int cc(int a[], int v, int m, int t, int b[]){
    if(v == 0)  return 0;
    if(v < 0 || m >= t)   return 100000;
    if(v==144) printf("----%d\n",a[m]);
    if(b[v] != 0) return b[v];
    if(v==144) printf("aaaaa%d %d %d\n",a[m],v-a[m],cc(a,v-a[m],m,t,b));
    return b[v] = min(cc(a, v, m+1, t, b),cc(a,v-a[m],m,t,b)+1);
}

int main(){
    int t,v;
    scanf("%d %d",&t,&v);
    int a[t];
    int b[10005];
    for(int i = 0; i < v+1; i++){
        b[i] = 0;
    }
    for(int i = 0; i < t; i++){
        scanf("%d",&a[i]);
        b[a[i]] = 1;

    }
    printf("%d\n",cc(a,v,0,t,b));
    for(int i=1;i<=v;i++)
    {
        printf("%d %d\n",i,b[i]);
    }
    return 0;
}
