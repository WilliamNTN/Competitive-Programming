#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1000000010;

map<int,int> powers;
int n,k;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cout<<fixed<<setprecision(0);
	cin>>n>>k;
	powers[0] = n;
	int nPairs = n/2;
	int kdif  = n-k;
	int curr = 0;
	while(kdif > 0 && nPairs > 0){
		
		int pairsToRemove = min(nPairs,kdif);
		powers[curr] -= pairsToRemove * 2;
		powers[++curr] += pairsToRemove;
		kdif-= pairsToRemove;
		nPairs /= 2;
	}

	if(kdif == 0){
		cout<<"YES"<<endl;
		for(int i = 0; i < 32; i++){
			for(int j = 0; j < powers[i]; j++)
				cout<<pow(2,i)<<" ";
		}
		cout<<endl;
	}

	else{
		cout<<"NO"<<endl;
	}
	return 0;
}