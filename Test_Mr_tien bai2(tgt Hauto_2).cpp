#include<bits/stdc++.h>
using namespace std;
bool check(string x){
	if(x=="+"||x=="-"||x=="*"||x=="/")return true;
	return false;
}
long long resu(string s){
	if(s[0]=='-'){
		long long res=0;
		for(int i=1;i<s.size();i++){
			int x=s[i]-48;
			res=res*10+x;
		}
		res=0-res;
		return res;
	}
	else{
		long long res=0;
		for(int i=0;i<s.size();i++){
			int x=s[i]-48;
			res=res*10+x;
		}
		return res;
	}
} 
void solve(string s){
	stringstream ss(s);
	string tmp;
	vector<string> v;
	while(ss>>tmp){
		v.push_back(tmp);
	}
	if(check(v[0])){
		stack<string> st;
		for(int i=v.size()-1;i>=0;i--){
			if(!check(v[i])) st.push(v[i]);
			else{
				string x=st.top();
				st.pop();
				string y=st.top();
				st.pop();
				if(v[i]=="+"){
					long long ans=resu(y)+resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="*"){
					long long ans=resu(y)*resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="/"){
					long long ans=resu(x)/resu(y);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="-"){
					long long ans=resu(x)-resu(y);
					string tmp=to_string(ans);
					st.push(tmp);
				}
			}
		}
		cout<<st.top()<<endl;
	}
	else{
		stack<string> st;
		for(int i=0;i<v.size();i++){
			if(!check(v[i])) st.push(v[i]);
			else{
				string x=st.top();
				st.pop();
				string y=st.top();
				st.pop();
				if(v[i]=="+"){
					long long ans=resu(y)+resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="*"){
					long long ans=resu(y)*resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="/"){
					long long ans=resu(y)/resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
				if(v[i]=="-"){
					long long ans=resu(y)-resu(x);
					string tmp=to_string(ans);
					st.push(tmp);
				}
			}
		}
		cout<<st.top()<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin.ignore();
		string s;
		getline(cin,s);
		solve(s);
	}
	return 0;
}