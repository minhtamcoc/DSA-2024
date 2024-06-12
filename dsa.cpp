#include<bits/stdc++.h>
using namespace std;
char dx[10]={'0','1','2','3','4','5','6','7','8','9'};
bool nt(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return n>1;
}
void solve(string s,string t){
    queue<pair<string,int>> q;
    q.push({s,0});
    set<string> st;
    st.insert(s);
    while(!q.empty()){
        pair<string,int> tmp=q.front();
        q.pop();
        string x=tmp.first;
        int cnt=tmp.second;
        if(x==t){
            cout<<cnt<<endl;
            break;
        }
        for(int i=0;i<4;i++){
            string k=x;
            for(int j=0;j<10;j++){
                k[i]=dx[j];
                if(k[0]=='0') continue;
                int res=stoi(k);
                if(nt(res)&&st.count(k)==0){
                    q.push({k,cnt+1});
                    st.insert(k);
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        solve(s,t);
    }
    return 0;
}