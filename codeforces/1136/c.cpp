#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 505;
int n,m;
int a[maxN][maxN];
int b[maxN][maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>a[i][j];

	bool flag = true;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>b[i][j];


	int ans = true;
	for(int i = 0; i < m; i++){
		int startRow = 0;
		int startCol = i;
		map<int,int> values;
		bool flag = true;
		//cout<<"Starting at "<<startRow<<" "<<startCol<<endl;
		for(int r = startRow, c = startCol; c >= 0 && r < n; r++,c--){
			if(values.find(a[r][c]) == values.end())
				values[a[r][c]] = 1;
			else
				values[a[r][c]]++;
			//cout<<"Visit "<<r<<" "<<c<<endl;
		}

		for(int r = startRow, c = startCol; c >= 0 && r < n; r++,c--){
			if(values.find(b[r][c]) == values.end())
				flag = false;
			else{
				if(values[b[r][c]] == 0)
					flag = false;
				else
					values[b[r][c]]--;
			}
		}
		if(!flag) ans = false;
	}
	//cout<<"TRADE"<<endl;
	for(int i = 1; i < n; i++){
		int startRow = i;
		int startCol = m-1;
		map<int,int> values;
		bool flag = true;
		//cout<<"Starting at "<<startRow<<" "<<startCol<<endl;
		for(int r = startRow, c = startCol; r < n && c >= 0; r++,c--){
			if(values.find(a[r][c]) == values.end())
				values[a[r][c]] = 1;
			else
				values[a[r][c]]++;
			//cout<<"Visit "<<r<<" "<<c<<endl;
		}

		for(int r = startRow, c = startCol; r < n && c >= 0; r++,c--){
			if(values.find(b[r][c]) == values.end())
				flag = false;
			else{
				if(values[b[r][c]] == 0)
					flag = false;
				else
					values[b[r][c]]--;
			}
		}
		if(!flag) ans = false;
	}

	if(ans) cout<<"YES"<<endl;
	else 	cout<<"NO"<<endl;
	return 0;
}
