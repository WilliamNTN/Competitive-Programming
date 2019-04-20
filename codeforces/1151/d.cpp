#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n;
LL a[maxN],b[maxN];
vector<pair<LL,LL> > leftV,rightV,vec;


bool compare(pair<LL,LL> a, pair<LL,LL> b){
	LL one = a.ff + (2*a.ss) + (2*b.ff) + b.ss;
	LL two = b.ff + (2*b.ss) + (2*a.ff) + a.ss;

	return one < two;
}
bool compareLeft(pair<LL,LL> a, pair<LL,LL> b){

	if(a.ff == b.ff){
		return a.ss < b.ss;
	}
	return a.ff > b.ff;
}
bool compareRight(pair<LL,LL> a, pair<LL,LL>b){
	if(a.ff == b.ff){
		a.ss > b.ss;
	}
	return a.ff < b.ff;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
		vec.pb(mp(a[i],b[i]));
		if(a[i] >= b[i]){
			leftV.pb(mp(a[i],b[i]));
		}else
			rightV.pb(mp(b[i],a[i]));
	}

	sort(leftV.begin(),leftV.end(),compareLeft);

	sort(rightV.begin(),rightV.end(),compareRight);

	sort(vec.begin(),vec.end(),compare);

	LL total = 0;
	// for(int i = 0; i < leftV.size(); i++){
	// 	total += (leftV[i].ff * i);
	// 	total += (leftV[i].ss * (leftV.size()-i-1 + rightV.size()));
	// }
	// for(int i = 0; i < rightV.size(); i++){
	// 	total += (rightV[i].ss * (i + leftV.size()));
	// 	total += (rightV[i].ff * (rightV.size()-i-1));
	// }

	for(int i = 0; i < vec.size(); i++){
		total += (vec[i].ff*i) + (vec[i].ss * (vec.size()-i-1)); 
	}
	cout<<total<<endl;
	return 0;
}
