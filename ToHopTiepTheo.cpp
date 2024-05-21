#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
int b[100];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=k;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		int idx=k;
		while(idx>=1&&b[idx]==n-k+idx){
			idx--;
		}
		if(idx>=1){
			b[idx]++;
			for(int i=idx+1;i<=k;i++){
				b[i]=b[idx]+i-idx;
			}
			int cnt=0;
			for(int i=1;i<=k;i++){
				for(int j=1;j<=k;j++){
					if(a[i]==b[j]) cnt++;
				}
			}
			cout<<k-cnt<<endl;
		}
		else{
			cout<<k<<endl;
		}
	}
}