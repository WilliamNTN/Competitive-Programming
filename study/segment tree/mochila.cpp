#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;

int vals[maxN];
int cost[maxN];
int total;
int w,n;



int knapsack01(int pos,int w){
	if(w == 0) return 0;
	if(pos > n) return 0;

	int ans = 0;
	total++;
	ans = max(ans,knapsack01(pos+1,w));
	if(cost[pos] <= w)
		ans = max(ans,knapsack01(pos+1,w-cost[pos])+vals[pos]);

	return ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>w;
	for(int i=1; i<=n; i++){
		int a,b;
		cin>>a>>b;
		vals[i] = a;
		cost[i] = b;
	}
	total = 0;
	cout<<knapsack01(1,w)<<endl;
	cout<<"OP: "<<total<<endl;
	return 0;
}
