#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define trip pair<pair<int,int> ,int >
#define ff first
#define ss second


trip make_trip(int a, int b, int c){
	return make_pair(make_pair(a,b),c);
}

vector<trip> t;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		int s; cin>>s;
		int sum = 0;
		int vals[s+1];
		for(int j=1;j<=s; j++){
			cin>>vals[j];
			sum += vals[j];
		}
		for(int j = 1; j<=s; j++){
			t.push_back(make_trip(sum-vals[j],i,j));
		}
	}

	sort(t.begin(),t.end());
	
	for(int i = 1; i<t.size(); i++){
		if( (t[i].ff.ff == t[i+1].ff.ff) && (t[i].ff.ss != t[i+1].ff.ss) ){
			cout<<"YES"<<endl;
			cout<<t[i].ff.ss<<" "<<t[i].ss<<endl;
			cout<<t[i+1].ff.ss<<" "<<t[i+1].ss<<endl;
			return 0;
		}
		// else{
		// 	cout<<t[i].ff.ff<<"dif from "<<t[i+1].ff.ff<<" or "<<t[i].ff.ss <<" dif from "<<t[i+1].ff.ss<<endl;
		// }
	}
	cout<<"NO"<<endl;
	return 0;
}
