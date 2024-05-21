#include<bits/stdc++.h>
using namespace std;
bool check(string s1,string s2,int n1,int n2){
    if(n1!=n2) return false;
    if(s1.size()!=s2.size()) return false;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1;
        cin>>n1;
        cin.ignore();
        string s1;
        getline(cin,s1);
        int n2;
        cin>>n2;
        cin.ignore();
        string s2;
        getline(cin,s2);
        if(check(s1,s2,n1,n2)) cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}