#include<bits/stdc++.h>
using namespace std;
int c;
char k;
vector<char> v;
void Try(char i){
    if(v.size()>c) return ;
    if(v.size()==c){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return ;
    }
    for(char j=i;j<=k;j++){
        v.push_back(j);
        Try(j);
        v.pop_back();
    }
}
int main(){
    cin>>k>>c;
    Try('A');
    return 0;
}