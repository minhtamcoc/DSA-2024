#include<bits/stdc++.h>
using namespace std;
int n;
int a[15];// cau hinh
int chiphi[105][105];
int check[105];
int res=1e9;
int cost=0;
int cmin=1e9;
void Try(int i){
    for(int j=2;j<=n;j++){
        if(check[j]==0){
        a[i]=j;
        check[j]=1;
        cost+=chiphi[a[i-1]][a[i]];
        if(i==n){
            res=min(res,cost+chiphi[a[n]][1]);
        }
        else if(cost+(n-i+1)*cmin<res) Try(i+1);
        check[j]=0;
        cost-=chiphi[a[i-1]][a[i]];
    }
}
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>chiphi[i][j];
           if(chiphi[i][j]!=0) cmin=min(cmin,chiphi[i][j]);
        }
    }
    memset(check,0,sizeof(check));
     a[1]=1;
    Try(2);
    cout<<res<<endl;
}