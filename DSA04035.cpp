#include<bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<iomanip>
#include <cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<string>
using namespace std;
long long pow1(int a,long long b){
    long long x=pow(a,b/2);
    if(b%2==0) return x*x%1000000007;
    return a*(x*x%1000000007)%1000000007;
}
int main(){
    int a;
    long long b;
    while(1){
        cin>>a>>b;
        if(a==0&&b==0) break;
        cout<<pow1(a,b)<<endl;
    }
    return 0;
}