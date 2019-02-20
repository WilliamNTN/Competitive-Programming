#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
LL n;
LL vals[maxN];
LL xors[maxN];
map<LL,pair<LL,LL>> presents;
vector<LL> uniques;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	vals[0] = 0;
	xors[0] = 0;
	for(int i = 1; i <=n; i++){
		cin>>vals[i];
		xors[i] = vals[i];
		xors[i] = xors[i]^xors[i-1];
	}


	uniques.pb(0);
	presents[0] = mp(0,0);
	presents[0].first++; // first = even, second == odd;

	for(int i = 1; i <= n; i++){
		if(presents.find(xors[i]) == presents.end()){
			presents[xors[i]] = mp(0,0);
			uniques.pb(xors[i]);
		}
		if(i%2 == 0){ // even
			presents[xors[i]].first++;
		}
		else{
			presents[xors[i]].second++;
		}
	}
	LL ans = 0;
	for(int i = 0; i < uniques.size(); i++){
		pair<LL,LL> p = presents[uniques[i]];
		LL even = p.first;
		LL odd = p.second;
		ans += even*(even-1)/2;
		ans += odd*(odd-1)/2;
	}

	cout<<ans<<endl;
	/*for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j+=2){
			int mid = j-i+1;
			LL firstXor  = xors[j] ^ xors[mid];
			LL secondXor = xors[mid] ^ xors[i-1];
			if(firstXor == secondXor){
				ans++;
			}
		}
	}*/
}
