#include <bits/stdc++.h>
using namespace std;
#define LL long long int


string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int lower= 0, upper= 0;
	for(int i=0;i<s.size();i++){
		if( (s[i] >= 'a' && s[i] <='z' ))   
			lower++;
		else
			upper++;
	}

	if(lower >= upper){
		for(int i=0;i<s.size();i++)
			cout<<(char)tolower(s[i]);
		cout<<endl;
	}
	else{
		for(int i=0;i<s.size();i++)
			cout<<(char)toupper(s[i]);
		cout<<endl;
	}
	return 0;
}