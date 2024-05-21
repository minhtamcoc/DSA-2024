#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    int a[100001]={0};
    queue<int> q;
    q.push(n);
    while(!q.empty()&&a[1]==0){
        int x=q.front();
        q.pop();
        if(x/2>0&&x%2==0&&a[x/2]==0){
            a[x/2]=a[x]+1;
            q.push(x/2);
        }
        if(x/3>0&&x%3==0&&a[x/3]==0){
            a[x/3]=a[x]+1;
            q.push(x/3);
        }
         if(x-1>0&&a[x-1]==0){
            a[x-1]=a[x]+1;
            q.push(x-1);
        }
    }
    return a[1];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}