#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int idx=n-1;
		while(idx>=1&&a[idx]>a[idx+1]){
			idx--;
		}
		if(idx>=1){
			int x=n;
			while(a[idx]>a[x]){
				x--;
			}
			swap(a[idx],a[x]);
			sort(a+idx+1,a+n);
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
		}
		else for(int i=1;i<=n;i++) cout<<i<<" ";
		cout<<endl;
	}
}