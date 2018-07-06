#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string s;
int print[220];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int first = 0;
	for(int i =0; i<s.size(); i++){
		if(s[i] == 'W' && s[i+1] == 'U' && s[i+2]=='B'){
			if(first)
				print[i] = 2;
			else
				print[i] = 1;
			print[i+1] = 1; print[i+2] = 1;
			i = i+2;
		}
		else{
			print[i] = 0;
			first = 1;
		}
	}
	int space = 0;
	for(int i = 0; i<s.size(); i++){
		if(print[i] == 0){
			cout<<s[i];
			space = 0;
		}
		else if(print[i] == 2 && !space){
			cout<<" ";
			space = 1;
		}
	}
	cout<<endl;
	return 0;
}
