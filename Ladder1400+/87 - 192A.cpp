
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 45000;

LL n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>n;
	bool ans = false;


	set<LL> triangulars;
	for(int i = 1; i <=maxN;i++){
		triangulars.insert(i*(i+1)/2);
	}

	set<LL>::iterator it;
	for(it = triangulars.begin(); it != triangulars.end(); it++){
		if(*it > n) break;
		if(triangulars.find(n-*it) != triangulars.end()){
			ans = true;
			break;
		}
	}
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
