#include<bits/stdc++.h>

using namespace std;

int main(){
    int p,n;
    priority_queue<int> q;
    scanf("%d %d",&p,&n);
    int a[p][n];
    int ans[p];
    int b = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        q.push(-x);
    }
    for(int i=0;i<p;i++) ans[i]=0;
    int i = 0;
    int j = 0;
    while(!q.empty()){
        if(i >= p){
           i = 0;
           j++;
        }
        else {
            if(j != 0){
                a[i][j] = a[i][j-1] + (-q.top());
                q.pop();
                ans[i] += a[i][j];
            }
            else{
                a[i][j] = -q.top();
                q.pop();
                ans[i] = a[i][j];
            }
            i++;
        }
    }
    for(int i = 0; i < p; i++){
        //printf("%d %d\n",i,ans[i]);
        b += ans[i];
    }
    double b2=b;
    printf("%.3f",b2/n);
    return 0;
}
