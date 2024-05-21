#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
int b[100];
int cnt;
bool visited[100];
bool check(int a[],int b[]){
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(!visited[j]){
			visited[j]=true;
			b[i]=j;
			if(i==n){
				cnt++;
				if(check(a,b)){
					cout<<cnt<<endl;
				}
			}
			else Try(i+1);
			visited[j]=false;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		Try(1);
	}
	return 0;
}