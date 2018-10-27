
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int t,n,v1,h1,a,b,c,d,e,f,m;




bool isInside(pii one, pii two, pii p){
	
	int maxX = max(one.ff,two.ff);
	int minX = min(one.ff,two.ff);
	int maxY = max(one.ss,two.ss);
	int minY = min(one.ss,two.ss);
	if(p.ff < maxX && p.ff > minX && p.ss < maxY && p.ss > minY) return true;
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	int count = 1;

	while(t--){
		cin>>n>>v1>>h1>>a>>b>>c>>d>>e>>f>>m;
		vector<pii> cafes;
		cafes.pb(mp(v1,h1));
		for(int i = 1; i < n; i++){
			int lastv = cafes[i-1].ff;
			int lasth = cafes[i-1].ss;

			int thisv = ((a*lastv)%m + (b*lasth)%m + c)%m;
			int thish = ((d*lastv)%m + (e*lasth)%m + f)%m;

			cafes.pb(mp(thisv,thish));
		}
		LL ans = 0;

		for(int i = 0; i < cafes.size()-2; i++){
			for(int j = i+1; j < cafes.size()-1; j++){
				for(int k = j+1; k < cafes.size(); k++){
					if(isInside(cafes[i],cafes[j],cafes[k])){
						continue;
					}
					if(isInside(cafes[i],cafes[k],cafes[j])){
				 		continue;
				 	}
					if(isInside(cafes[j],cafes[k],cafes[i])){
						continue;
					}
					ans++;	
				}
			}
		}

		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}
	return 0;
}
