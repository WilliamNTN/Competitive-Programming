#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
map <pair<LL,LL>,LL> dp; // nDigitsBehind,MOD
int n,k;
LL vals[maxN];

int getDigit(LL val){
	int count = 1;
	int mult = 10;
	while(val%mult != val){
		count++;
		mult *= 10;
	}
	return count;
}

LL multiply10Modk(LL val, int t){
	LL ans = val%k;
	for(int i = 0; i < t; i++){
		ans = ((ans%k)*10)%k;
	}
	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	for(int i = 0; i < n; i++){
		LL val = vals[i];
		for(int j = 1; j <= 9; j++){
			LL mod = multiply10Modk(val,j);
			dp[mp(j,mod)]++;
		}
	}
	LL ans = 0;
	for(int i = 0; i < n; i++){
		LL val = vals[i];
		int thisMod = val%k;
		int targetMod = k - thisMod;
		if(targetMod == k) targetMod = 0;


		LL thisDigit = getDigit(val);
		ans += dp[mp(thisDigit,targetMod)];
		LL mod = multiply10Modk(val,thisDigit);
		if(mod == targetMod) ans--;
	}
	cout<<ans<<endl;
	return 0;
}
