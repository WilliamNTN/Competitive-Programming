#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1012345;
int t;
int n;
int vals[maxN];
map<int,int> hashMap;
vector<int> ok;

double getValue(int a, int b){
	return ((4*a)/(1.0*b)) + ((4*b)/(1.0*a));
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	while(t--){
		cin>>n;
		hashMap.clear();
		ok.clear();
		for(int i = 0; i < n; i++){
			cin>>vals[i];
			hashMap[vals[i]]++;
			if(hashMap[vals[i]] == 2){
				hashMap[vals[i]] = 0;
				ok.pb(vals[i]);
			}
		}
		
		sort(ok.begin(),ok.end());
		int ans = 0;
		double value = getValue(ok[0],ok[1]);
		for(int i = 1; i < (ok.size()-1); i++){
			double thisV = getValue(ok[i],ok[i+1]);
			if(thisV < value){
				value = thisV;
				ans = i;
			}
		}

		cout<<ok[ans]<<" "<<ok[ans]<<" "<<ok[ans+1]<<" "<<ok[ans+1]<<endl;
	}
	return 0;	
}
