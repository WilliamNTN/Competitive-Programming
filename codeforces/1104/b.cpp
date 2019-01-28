
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

int getNPairs(string s, int n){

	int ans = 0;
	stack<char> st;

	for(int i = 0; i < n; i++){
		if(st.size() && s[i] == st.top()){
			ans++;
			st.pop();
		}
		else
			st.push(s[i]);
	}

	return ans;

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s;
	cin>>s;

	if(getNPairs(s,s.size())%2 == 0){
		cout<<"No"<<endl;
	}
	else
		cout<<"Yes"<<endl;
	return 0;
}
