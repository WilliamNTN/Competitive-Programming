#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n;
int vals[maxN];


int calculateCost(int target){
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(vals[i] == target) continue;

		int one = abs(vals[i] - (target+1));
		int two = abs(vals[i] - (target-1));
		ans += min(one,two);
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int maxValue = -1, minValue = INT_MAX;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}
	
	int finalT;
	int finalCost = INT_MAX;

	for(int target = 1; target <= 100; target++){
		int cost = calculateCost(target);
		if(cost < finalCost){
			finalCost = cost;
			finalT = target;
		}
	}

	cout<<finalT<<" "<<finalCost<<endl;
	return 0;
}
