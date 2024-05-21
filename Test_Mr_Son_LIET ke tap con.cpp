#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<string> v;
int a[100];
vector<string> T;
void ins(){
	string tmp="";
	for(int i=1;i<=k;i++){
		tmp+=v[a[i]-1];
	}
	T.push_back(tmp);
}
void Try(int i){
	for(int j=a[i-1]+1;j<=n-k+i;j++){
		a[i]=j;
		if(i==k) ins();
		else Try(i+1);
	}
}
int main(){
	cin>>n>>k;
	cin.ignore();
	string s;
	getline(cin,s);
	stringstream ss(s);
	string tmp;
	while(ss>>tmp){
		 v.push_back(tmp);
	}
	n=v.size();
	Try(1);
	map<string,int> mp;
	for(int i=0;i<T.size();i++){
		mp[T[i]]++;
	}
	for(auto x:mp) cout<<x.first<<endl;
	return 0;
}