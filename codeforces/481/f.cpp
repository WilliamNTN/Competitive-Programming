#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n,k;
LL ment[201234];
LL skills[201234];

vector<LL> graph[201234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	memset(ment,0,sizeof(ment));
	for(LL i=1; i<=n; i++){
		cin>>skills[i];

		for(LL j=1; j<i; j++){
			if(skills[i] > skills[j]){
				graph[i].push_back(j);
			}
			else if(skills[i] < skills[j]){
				graph[j].push_back(i);
			}
		}
	}

	for(LL i=0; i<k; i++){
		LL x,y;
		cin>>x>>y;
		if(skills[x] > skills[y]){
			graph[x].erase(remove(graph[x].begin(),graph[x].end(),y));
		}
		else if(skills[x] < skills[y])
			graph[y].erase(remove(graph[y].begin(),graph[y].end(),x));

	}

	for(LL i=1; i<=n; i++)
		cout<<graph[i].size()<<" ";
	cout<<endl;
	return 0;
}
