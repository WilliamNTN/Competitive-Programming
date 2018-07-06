#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n;
set<string> used;

string getObj(string a){
	string s = "";
	set<char> used;
	for(int i = 0; i<a.size(); i++){
		if(used.count(a[i]) == 0)
			s = s+a[i];
		used.insert(a[i]);
	}

	return s;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int count = 0;
	cin>>n;

	for(int i = 0; i<n; i++){
		string a;
		cin>>a;
		string b = getObj(a);
		sort(b.begin(),b.end());
		if(used.count(b) == 0)
			count++;
		used.insert(b);
	}

	cout<<count<<endl;
	return 0;
}
