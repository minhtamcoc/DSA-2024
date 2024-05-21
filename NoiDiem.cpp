#include<bits/stdc++.h>
using namespace std;
int N;
int parents[1001];
vector<pair<int,int>> T;
struct canh{
	int x,y;
	double z;
};
struct diem{
	double a,b;
};
double check(diem l,diem r){
	double ans=sqrt(pow((l.a-r.a),2)+pow((l.b-r.b),2));
	return ans;
}
bool cmp(canh l,canh r){
	return l.z<r.z;
}
void solve(){
	cin>>N;
	vector<canh> ds;
	vector<diem> dinh(N+1);
	for(int i=1;i<=N;i++){
		cin>>dinh[i].a>>dinh[i].b;
	}
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			canh tmp;
			tmp.x=i;
			tmp.y=j;
			tmp.z=check(dinh[i],dinh[j]);
			ds.push_back(tmp);
		}
	}
	sort(ds.begin(),ds.end(),cmp);
	for(int i=1;i<=N;i++){
		parents[i]=i;
	}
	double res=0;
	double idx=0;
	while(T.size()<N-1){
		if(parents[ds[idx].x]!=parents[ds[idx].y]){
			res+=ds[idx].z;
			T.push_back({ds[idx].x,ds[idx].y});
			int old=parents[ds[idx].y];
			for(int i=1;i<=N;i++){
				if(parents[i]==old){
					parents[i]=parents[ds[idx].x];
				}
			}
		}
		idx++;
	}
	cout<<fixed<<setprecision(6)<<res<<endl;
	T.clear();
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}