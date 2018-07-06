#include <bits/stdc++.h>
using namespace std;

#define LL long long int
LL n;

vector<pair<LL,LL> > frags;


bool compare(const pair<int,int> &a, const pair<int,int> &b){
	return (a.first < b.first);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	for(LL i=0;i<n;i++){
		LL a;
		cin>>a;
		frags.push_back(make_pair(a,i));
	}

	sort(frags.begin(),frags.end(),compare);

	LL total = 0;
	for(LL i=0;i<(n-1);i++)
		total += abs(frags[i].second - frags[i+1].second);

	cout<<total<<endl;
	return 0;
	
}
