#include<bits/stdc++.h>
using namespace std;
string check(int a[],int k,int n){
    for(int i=0;i<n;i++){
        if(a[i]>=k) break;
        for(int j=i+1;j<n;j++){
            if(binary_search(a+j+1,a+n,k-a[i]-a[j])) return "YES";
        }
    }
    return "NO";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<check(a,k,n)<<endl;
    }
}