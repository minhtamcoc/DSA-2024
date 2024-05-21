#include<bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool visited[100];
int res;
char s,t;
void ins(){
	for(int i=1;i<=n;i++){
		int x=res+a[i]-1;
		char tmp=x+48;
		cout<<tmp;
	}
	cout<<endl;
}
void Try(int i){
	for(int j=1;j<=n;j++){
		if(!visited[j]){
			visited[j]=true;
			a[i]=j;
			if(i==n) ins();
			else Try(i+1);
			visited[j]=false;
		}
	}
}
int main(){
	cin>>s>>t;
	int a=s-48;
	int b=t-48;
	if(a<b) swap(a,b);
	n=a-b+1;
	res=min(a,b);
	Try(1);
	return 0;
}