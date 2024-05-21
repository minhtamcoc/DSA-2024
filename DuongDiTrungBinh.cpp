#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=1e9;
			}
			dp[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			dp[x][y]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
					}
				}
			}
		}
		float cnt=0;
		float sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]!=0&&dp[i][j]!=1e9){
					sum+=dp[i][j];
					cnt++;
				}
			}
		}
		float ans=sum/cnt;
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}