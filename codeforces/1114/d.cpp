
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 5050;

int n;
int vals[maxN];
vector<int> components;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	components.pb(vals[0]);
	for(int i = 1; i < n; i++)
		if(vals[i] != vals[i-1])
			components.pb(vals[i]);


	int ans = components.size()-1;
	for(int i = 0; i < components.size(); i++){
		int a = i-1;
		int pt1 = i+1;
		while(a >= 0){
			int count = 0;
			int pt0 = a;
			while(pt1 < components.size()){
				if(components[pt1] == components[pt0]){
					count++;
					pt0--;
					if(pt0 < 0) break;
				}
				pt1++;
			}

			ans = min(ans,(int)components.size()-1-count);
			a--;
			pt1 = i+1;
		}
	}


	cout<<ans<<endl;
	return 0;
}
