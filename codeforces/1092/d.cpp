#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL vals[maxN];
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		vals[i] = vals[i]%2;
	}
	vector<int> vec;
	for(int i = 0; i < n; i++){
		if(vec.size() && vals[i] == vec[vec.size()-1]){
			vec.pop_back();
		}
		else
			vec.pb(vals[i]);
	}
	if(vec.size() <= 1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
