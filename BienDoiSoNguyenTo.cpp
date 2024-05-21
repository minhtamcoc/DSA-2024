#include<bits/stdc++.h>
using namespace std;
bool nt(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return n>1;
}
void solve(string s,string t){
    queue<pair<string,int>> q;
    q.push({s,0});
    char dx[10]={'0','1','2','3','4','5','6','7','8','9'};
    set<string> st;
    st.insert(s);
    while(!q.empty()){
        pair<string,int> tmp=q.front();
        string x=tmp.first;
        int cnt=tmp.second;
        q.pop();
        if(x==t){
            cout<<cnt<<endl;
            break;
        }
        for(int i=0;i<4;i++){
            string k=x;
            for(int j=0;j<10;j++){
                k[i]=dx[j];
                if(k[0]=='0') continue;
                int res=(k[0]-'0')*1000+(k[1]-'0')*100+(k[2]-'0')*10+(k[3]-'0');
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