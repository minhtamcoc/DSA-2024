#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        int a[n1+1];
        int b[n2+1];
        int c[n3+1];
        for(int i=0;i<n1;i++) cin>>a[i];
        for(int i=0;i<n2;i++) cin>>b[i];
        for(int i=0;i<n3;i++) cin>>c[i];
        int i=0;
        int j=0;
        int k=0;
       vector<int> v;
        bool check=false;
        while(i<n1&&j<n2&&k<n3){
            if(a[i]==b[j]&&b[j]==c[k]){
                v.push_back(a[i]);
                check=true;
                i++;
                j++;
                k++;
            }
            else if(a[i]<b[j]) i++;
            else if(c[k]>b[j]) j++;
            else k++;
        }
        if(!check) cout<<"-1";
        else {
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}