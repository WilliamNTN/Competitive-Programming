
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;
int n,x;
int vals[maxN];
set<int> xPositions;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x;
	vals[0] = -10000100;
	bool present = false;
	for(int i = 1; i <=n; i++){
		cin>>vals[i];
		if(vals[i] == x) present = true;
	}
	int ans = 0;

	if(!present){
		n++;
		vals[n] = x;
		ans++;
	}

	sort(vals,vals+(n+1));

	int firstPosition = -1, lastPosition = 0;
	for(int i = 1; i <=n; i++){
		if(vals[i] == x && firstPosition == -1)
			firstPosition = i;
		if(vals[i] == x)
			lastPosition = i;
	}


	int median = (n+1)/2;
	int medianb = median;
	int first = 1;
	int last = n;

	while((median < firstPosition || median > lastPosition) && (medianb < firstPosition || medianb > lastPosition)){
		first--;
		last++;

		median = (n - first + 2)/2;
		median = first + median-1;

		medianb = (last+1)/2;
		ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
