#include <bits/stdc++.h>
using namespace std;

string s;

set<char> used;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;
	int count = 0;
	for(int i=0;i<s.size();i++){
		if(used.count(s[i]) == 0){
			count++;
			used.insert(s[i]);
		}
	}

	if(count % 2 != 0){
		cout<<"IGNORE HIM!"<<endl;
	}
	else{
		cout<<"CHAT WITH HER!"<<endl;
	}
	return 0;
}
