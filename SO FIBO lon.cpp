#include<bits/stdc++.h>
using namespace std;
const long long mode=1e9+7;
struct matran{
	long long a[2][2]={1,1,1,0};
};
matran operator*(matran A,matran B){
	matran C;
	for(int k=0;k<2;k++){
		for(int i=0;i<2;i++){
			C.a[i][k]=0;
			for(int j=0;j<2;j++){
				C.a[i][k]=(C.a[i][k]%mode+A.a[i][j]*B.a[j][k]%mode)%mode;
			}
		}
	}
	return C;
}
matran POW1(matran A,long long n){
	if(n==1) return A;
	matran tmp=POW1(A,n/2);
	if(n%2==0) return tmp*tmp;
	return A*tmp*tmp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		matran A;
		matran X;
		X=POW1(A,n);
		cout<<X.a[1][0]<<endl;
	}
	return 0;
}