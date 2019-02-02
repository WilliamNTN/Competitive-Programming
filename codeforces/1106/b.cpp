
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL n,m;
LL remain[maxN];
LL cost[maxN];
LL t,d;

struct compare{
	bool operator()(const pair<LL,LL>&a, const pair<LL,LL>&b){
		if(a.ff != b.ff)
			return a.ff > b.ff;
		else
			return a.ss > b.ss;
	}
};

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i = 0; i < n; i++)
		cin>>remain[i];
	for(LL i = 0; i < n; i++)
		cin>>cost[i];

	priority_queue<pair<LL,LL>,vector<pair<LL,LL>>, compare> pq;

	for(LL i = 0; i < n; i++){
		pq.push(make_pair(cost[i],i));
	}

	for(LL i = 0; i < m; i++){
		LL thisCost = 0;
		cin>>t>>d;
		t--;
		while(d){
			if(remain[t] > 0){
				int toRemove = min(remain[t],d);
				remain[t] -= toRemove;
				thisCost += cost[t]*toRemove;
				d -= toRemove;
			}else{
				if(pq.size()){
					pair<LL,LL> rPair = pq.top(); pq.pop();
					LL dish = rPair.ss;
					while(pq.size() && remain[dish] == 0){
						rPair = pq.top(); pq.pop();
						dish = rPair.ss;
					}
					if(remain[dish] > 0){
						int toRemove = min(remain[dish],d);
						remain[dish] -= toRemove;
						thisCost += cost[dish]*toRemove;
						d -= toRemove;
						if(remain[dish] > 0){
							pq.push(rPair);
						}
					}
					else{
						thisCost = 0; d= 0;
					}
				}
				else{
					thisCost = 0;
					d = 0;
				}
			}
		}

		cout<<thisCost<<endl;
	}
	return 0;
}
