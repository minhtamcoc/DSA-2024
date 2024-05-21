#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int V,E;
void ins(){
    cin>>V>>E;
    memset(a,0,sizeof(a));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }
    int dem=0;
    for(int i=1;i<=V;i++){
        int cnt=0; // tong cac hang
        int res=0;
        for(int j=1;j<=V;j++){
            cnt+=a[i][j];
            res+=a[j][i];
        }
        if(cnt==res) dem++;
    }
    if(dem==V) cout<<"1"<<endl;
    else cout<<"0"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
    }
}