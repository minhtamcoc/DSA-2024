#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            a[i][x]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                cout<<j<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}