#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<int> v[1001];
void ins(){
    cin>>V>>E;
    memset(v,0,sizeof(v));
    for(int i=1;i<=E;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void res(){
    int dem1=0; // dem so dinh bac chan
    int dem2=0; // dem so dinh bac le
   for(int i=1;i<=V;i++){
    if(v[i].size()%2==0) dem1++;
    else dem2++;
   }
   if(dem1==V) cout<<"2"<<endl;
   else if(dem2==2) cout<<"1"<<endl;
   else cout<<"0"<<endl;
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ins();
       res();
    }
    return 0;
}