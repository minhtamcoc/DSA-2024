#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
vector<int> c;
vector<vector<int>> l;
void Try(int i){
	for(int j=i;j<=n;j++){
		c.push_back(j);
		l.push_back(c);
		Try(j+1);
		c.pop_back();
	}
}
int main(){
	cin>>n;
	cin.ignore();
	string s;
	getline(cin,s);
	stringstream ss(s);
	string tmp;
	while(ss>>tmp){
		v.push_back(tmp);
	}
	Try(1);
	map<string,int> mp;
	for(int i=0;i<l.size();i++){
		string tmp="";
		for(int j=0;j<l[i].size();j++){
			tmp+=v[l[i][j]-1];
		}
		mp[tmp]++;
	}
	for(auto x:mp) cout<<x.first<<endl;
	v.clear();
	c.clear();
	l.clear();
	return 0;
}