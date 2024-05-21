#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int x[100005];
        int y[100005];
        x[0]=1;
        y[n-1]=1;
        for(int i=1;i<=n-1;i++){
            if(a[i]>a[i-1]) x[i]=x[i-1]+1;
            else x[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(a[i]>a[i+1]) y[i]=y[i+1]+1;
            else y[i]=1;
        }
        int res=-1e9;
        for(int i=0;i<n;i++){
            res=max(res,x[i]+y[i]-1);
        }
        cout<<res<<endl;
    }
    return 0;
}