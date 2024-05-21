#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[105];
        for(int i=0;i<n;i++) cin>>a[i];
        int x[105];
        int y[105];
        for(int i=0;i<n;i++){
            x[i]=a[i];
            for(int j=0;j<i;j++){
                if(a[i]>a[j]&&x[i]<x[j]+a[i]){
                    x[i]=x[j]+a[i];
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            y[i]=a[i];
            for(int j=n-1;j>i;j--){
                if(a[i]>a[j]&&y[i]<y[j]+a[i]){
                    y[i]=y[j]+a[i];
                }
            }
        }
        int res=-1e9;
        for(int i=0;i<n;i++){
            res=max(res,x[i]+y[i]-a[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}