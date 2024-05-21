#include<bits/stdc++.h>
using namespace std;
string solve(string s1){
	stack<char> st;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='('){
			if(s1[i-1]=='-'||s1[i-1]=='+') st.push(s1[i-1]);
		}
		if(st.size()&&st.top()=='-'){
			if(s1[i]=='+') s1[i]='-';
			else if(s1[i]=='-') s1[i]='+';
		}
		if(s1[i]==')'&&st.size()) st.pop();
	
	}
	string res="";
	for(int i=0;i<s1.size();i++){
		if(s1[i]!='('&&s1[i]!=')') res+=s1[i];
	}
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		if(solve(s1)==solve(s2)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}