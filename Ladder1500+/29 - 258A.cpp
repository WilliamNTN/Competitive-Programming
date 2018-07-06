#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;

	int done = 0, one = 0;

	for(LL i=0;i<s.size();i++){
		if(s[i]=='1'){
			if(!done && (i != (s.size()-1))){
				one = 1;
				cout<<'1';
			} 
			else if(!done && (i == (s.size()-1))){}
			else
				cout<<'1';
		}
		else{
			if(!done && one){
				done = 1;
			}	
			else if(done || !one){
				cout<<'0';
			}
		}
	}

	cout<<endl;
	return 0;
}
