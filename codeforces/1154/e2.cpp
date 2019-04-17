#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n,k;
LL vals[maxN];
LL ptNext[maxN],ptBefore[maxN];
pii ord[maxN];
LL team[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		ord[i] = mp(vals[i],i);
	}

	sort(ord,ord+n);
	ptNext[n-1] = -1;
	for(int i = 0; i < (n-1); i++)
		ptNext[i] = i+1;

	ptBefore[0] = -1;
	for(int i = 1; i < n; i++)
		ptBefore[i] = i-1;

	memset(team,0,sizeof(team));
	int pt0 = n-1;
	int curTeam = 1;
	int index;
	while(pt0 >= 0){
		if(team[ord[pt0].ss] != 0){
			pt0--;
			continue;
		}
		index = ord[pt0].ss;
		team[index] = curTeam;
		int count = 0;
		int l = ptBefore[index];
		while(l != -1 && count < k){
			if(team[l] == 0){
				team[l] = curTeam;
				count++;
			}
			l = ptBefore[l];
		}

		count = 0;
		int r = ptNext[index];

		while(r != -1 && count < k){
			if(team[r] == 0){
				team[r] = curTeam;
				count++;
			}
			r = ptNext[r];
		}

		if(r != -1 || l != -1){
			if(r != -1) ptBefore[r] = l;
			if(l != -1) ptNext[l] = r;
		}
		curTeam = (curTeam%2)+1;
	}
	for(int i = 0; i < n; i++)
		cout<<team[i];
	cout<<endl;
	return 0;
}
