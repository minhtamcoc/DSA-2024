#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100005];
    int b[100005];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int l[100005];
    int res=-1e9;
    for(int i=0;i<n;i++){
        l[i]=1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j]&&b[i]>b[j]&&l[i]<l[j]+1){
                l[i]=l[j]+1;
            }
        }
        res=max(res,l[i]);
    }
    cout<<res<<endl;
    return 0;
}