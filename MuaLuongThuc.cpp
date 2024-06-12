#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,s,m;
		cin>>n>>s>>m;
		int tongluongthuc=m*s;
		int songaymocua=((s/7)*6+(s%7));
		if(tongluongthuc>songaymocua*n) cout<<"-1"<<endl;
		else{
			int res=(tongluongthuc+n-1)/n;
			cout<<res<<endl;
		}
	}
}