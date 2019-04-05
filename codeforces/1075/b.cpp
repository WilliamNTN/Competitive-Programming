#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n,m;
LL position[maxN];
LL isTaxi[maxN];
LL near[maxN];
map<LL,LL> taxiPosition;
map<LL,LL> ans;
LL taxi;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i = 0; i < (n+m); i++){
		cin>>position[i];
	}
	taxi = 0;
	for(LL i = 0; i < (n+m); i++){
		cin>>isTaxi[i];
		if(isTaxi[i] == 1){
			taxiPosition[taxi] = position[i];
			taxi++;
		}
	}

	memset(near,-1,sizeof(near));
	taxi = -1;
	for(LL i = 0; i < (n+m); i++){
		if(isTaxi[i] == 1)
			taxi++;
		else
			near[i] = taxi;
	}

	taxi = m;
	for(LL i = (n+m-1); i>=0; i--){
		if(isTaxi[i] == 1)
			taxi--;
		else{
			if(taxi == m) continue;
			if(near[i] == -1)
				near[i] = taxi;
			else{
				LL distBefore = abs(position[i] - taxiPosition[near[i]]);
				LL distNow = abs(position[i] - taxiPosition[taxi]);
				if(distNow < distBefore)
					near[i] = taxi;
			}
		}
	}
	for(LL i = 0; i < (n+m); i++){
		if(isTaxi[i] == 1) continue;
		ans[near[i]]++;
	}
	for(LL i = 0; i < m; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
