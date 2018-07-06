#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define pair pair<LL,LL>
#define fi first
#define se second


LL n;
LL tipos[301234];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	pair segments[301234];
	LL nSegments = 0;

	cin>>n;
	for(LL i=0; i<n; i++)
		cin>>tipos[i];

	LL left = 0;
	set<int> inSegment;
	inSegment.insert(tipos[0]);

	for(LL i=1;i<n;i++){
		if(inSegment.count(tipos[i])){
			segments[nSegments++] = make_pair(left+1,i+1);
			left = i+1;
			i++;
			inSegment.clear();
			inSegment.insert(tipos[left]);
		}
		else
			inSegment.insert(tipos[i]);
	}

	if(nSegments == 0){
		cout<<-1<<endl;
		return 0;
	}
		
	
	if(segments[nSegments-1].se != n)
		segments[nSegments-1].se = n;

	cout<<nSegments<<endl;

	for(LL i=0;i<nSegments;i++)
		cout<<segments[i].fi<<" "<<segments[i].se<<endl;
	return 0;
}
