
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201;
string s;
int k;
int n;

string dpS[maxN][maxN];
int dp[maxN][maxN];
string build(int position, string soFar){
	if(position >= n){
		if(soFar.size() == k) return soFar;
		return "Impossible";
	}

	if(soFar.size() > k) return "Impossible";

	if(dp[position][soFar.size()] != -1)
		return dpS[position][soFar.size()];

	dp[position][soFar.size()] = 1;

	if(position+1 < n && s[position+1] == '?'){
		string a = build(position+2,soFar);
		soFar += s[position];
		string b = build(position+2,soFar);

		if(a == "Impossible"){
			return dpS[position][soFar.size()-1] = b;
		}
		return dpS[position][soFar.size()-1] = a;
	}
	if(position+1 < n && s[position+1] == '*'){
		string a = build(position+2,soFar);
		soFar += s[position];
		string b = build(position,soFar);

		if(a == "Impossible"){
			return dpS[position][soFar.size()-1] = b;
			return b;
		}
		return dpS[position][soFar.size()-1] = a;
	}
	else{
		soFar += s[position];
		return dpS[position][soFar.size()-1] = build(position+1,soFar);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s>>k;
	memset(dp,-1,sizeof(dp));
	n = s.size();
	cout<<build(0,"")<<endl;
	return 0;
}
