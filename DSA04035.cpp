#include<bits/stdc++.h>
using namespace std;
int a;
long long b;
long long pow1(int a,long long b){
    if(b==0) return 1;
    long long x=pow1(a,b/2);
    if(b%2==0) return x*x%1000000007;
     return a*(x*x%1000000007)%1000000007;
}
int main(){
    while(1){
        cin>>a>>b;
        if(a==0&&b==0) break;
        cout<<pow1(a,b)<<endl;
    }
    return 0;
}