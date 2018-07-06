#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
string s[110];

bool sortBySize(const string a, const string b){
	return a.size() < b.size();
}

bool in(string a, string b){
	if(a.size() < b.size()) return false;

	int lastAns = 0;
	for(int i = 0; i < a.size() - b.size() + 1; i++){
		int ans = 1;
		for(int j = 0; j<	b.size(); j++){
			if(a[i+j] != b[j]) ans = 0;
		}
		if(ans) lastAns = 1;
	}	

	if(lastAns) return true;
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>s[i];

	sort(s,s+n,sortBySize);
	for(int i=0; i<n; i++){
		for(int j = i+1; j < n-1-i; j++){
			if(in(s[i],s[j])) 	// se s[j] está dentro de s[i]
				swap(s[i],s[j]);
		}
	}
	int ans = 1;
	for(int i=0; i<n-1; i++){
		if(!in(s[i+1],s[i]))
			ans = 0;
	}

	if(ans){
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++)
			cout<<s[i]<<endl;
	}
	else
		cout<<"NO"<<endl;

	return 0;
}
	