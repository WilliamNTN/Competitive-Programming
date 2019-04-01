#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 2020;
LL n;
vector<LL> odd,even;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	LL a;
	for(int i = 0; i < n; i++){
		cin>>a;
		if(a%2 == 0) even.pb(a);
		else odd.pb(a);
	}

	sort(odd.begin(),odd.end());
	sort(even.begin(),even.end());

	int po = odd.size()-1;
	int pe = even.size()-1;


	while(po >= 0){
		po--;
		if(pe >= 0) pe--;
		else break;
	}
	LL sumOne = 0;
	for(int i = 0; i <= po; i++)
		sumOne += odd[i];
	for(int i = 0; i <= pe; i++)
		sumOne += even[i];


	po = odd.size()-1;
	pe = even.size()-1;

	while(pe >= 0){
		pe--;
		if(po >= 0) po--;
		else break;
	}
	LL sumTwo = 0;
	for(int i = 0; i <= po; i++)
		sumTwo += odd[i];
	for(int i = 0; i <= pe; i++)
		sumTwo += even[i];

	cout<<min(sumTwo,sumOne)<<endl;
	return 0;
}
