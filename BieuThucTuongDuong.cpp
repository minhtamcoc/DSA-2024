#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<char> st;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				if(s[i-1]=='+'||s[i-1]=='-') st.push(s[i-1]);
			}
				if(st.size()&&st.top()=='-'){
						if(s[i]=='+') s[i]='-';
						else if(s[i]=='-') s[i]='+';
				}
				if(s[i]==')'&&st.size()){
					st.pop();
				}
			}
			string res="";
			for(int i=0;i<s.size();i++){
				if(s[i]!='('&&s[i]!=')'){
					res+=s[i];
				}
			}
			cout<<res<<endl;
		}
		return 0;
	}
