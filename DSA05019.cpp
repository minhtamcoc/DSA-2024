#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505][505];
int b[505][505];
void solve(){
    cin>>n>>m;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int res=-1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0) b[i][j]=a[i][j];
            else{
                if(a[i][j]==1){
                    b[i][j]=min(b[i][j-1],min(b[i-1][j-1],b[i-1][j]))+1;
                }
                else b[i][j]=a[i][j];
            }
            res=max(res,b[i][j]);
        }
    }
    cout<<res<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}