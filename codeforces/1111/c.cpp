
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

LL n,k,a,b;
vector<LL> positions;


LL binarySearch(LL left, LL right){

	LL leftPosition = lower_bound(positions.begin(),positions.end(),left) - positions.begin();
	while(leftPosition >= 0 && positions[leftPosition] >= left) leftPosition--;

	LL rightPosition = upper_bound(positions.begin(),positions.end(),right) - positions.begin();
	if(rightPosition == k || positions[rightPosition] > right) rightPosition--;

	return rightPosition - leftPosition > 0 ? rightPosition - leftPosition : 0;
}
LL destroy(LL left, LL right){


	LL avengers = binarySearch(left,right);
	if(avengers == 0) return a;
	if(left == right){ // len == 1
		if(avengers == 0) return a;
		return b * avengers;
	}

	LL middle = left + ((right-left)/2);
	LL divideValue = destroy(left,middle) + destroy(middle+1,right);
	LL thisLen = right-left+1;
	LL burnValue = b * avengers * thisLen;


	return min(burnValue,divideValue);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k>>a>>b;
	LL len = pow(2,n);

	for(LL i = 0; i < k; i++){
		LL pos; cin>>pos;
		positions.pb(pos);
	}

	sort(positions.begin(),positions.end());

	cout<<destroy(1,len)<<endl;
	return 0;
}
