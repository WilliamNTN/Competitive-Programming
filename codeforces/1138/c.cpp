#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n,m;
int vals[maxN][maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
		for(int  j = 0; j < m; j++)
			cin>>vals[i][j];

	vector<int> lines[n];
	vector<int> cols[m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			lines[i].pb(vals[i][j]);
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cols[i].pb(vals[j][i]);
		}
	}

	for(int i = 0; i < n; i++)
		sort(lines[i].begin(),lines[i].end());

	for(int i = 0; i < m; i++)
		sort(cols[i].begin(),cols[i].end());


	for(int i = 0; i < n; i++){
		//line i
		for(int j = 1; j < lines[i].size(); j++){
			if(lines[i][j] == lines[i][j-1]){
				lines[i].erase(lines[i].begin()+j);
				j--;
			}
		}
	}

	for(int i = 0; i < m; i++){
		//col i
		for(int j = 1; j < cols[i].size(); j++){
			if(cols[i][j] == cols[i][j-1]){
				cols[i].erase(cols[i].begin() + j);
				j--;
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < lines[i].size(); j++)
	// 		cout<<lines[i][j]<<" ";
	// 	cout<<endl;
	// }

	// for(int i = 0; i < m; i++){
	// 	for(int j = 0; j < cols[i].size(); j++){
	// 		cout<<cols[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	 // HERE WE GO

	int ans[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int thisVal = vals[i][j];
			int linePos = lower_bound(lines[i].begin(),lines[i].end(),thisVal) - lines[i].begin();
			int colPos = lower_bound(cols[j].begin(),cols[j].end(),thisVal) - cols[j].begin();
			//cout<<"ThisVal: "<<thisVal<<" Line pos: "<<linePos<<" colPos: "<<colPos<<endl;
			int thisPos = max(linePos,colPos);
			int maxLine = (thisPos+1) + (lines[i].size()-(linePos+1));
			int maxCol = (thisPos+1)+(cols[j].size()-(colPos+1));
			//cout<<"MaxLine: "<<maxLine<<" maxCol "<<maxCol<<endl;
			ans[i][j] = max(maxLine,maxCol);
		}
	}

	//cout<<endl<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}


	return 0;
}
