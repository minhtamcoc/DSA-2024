#include<bits/stdc++.h>
using namespace std;
// tron 2 day con1:[l,m] ,day con2:[m+1,r]
void merge(int a[],int l,int m,int r){
// a[] la mang muc tieu
        vector<int> x(a+l,a+m+1);// coppy [)
        vector<int> y(a+m+1,a+r+1); // coppy [)
        int i=0; // khoi tao moc 1
        int j=0; // khoi tao moc 2
        int k=l;
        while(i<x.size()&&j<y.size()){
            if(x[i]<=y[j]){ // so sanh xong tang
                a[k]=x[i];
                i++;
            }
            else{
                a[k]=y[j];
                j++;      
            }
            k++;
        }
        while(i<x.size()){ // kiem tra con thua hay khog
            a[k]=x[i];
            k++;
            i++;
        }
        while(j<y.size()){ // kiem tra con thua hay khong
            a[k]=y[j];
            k++;
            j++;
        }
}
void mergesort(int a[],int l,int r){
if(l>=r) return;
int m=(l+r)/2;
mergesort(a,l,m);
mergesort(a,m+1,r);
merge(a,l,m,r);
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
      return 0;
}