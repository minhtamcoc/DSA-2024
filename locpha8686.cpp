#include<bits/stdc++.h>
using namespace std;
void ins(string s){
	for(int i=s.size()-1;i>=0;i--) cout<<s[i];
}
void solve(int n){
	queue<string> q;
	q.push("6");
	q.push("8");
	vector<string> v;
	while(!q.empty()){
		string tmp=q.front();
		q.pop();
		v.push_back(tmp);
		if(v.size()==n) break;
		q.push(tmp+"6");
		q.push(tmp+"8");
	}
	for(int i=0;i<v.size();i++) {
		cout<<v[i];
		ins(v[i]);
		cout<<" ";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
		cout<<endl;
	}
}