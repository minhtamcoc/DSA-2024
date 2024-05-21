#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    int a[100][100];
    memset(a,0,sizeof(a));
    for(int i=1;i<=t;i++){
        string s;
        getline(cin,s);
        int res=0;
        s+=" ";
        for(int j=0;j<s.size();j++){
            if(isdigit(s[j])){
                int x=s[j]-48;
                res=res*10+x;
            }
            else{
                a[i][res]=a[res][i]=1;
                res=0;
            }
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=i+1;j<=t;j++){
            if(a[i][j]==1){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}