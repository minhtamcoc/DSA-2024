#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l[n+1]={0};
        int res=0;
        for(int i=0;i<n;i++){
            l[i]=0;
            for(int j=0;j<i;j++){
                if(s[i]==s[j]&&l[i]<l[j]+1){
                    l[i]=l[j]+1;
                }
            }
            res=max(res,l[i]);
        }
        cout<<res<<endl;
    }
}