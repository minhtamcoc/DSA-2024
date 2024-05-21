#include<bits/stdc++.h>
using namespace std;
int check(long long n,long long k){
	long long tmp=pow(2,n-1);
	if(k==tmp) return n;
	if(k<tmp) return check(n-1,k);
	return check(n-1,k-tmp);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		cout<<check(n,k)<<endl;
	}
	return 0;
}