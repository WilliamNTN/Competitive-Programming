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
LL vals[maxN];


bool test(LL middle){
	LL total = 0;
	LL index = n-1;
	LL count = 0;
	LL k = 0;
	while(index >= 0){
		total += vals[index--] - k;
		if(total >= m) break;
		count++;
		if(count == middle){
			count = 0;
			k++;
		}
	}
	return total >= m;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(LL i = 0;i < n; i++){
		cin>>vals[i];
	}

	sort(vals,vals+n);
	LL ans = -1, l = 1, r = m;
	while(l <= r){
		LL middle = l+(r-l)/2;
		if(test(middle)){
			ans = middle;
			r = middle-1;
		}else{
			l = middle+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
