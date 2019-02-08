#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	if(n >= m){
		while(m){
			cout<<"BG";
			n--;m--;
		}
		while(n){
			cout<<"B";
			n--;
		}
	}
	else{
		while(n){
			cout<<"GB";
			n--;m--;
		}
		while(m){
			cout<<"G";
			m--;
		}
	}
	cout<<endl;
	return 0;
}
