#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505][505];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0) dp[i][j]=a[i][j];
			else if((i==0)&&j>0) dp[i][j]=dp[i][j-1]+a[i][j];
			else if((j==0)&&i>0) dp[i][j]=dp[i-1][j]+a[i][j];
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j])+a[i][j];
			}
		}
	}
	cout<<dp[n-1][m-1]<<endl;
	return 0;
}