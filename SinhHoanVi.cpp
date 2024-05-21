#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];
bool visited[10];
void ins(){
    for(int i=1;i<=n;i++) cout<<a[i];
    cout<<" ";
}
void Try(int i){
    for(int j=1;j<=n;j++){
        if(!visited[j]){
            visited[j]=true;
            a[i]=j;
            if(i==n) ins();
            else Try(i+1);
            visited[j]=false;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Try(1);
        cout<<endl;
    }
}