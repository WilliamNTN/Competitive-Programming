#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n,k;
int vals[101234];
int cnt[101234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	int total = 0;
	for(int i=1; i<=n; i++){
		cin>>vals[i];
		cnt[vals[i]]++;
		if(cnt[vals[i]] == 1)
			total++;
	}

	if(total < k){
		cout<<"-1 -1"<<endl;
		return 0;
	}

	int p1 = 1, p2 = n;
	
	while(total > k || (total >=k && cnt[vals[p2]] > 1)){
		while(cnt[vals[p2]] > 1){
			cnt[vals[p2]]--; p2--;
		}
		if(total > k){
			cnt[vals[p2]]--;
			total--;
			p2--;
		}
	}

	while(total > k || (total >=k && cnt[vals[p1]] > 1)){
		while(cnt[vals[p1]] > 1){
			cnt[vals[p1]]--; p1++;
		}
		if(total > k){
			cnt[vals[p1]]--;
			total--;
			p1++;
		}
	}

	cout<<p1<<" "<<p2<<endl;
	return 0;
}
