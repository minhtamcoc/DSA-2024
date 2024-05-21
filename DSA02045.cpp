#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
void Try(int i,string sum,int idx){
    if(idx>n) return;
    for(int j=i;j<n;j++){
        idx++;
        if(idx<=n) v.push_back(sum+s[j]);
        Try(j+1,sum+s[j],idx);
        idx--;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin.ignore();
        cin>>s;
        Try(0,"",0);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        v.clear();
        cout<<endl;
    }
   return 0;
}