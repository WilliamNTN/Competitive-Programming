
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n,r;
int input[maxN];
int cc[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>r;
	int total = 0;

	for(int i = 0; i < n; i++){
		cin>>input[i];
		total += input[i];
	}

	for(int i = 0; i < n; i++){
		if(input[i] == 0) continue;

		int downLimit = i-r+1;
		int upLimit = i+r-1;

		for(int j = max(downLimit,0); j <= min(n-1,upLimit); j++)
			cc[j]++;
	}

	int takata = 0;
	
	for(int i = 0; i < n; i++){
		if(cc[i] <= 0){
			cout<<-1<<endl; return 0;
		}
		if(input[i] == 0) continue;

		int downLimit = i-r+1;
		int upLimit = i+r-1;
		bool foundOne = false;
		for(int j = max(downLimit,0); j <= min(n-1,upLimit); j++){
			if(cc[j] <= 0){
				cout<<-1<<endl; return 0;
			}
			if(cc[j] == 1)
				foundOne = true;

		}

		if(!foundOne){
			takata++;
			for(int j = max(downLimit,0); j <= min(n-1,upLimit); j++){
				cc[j]--;
			}
		}
	}

	cout<<total-takata<<endl;

	return 0;
}