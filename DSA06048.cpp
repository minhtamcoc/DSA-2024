#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[100005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) cnt++;
            else break;
        }
        if(cnt==n) cout<<"0"<<endl;
        else{
            cout<<cnt<<endl;
        }
    }
    return 0;
}