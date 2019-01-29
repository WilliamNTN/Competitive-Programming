
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1000000010;

map<LL,LL> powers;
LL n,k;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(0);
	

	cin>>n>>k;
	powers[0] = n;

	LL nPairs = n/2;   //pairs I can remove
	LL diff = n-k;   // how many numbers i need to remove
	LL actual = 0;  // power im currently looking

	while(diff > 0 && nPairs > 0 && actual < 30){
		//cout<<"Enter: "<<diff<<" "<<nPairs<<endl;
		if(diff <= nPairs){ // it will finish
			powers[actual] -= diff*2;
			actual++;
			powers[actual] += diff;
			diff = 0;
		}
		else{
			//remove All Pairs
			powers[actual] -= nPairs * 2;
			actual++;
			powers[actual] += nPairs;
			diff -= nPairs;
			nPairs = powers[actual]/2;
		}
	}

	if(diff == 0){
		cout<<"YES"<<endl;
		for(LL i = 0; i < 35; i++){
			for(LL j = 0; j < powers[i]; j++){
				cout<<pow(2,i)<<" ";
			}
		}
		cout<<endl;

	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}

