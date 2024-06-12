#include<bits/stdc++.h>
using namespace std;
long long F[100];
char Try(long long n,long long k){
	if(n==1) return 'A';
	if(n==2) return 'B';
	if(k<=F[n-2]) return Try(n-2,k);
	return Try(n-1,k-F[n-2]);
}
int main(){
	int t;
	cin>>t;
	F[1]=1;
	F[2]=1;
	for(int i=3;i<93;i++){
		F[i]=F[i-1]+F[i-2];
	}
	while(t--){
		long long n,k;
		cin>>n>>k;
		cout<<Try(n,k)<<endl;
	}
	return 0;
}