#include<bits/stdc++.h>
using namespace std;
int n,k,s,check;
int a[100];
bool visited[100];
int dem=0;
void Try(int sum,int dem){
    if(check==1) return;
    if(dem==k){
        check=1;
        return;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            if(sum==s){
                Try(0,dem+1);
            }
            if(sum>s) return;
            else Try(sum+a[i],dem);
        }
        visited[i]=false;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        s=0;
        check=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            visited[i]=false;
            s+=a[i];
        }
        if(s%k!=0) cout<<"0"<<endl;
        else{
            s/=k;
            Try(0,0);
            if(check==1) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    return 0;
}