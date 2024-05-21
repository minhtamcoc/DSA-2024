#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool visited[100];
int dx[4]={2,3,5,7};
void ins(){
	for(int i=1;i<=n;i++){
		if(a[i]<=4) cout<<dx[a[i]-1];
		else{
			int tmp=a[i]%4;
			cout<<dx[tmp-1];
		}
	}
	cout<<endl;
}
void Try(int i){	
	for(int j=1;j<=n;j++){
		if(!visited[j]){
			visited[j]=true;
			a[i]=j;
			if(i==n){
				int tmp=a[n]%4;
				if(tmp!=1) ins();
			}
			else Try(i+1);
			visited[j]=false;
		}
	}
}
int main(){
	cin>>n;
	Try(1);
	return 0;
}