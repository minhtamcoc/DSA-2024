#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[105][105];
int cnt=0;
int x[8]={-1,-1,-1,0,0,1,1,1};
int y[8]={-1,0,1,-1,1,-1,0,1};
void Try(int i,int j){
    a[i][j]='.';
    for(int k=0;k<8;k++){
        int i1=i+x[k];
        int j1=j+y[k];
        if(i1<n&&i1>=0&&j1<m&&j1>=0&&a[i1][j1]=='W'){
            Try(i1,j1);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                cnt++;
                Try(i,j);
            }
        }
    }
    cout<<cnt<<endl;
}
int main(){
    solve();
    return 0;
}