
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
vector<LL> demages;
int n,k;
string s;


void print(){
	for(int i = 0; i < n; i++)
		cout<<demages[i]<<" ";
	cout<<endl<<endl;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i = 0; i < n; i++){
		LL a;
		cin>>a;
		demages.pb(a);
	}
	cin>>s;

	int pt1 = 0, pt2 = 0;
	LL totalDemage = 0;
	while(pt1 < n){
		while(pt2 < n && s[pt2] == s[pt1]) pt2++;
		int len = pt2 - pt1;
		if(len > k){
			//choose K greater among in [pt1,pt2)
			vector<LL> aux;
			for(int i = pt1; i < pt2; i++)
				aux.pb(demages[i]);
			sort(aux.begin(),aux.end());
			for(int i = aux.size()-1,count = 0; count < k; count++,i--){
				totalDemage += aux[i];
			}
		}
		else{
			for(int i = pt1; i < pt2; i++){
				totalDemage += demages[i];
			}
		}
		pt1 = pt2;

	}
	cout<<totalDemage<<endl;
	return 0;
}
