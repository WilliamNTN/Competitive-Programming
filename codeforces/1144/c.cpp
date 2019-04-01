#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n;
int vals[maxN];
map<int,int> hashMap;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}

	vector<int>a,b;
	bool flag = true;
	for(int i = 0; i < n; i++){
		if(hashMap[vals[i]] == 0){
			a.pb(vals[i]);
			hashMap[vals[i]] = 1;
		}else if(hashMap[vals[i]] == 1){
			b.pb(vals[i]);
			hashMap[vals[i]] = 2;
		}else
			flag = false;
	}

	if(!flag){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		cout<<a.size()<<endl;
		for(int i = 0; i < a.size(); i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		cout<<b.size()<<endl;
		for(int i = b.size()-1; i>= 0; i--)
			cout<<b[i]<<" ";
		cout<<endl;
	}
	return 0;
}
