
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 5050;

set<int> used[maxN];
int n;
int vals[maxN];
int colors[maxN];
int k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>k;

	for(int i = 0; i < n; i++)
		cin>>vals[i];

	int color = 0;
	bool impossible = false;
	
	for(int i = 0; i < n; i++){

		int t = 0;
		while(used[vals[i]].find(color) != used[vals[i]].end() && t < k){
			color = (color+1)%k;
			t++;
		}
		if(t >= k){
			impossible = true;
			break;
		}
		colors[i] = color;
		used[vals[i]].insert(color);
		color = (color+1)%k;
	}

	if(impossible)
		cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		for(int i = 0; i < n; i++)
			cout<<colors[i]+1<<" ";
	cout<<endl;
	}
	return 0;
}
