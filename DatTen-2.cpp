#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
void ins(){
	for(int i=1;i<=k;i++){
		char tmp=a[i]+64;
		cout<<tmp;
	}
	cout<<endl;
}
void Try(int i){
	for(int j=a[i-1]+1;j<=n-k+i;j++){
		a[i]=j;
		if(i==k){
			ins();
		}
		else Try(i+1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		Try(1);
	}
	return 0;
}