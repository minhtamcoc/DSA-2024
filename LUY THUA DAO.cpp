#include<bits/stdc++.h>
using namespace std;
const int mode=1e9+7;
long long check(long long n){
	long long res=0;
	while(n>0){
		int rem=n%10;
		res=res*10+rem;
		n/=10;
	}
	return res;
}
long long POW1(long long n,long long k){
	if(k==0) return 1;
	long long tmp=POW1(n,k/2);
	if(k%2==0) return tmp*tmp%mode;
	return n*(tmp*tmp%mode)%mode;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<POW1(n,check(n))<<endl;
	}
	return 0;
}