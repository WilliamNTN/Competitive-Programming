
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;

LL n;
string s;
LL cost[maxN];
LL isImportant[maxN];



void populate(char curr, LL position){
	string q = "hard";
	q.erase(q.find(curr),1);

	LL foundAfter = 0;
	LL needsAfter = 3 - position;
	set<LL> after;

	for(LL i = n-1; i >= 0; i--){
		if(s[i] == q[0] && after.find(q[0]) == after.end())
			foundAfter++;
		if(s[i] == q[1] && after.find(q[1]) == after.end())
			foundAfter++;
		if(s[i] == q[2] && after.find(q[2]) == after.end())
			foundAfter++;
		if(s[i] == curr){
			if(foundAfter >= needsAfter) isImportant[i]++;
		}
		after.insert(s[i]);
	}


	LL foundBefore = 0;
	LL needsBefore = position;
	set<LL> before;

	for(LL i = 0; i < n; i++){
		if(s[i] == q[0] && before.find(q[0]) == before.end())
			foundBefore++;
		if(s[i] == q[1] && before.find(q[1]) == before.end())
			foundBefore++;
		if(s[i] == q[2] && before.find(q[2]) == before.end())
			foundBefore++;

		if(s[i] == curr){
			if(foundBefore >= needsBefore) isImportant[i]++;
		}
		before.insert(s[i]);
	}


}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	for(LL i = 0; i < n; i++)
		cin>>cost[i];

	memset(isImportant,0,sizeof(isImportant));

	populate('h',0);
	populate('a',1);
	populate('r',2);
	populate('d',3);
	
	string hard = "hard";
	LL ans = LONG_MAX;
	for(LL i = 0; i < 4; i++){
		LL currAns = 0;
		for(LL j = 0; j < n; j++){
			if(s[j] != hard[i]) continue;
			if(isImportant[j] >= 2){
				currAns += cost[j];
			}
		}

		ans = min(currAns,ans);
	}

	cout<<ans<<endl;

	return 0;
}
