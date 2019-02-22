#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
LL a1,b1,a2,b2;
LL n;
string s;
map<char,LL> moves;
LL totalMoves;
pair<LL,LL> cumsum[maxN];
bool test(LL days){
	LL rep = days/n;
	LL rem = days%n;

	LL x,y;
	x = a1 + cumsum[rem].ff + (rep * 1LL * cumsum[n].ff); 
	y = b1 + cumsum[rem].ss + (rep * 1LL * cumsum[n].ss);
	LL dist = abs(x-a2) + abs(y-b2);
	if(dist <= days) return true;
	return false; 
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>a1>>b1>>a2>>b2>>n>>s;
	cumsum[0] = make_pair(0,0);
	for(int i = 0; i < n; i++){
		int x = 0, y = 0;
		if(s[i] == 'U') y = 1;
		if(s[i] == 'D') y = -1;
		if(s[i] == 'L') x = -1;
		if(s[i] == 'R') x = 1;

		cumsum[i+1] = make_pair(cumsum[i].ff + x,cumsum[i].ss + y);
	}
	//U y++
	//D y--
	//L x--
	//R x++
	LL xDiff = a2-a1;
	LL yDiff = b2-b1;
	totalMoves = 0;
	if(xDiff > 0){ // x2 > x1, needs x++
		moves['R'] = abs(xDiff);	
	}else if(xDiff < 0){//x1 < x1, needs x--
		moves['L'] = abs(xDiff);
	}
	totalMoves += xDiff;

	if(yDiff > 0){//y2 > y1, needs y++
		moves['U'] = abs(yDiff);
	}else if(yDiff < 0){
		moves['D'] = abs(yDiff);
	}
	totalMoves += abs(yDiff);

	if(xDiff == 0 && yDiff == 0){
		cout<<0<<endl; return 0;
	}

	LL l = 1, r = pow(10,18)-1;
	LL ans = -1;
	while(l <= r){
		LL middle = l + (r-l)/2;
		if(test(middle)){
			ans = middle;
			r = middle - 1;
		}else{
			l = middle + 1;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
