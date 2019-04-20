#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n;
string s;
string gen = "ACTG";

LL getDist(char a, char b){
	
	if(b >= a){
		LL dist1 = b - a;
		LL dist2 = a + (26 - b);
		return min(dist1,dist2);
	}
	LL dist1 = a - b ;
	LL dist2 = b + (26 - a);
	return min(dist1,dist2);

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	LL ans = INT_MAX;

	for(int i = 0; i <=(n-4); i++){
		LL totalDist = 0;
		for(int j = i; j <= i+3; j++){
			totalDist += getDist(s[j],gen[j-i]);
		}
		ans = min(ans,totalDist);
	}
	cout<<ans<<endl;
	return 0;
}
