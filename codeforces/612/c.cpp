#include <bits/stdc++.h>
using namespace std;


vector<char> stackC;
string s;

int type(char c){
	if(c == '{' || c == '}')
		return 1;
	if(c == '(' || c == ')')
		return 2;
	if(c == '<' || c == '>')
		return 3;
	return 4;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int count = 0;

	for(int i=0; i<s.size();i++){
		if(s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '(')
			stackC.push_back(s[i]);
		else{
			if(stackC.size() == 0){
				cout<<"Impossible"<<endl;
				return 0;
			}
			if(type(stackC.back()) != type(s[i])){
				count++;
			}
			stackC.pop_back();
		}
	}

	if(stackC.size()!=0)
		cout<<"Impossible"<<endl;
	else
		cout<<count<<endl;
	return 0;
}
