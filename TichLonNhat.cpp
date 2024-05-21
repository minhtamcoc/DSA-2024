#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int x=a[0]*a[1];//2 thang nho nhat
	int b=a[n-1]*a[n-2] ;// hai thang lon nhat
	int c=a[0]*a[1]*a[n-1];
	int d=a[n-1]*a[n-2]*a[n-3];
	cout<<max(x,max(b,max(c,d)))<<endl;
	return 0;
}