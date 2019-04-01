#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 255;
int t;
int r,c;
char vals[maxN][maxN];

int manhattan(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}

int calculate(vector<pii> positions){
	int residual[maxN][maxN];
	memset(residual,0x3f3f3f3f,sizeof(residual));
	int ans = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(vals[i][j] == '1')
				residual[i][j] = 0;
			else{
				for(int k = 0; k < positions.size(); k++){
					int x = positions[k].ff;
					int y = positions[k].ss;
					int dist = manhattan(x,y,i,j);
					residual[i][j] = min(residual[i][j],dist);
				}
			}
			ans = max(ans,residual[i][j]);
		}
	}
	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int count = 1; count <= t; count++){
		cin>>r>>c;
		vector<pii> positions;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				cin>>vals[i][j];
				if(vals[i][j] == '1'){
					positions.pb(mp(i,j));
				}
			}
		}
		if(positions.size() == (r*c)){
			cout<<"Case #"<<count<<": "<<0<<endl;
			continue;
		}
		int ans = 0x3f3f3f3f;

		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(vals[i][j] == '1') continue;
				positions.pb(mp(i,j));
				vals[i][j] = '1';
				ans = min(ans,calculate(positions));
				positions.pop_back();
				vals[i][j] = '0';
			}
		}

		cout<<"Case #"<<count<<": "<<ans<<endl;
	}
	return 0;
}
