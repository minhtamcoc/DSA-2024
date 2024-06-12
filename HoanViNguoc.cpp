#include<bits/stdc++.h>
using namespace std;
int n;
int a[50];
bool visited[50];
vector<vector<int>> v;
void Try(int i){
	for(int j=1;j<=n;j++){
		if(!visited[j]){
			a[i]=j;
			visited[j]=true;
			if(i==n){
				vector<int> c;
				for(int i=1;i<=n;i++) c.push_back(a[i]);
				v.push_back(c);
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
		Try(1);
		for(int i=v.size()-1;i>=0;i--){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j];
			}
			cout<<" ";
		}
		cout<<endl;
		v.clear();
	}
	return 0;
}