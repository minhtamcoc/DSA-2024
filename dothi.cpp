#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<pair<int,int>> T;
int parents[1001];
struct canh{
	int a,b,c;
};
bool cmp(canh x,canh y){
	return x.c<y.c;
}
void solve(){
	cin>>V>>E;
	canh ds[E+1];
	for(int i=1;i<=E;i++){
		cin>>ds[i].a>>ds[i].b>>ds[i].c;
	}
	sort(ds+1,ds+1+E,cmp);
	for(int i=1;i<=V;i++) parents[i]=i;
	int idx=1;
	int res=0;
	while(T.size()<V-1){
		if(parents[ds[idx].a]!=parents[ds[idx].b]){
			res+=ds[idx].c;
			T.push_back({ds[idx].a,ds[idx].b});
			int old=parents[ds[idx].b];
			for(int i=1;i<=V;i++){
				if(parents[i]==old){
					parents[i]=parents[ds[idx].a];
				}
			}
		}
		idx++;
	}
	cout<<res<<endl;
	for(int i=0;i<T.size();i++){
		cout<<"{"<<T[i].first<<","<<T[i].second<<"}"<<endl;
	}
	T.clear();
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}