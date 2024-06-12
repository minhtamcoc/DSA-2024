#include<bits/stdc++.h>
using namespace std;
set<string> st;
void solve(string a,string b){
    queue<pair<string,int>> q;
    q.push({a,1});
    int n=a.size();
    while(!q.empty()){
        pair<string,int> tmp=q.front();
        q.pop();
        string s=tmp.first;
        int cnt=tmp.second;
        if(s==b){
            cout<<cnt<<endl;
            break;
        }
        for(int i=0;i<n;i++){
            char c=s[i];
            for(char j='A';j<='Z';j++){
                s[i]=j;
                if(st.count(s)!=0){
                    st.erase(s);
                    q.push({s,cnt+1});
                }
            }
            s[i]=c;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        while(n--){
            string tmp;
            cin>>tmp;
            if(tmp!=a) st.insert(tmp);
        }
        solve(a,b);
    }
    return 0;
}