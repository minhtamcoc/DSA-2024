#include<bits/stdc++.h>
using namespace std;
int n,k;
int s;
int a[100];
vector<string> v;
void ins(){
    for(int i=1;i<=k-1;i++){
        cout<<v[a[i]-1]<<" ";
    }
    cout<<v[a[k]-1];
    cout<<endl;
}
void Try(int i){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
        a[i]=j;
        if(i==k){
            ins();
        }
        else Try(i+1);
    }
}
int main(){
     cin>>n>>k;
    cin.ignore();
    string s;
    getline(cin,s);
    stringstream ss(s);
    string tmp;
    map<string,int> mp;
    while(ss>>tmp){
        mp[tmp]++;
    }
    for(auto x:mp){
        v.push_back(x.first);
    }
    n=v.size();
    Try(1);
    return 0;
}