#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        while(1){
            int idx=s.find("()");
            if(idx==-1) break;
            else{
                cnt+=2;
                s.erase(idx,2);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}