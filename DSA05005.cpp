#include<bits/stdc++.h>
using namespace std;
const int mode =1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        for(int i=0;i<n;i++) cin>>a[i];
        int l[n+1]={0};
        int res=0;
        for(int i=0;i<n;i++){
            l[i]=1;
            for(int j=0;j<i;j++){
                if(a[i]>=a[j]&&l[i]<l[j]+1){
                    l[i]=l[j]+1;
                }
            }
            res=max(res,l[i]);
        }
        cout<<n-res<<endl;
    }
    return 0;
}