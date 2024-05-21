#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int r=s.size()-1;
		while(r>=0&&s[r]!='0'){
			r--;
		}
		if(r>=0){
			s[r]='1';
			for(int i=r+1;i<s.size();i++){
				int tmp=s[i]-48;
				int x=1-tmp;
				s[i]=x+48;
			}
			cout<<s;
		}
		else{
			for(int i=0;i<s.size();i++) cout<<'0';
		}
		cout<<endl;
	}
}