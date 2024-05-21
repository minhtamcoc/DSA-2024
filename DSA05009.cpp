#include<bits/stdc++.h>
using namespace std;
int n;
int a[105];
int check;
void Try(int s,int i,int k){
    if(check==1) return ;
    for(int j=i;j<=n;j++){
        if(s+a[i]==k&&check==0){
            check=1;
            cout<<"YES"<<endl;
            return ;
        }
        else if(s+a[i]<k) Try(s+a[i],j,k);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        check=0;
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==1) cout<<"NO"<<endl;
        else{
            Try(0,1,sum/2);
        }
    }
    return 0;
}