#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 401234;

int n,k;
string s;
vector<int> unq;
vector<int> indexes[27];
set<char> done;
set<int> removal;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	cin>>s;

	for(int i = 0; i<n; i++){
		int val = s[i] - 'a';
		indexes[val].pb(i);

		if(done.count(s[i]) == 0)
			unq.pb(s[i]);
		done.insert(s[i]);
	}

	sort(unq.begin(),unq.end());

	for(int i = 0; i<unq.size(); i++){
		int thisIndex = unq[i] - 'a';

		for(int j = 0; j < indexes[thisIndex].size(); j++){
			if(k <= 0){
				i = unq.size() + 1;
				break;
			}
			else{
				removal.insert(indexes[thisIndex][j]);
				k--;
			}
		}
	}

	for(int i = 0; i<n; i++)
		if(removal.count(i) == 0)
			cout<<s[i];
	cout<<endl;
}
