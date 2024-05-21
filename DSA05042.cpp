#include<bits/stdc++.h>
using namespace std;
string check(long long n,long long k,vector<long long>& v){
    if(k==0) return "NO";
    multiset<long long> st;
    for(int i=1;i<n+1;i++) st.insert(v[i]);
    for(int i=0;i<n+1;i++){
        if(st.count(v[i]-k)!=0) return "YES";
    }
    return "NO";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> v(n+1,0);
        for(int i=1;i<n+1;i++){
            cin>>v[i];
        }
        for(int i=1;i<n+1;i++) v[i]+=v[i-1];
        cout<<check(n,k,v)<<endl;
}   
return 0;
}