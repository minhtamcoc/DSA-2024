#include<bits/stdc++.h>
using namespace std;
// n-k+i;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[k+1];
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		int idx=k;
		while(idx>=1&&a[idx]==n-k+idx){
			idx--;
		}
		if(idx>=1){
			a[idx]++;
			for(int i=idx+1;i<=k;i++){
				a[i]=a[idx]+i-idx;
			}
			for(int i=1;i<=k;i++) cout<<a[i]<<" ";
		}
		else for(int i=1;i<=k;i++) cout<<i<<" ";
		cout<<endl;
		}
		return 0;
	}