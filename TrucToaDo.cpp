#include<bits/stdc++.h>
using namespace std;
struct canh{
	int x,y,z;
};
vector<canh> T;
bool cmp(canh a,canh b){
	return a.y<b.y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		canh ds[n+1];
		for(int i=1;i<=n;i++){
			cin>>ds[i].x>>ds[i].y;
			ds[i].z=ds[i].y-ds[i].x;
		}
		sort(ds+1,ds+1+n,cmp);
	int cnt=1;
	int idx=1;
	for(int i=2;i<=n;i++){
		if(ds[i].x>ds[idx].y){
			idx=i;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	}
	return 0;
}