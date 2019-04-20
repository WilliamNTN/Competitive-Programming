#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>s;
	vector<char> v;
	int k = -1;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'a'){
			k = i; continue;
		}
		v.pb(s[i]);
	}

	if(v.size()%2 != 0){
		cout<<":("<<endl;
		return 0;
	}
	bool ans = true;
	int i = 0, j = v.size()/2;
	while(j < v.size()){
		if(v[i] != v[j]){
			ans = false;
		}
		i++; j++;
	}

	if(ans){

		int count = 0;
		for(int i = 0; i < k; i++){
			if(s[i] != 'a') count++;
		}
		if(count <= v.size()/2){
			cout<<s.substr(0,k+1+(v.size()/2-count))<<endl;
		}else{
			cout<<":("<<endl;
		}
	}else{
		cout<<":("<<endl;
	}
	return 0;
}
