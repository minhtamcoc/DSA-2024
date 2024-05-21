#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double a[n+1];
        double b[n+1];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        int l[n+1];
        int ans=-1e9;
        for(int i=0;i<n;i++){
            l[i]=1;
            for(int j=0;j<i;j++){
                if(a[i]>a[j]&&b[i]<b[j]&&l[i]<l[j]+1){
                    l[i]=l[j]+1;
                }
            }
            ans=max(ans,l[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}