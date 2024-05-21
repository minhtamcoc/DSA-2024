#include<bits/stdc++.h>
using namespace std;
struct congviec{
	int a,b,c;
};
bool cmp(congviec x,congviec y){
	return x.b<y.b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		congviec ds[1001];
		for(int i=0;i<n;i++){
			cin>>ds[i].a>>ds[i].b>>ds[i].c;
		}
		sort(ds,ds+n,cmp);
		priority_queue<int,vector<int>,greater<int>> pq;
		for(int i=0;i<n;i++){
			pq.push(ds[i].c);
			while(ds[i].b<pq.size()){
				pq.pop();
			}
		}
		cout<<pq.size()<<" ";
		int res=0;
		while(!pq.empty()){
			res+=pq.top();
			pq.pop();
		}
		cout<<res<<endl;
	}
}