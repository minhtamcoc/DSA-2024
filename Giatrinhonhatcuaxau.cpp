#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>k>>s;
        map<char,long long> mp;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        priority_queue<long long> q;
        for(auto x:mp) q.push(x.second);
        while(k>0&&!q.empty()){
            long long tmp=q.top();
            q.pop();
            tmp--;
            q.push(tmp);
            k--;
        }
        long long res=0;
        while(!q.empty()){
                long long l=q.top();
                q.pop();
                res+=l*l;
        }
        cout<<res<<endl;
    }
    return 0;
}