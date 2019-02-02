
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 550;
int n;
char mat[maxN][maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>mat[i][j];

	int ans = 0;

	for(int i = 1; i < n-1; i++){
		for(int j = 1; j < n-1; j++){
			if(mat[i][j] != 'X') continue;
			int isGood = true;
			for(int a = -1; a <= 1; a +=2){
				for(int b = -1; b <= 1; b+=2){
					int ni = i+a;
					int nj = j+b;
					if(mat[ni][nj] != 'X') isGood = false;
				}
			}

			if(isGood) ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}
