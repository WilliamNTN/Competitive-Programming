#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 220;
int n;
string s[maxN];
map<int,vector<string>> hashMap;

vector<char> solve(string total1){
	vector<char> ans;
	map<string,vector<char>> hashAns;
	// cout<<"Start: "<<total1<<endl;
	for(int i = 1; i <= (n-1); i++){
		string a = hashMap[i][0];
		string b = hashMap[i][1];

		string pr = total1.substr(0,i);
		string su = total1.substr(n-i);
		// cout<<"I: "<<i<<endl;
		// cout<<"A: "<<a<<" B: "<<b<<endl;
		// cout<<"PRE: "<<pr<<" SUF: "<<su<<endl;
		if(a == pr && b == su){
			hashAns[a].pb('P');
			hashAns[b].pb('S');
		}else if(b == pr && a == su){
			hashAns[a].pb('S');
			hashAns[b].pb('P');
		}else{
			return ans;
		}
	}

	for(int i = 0; i < (2*n-2); i++){
		ans.pb(hashAns[s[i]][0]);
		hashAns[s[i]].erase(hashAns[s[i]].begin());
	}

	return ans;
}
bool test(string a){
	for(int i = 1; i <= n-1; i++){
		string f = hashMap[i][0];
		string s = hashMap[i][1];

		string pre = a.substr(0,i);
		string suf = a.substr(n-i);

		if(f == pre && s == suf || f == suf || s == pre){

		}else{
			return false;
		}
	}
	return true;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < (2*n - 2); i++){
		cin>>s[i];
		hashMap[s[i].size()].pb(s[i]);
	}
	string total1 = hashMap[n-1][0] + hashMap[n-1][1][n-2]; 
	string total2 = hashMap[n-1][1] + hashMap[n-1][0][n-2];
 	
 	vector<char> first = solve(total1);
 	vector<char> second = solve(total2);
 	if(first.size()){
 		for(int i = 0; i < first.size(); i++)
 			cout<<first[i];
 	}else{
 		for(int i = 0; i < second.size(); i++)
 			cout<<second[i];
 	}
 	cout<<endl;
	return 0;
}
