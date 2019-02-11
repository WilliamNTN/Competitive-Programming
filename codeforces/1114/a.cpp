
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 101234;
int x,y,z;
int green,purple,black;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>x>>y>>z;
	cin>>green>>purple>>black;

	if(green < x){
		cout<<"NO"<<endl;
		return 0;
	}
	green -= x;
	int toSecond = green + purple;
	if(toSecond < y){
		cout<<"NO"<<endl;
		return 0;
	}
	toSecond -= y;
	int rest = toSecond + black;
	if(rest < z)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;

	return 0;
}
