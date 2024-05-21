#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin>>n;
	stack<char> st;
	stack<char> st1;
	for(int i=0;i<n.size();i++){
		if(n[i]=='<'){
			if(!st.empty()){
				st1.push(st.top());
				st.pop();
			}
		}
		else if(n[i]=='>'){
			if(!st1.empty()){
				st.push(st1.top());
				st1.pop();
			}
		}
		else if(n[i]=='-'){
			if(!st.empty()) st.pop();
		}
		else st.push(n[i]);
	}
	while(!st.empty()){
		st1.push(st.top());
		st.pop();
	}
	while(!st1.empty()){
		cout<<st1.top();
		st1.pop();
	}
	return 0;
}