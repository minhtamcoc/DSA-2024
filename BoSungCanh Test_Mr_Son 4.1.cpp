#include<bits/stdc++.h>
using namespace std;
int V,E;
int parents[1001];
int num[1001];
void Setup(){
	for(int i=1;i<=V;i++){
		parents[i]=i;
		num[i]=1;
	}
}
int Find(int u){
	if(u==parents[u]) return u;
	return Find(parents[u]);
}
void Union(int u,int v){
	int a=Find(u);
	int b=Find(v);
	if(a==b) return;
	if(num[a]<num[b]) swap(a,b);
	parents[b]=a;
	num[a]+=num[b];
}
int main(){
		cin>>V>>E;
		Setup();
		for(int i=1;i<=E;i++){
			int x,y;
			cin>>x>>y;
			Union(x,y);
		}
		int cnt=0;
		map<int,int> mp;
		for(int i=1;i<=V;i++){
			mp[Find(i)]++;
		}
		if(mp.size()==1) cout<<num[1]<<endl;
		else{
			int res=-1e9;
			for(int i=2;i<=V;i++){
				if(res<num[i]) res=num[i];
			}
			cout<<res+num[1]<<endl;
		}
	return 0;
}