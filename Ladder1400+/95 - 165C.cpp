#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<LL,LL>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const LL maxN = 1012345;
LL n,k; string s;
LL acc[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>k>>s;
	LL n = s.size();

	acc[0] = s[0]=='1'?1:0;
	for(LL i = 1; i<n; i++){
		acc[i] = acc[i-1] + (s[i]=='1'?1:0);
	}

	LL final = 0;

	for(LL i = 0; i<n; i++){

		if(k == 0 && s[i] == '1') continue;
		LL search = (acc[i]+k-1);
		if(s[i] == '0') search++;
		if(search < acc[i]) search = acc[i];

		LL pos1 = -1;
		LL l = i,r=n-1;

		while(l<=r){
			LL m = (l+r)/2;
			if(acc[m] >= search){
				pos1 = m;
				r = m-1;
			}
			else
				l = m+1;
		}

		LL pos2 = -1;
		l=i; r=n-1;

		while(l<=r){
			LL m = (l+r)/2;
			if(acc[m] <= search){
				pos2 = m;
				l = m+1;
			}
			else
				r = m-1;
		}

		if(pos1 != -1 && acc[pos1] == search) final++;
		if(pos2 != -2 && acc[pos2] == search){
			final += pos2-pos1;
		}
	}

	cout<<final<<endl;


	return 0;
}
