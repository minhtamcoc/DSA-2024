#include<bits/stdc++.h>
using namespace std;
long long merge(long long a[],int l,int m,int r){
    vector<long long> x(a+l,a+m+1);
    vector<long long> y(a+m+1,a+r+1);
    int i=0;
    int j=0;
    long long cnt=0;
    while(i<x.size()&&j<y.size()){
        if(x[i]<=y[j]){
            a[l]=x[i];
            i++;
        }
        else{
            a[l]=y[j];
            j++;
        }
        l++;
    }
    while(i<x.size()){
        a[l]=x[i];
        l++;
        i++;
    }
    while(j<y.size()){
        a[l]=y[j];
        j++;
        l++;
    }
    return cnt;
}
long long mergesort(long long a[],int l,int r){
    long long dem=0;
    if(l<r){
        int m=(l+r)/2;
       dem+= mergesort(a,l,m);
       dem+= mergesort(a,m+1,r);
        dem+=merge(a,l,m,r);
    }
    return dem;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n+1];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<mergesort(a,0,n-1)<<endl;
    }
    return 0;
}