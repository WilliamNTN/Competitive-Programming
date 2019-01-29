
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
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	int pt1 = 0;
	int jump = 2;
	while(pt1 < n){
		cout<<s[pt1];
		pt1+=jump;
		jump++;
	}

	cout<<endl;
	return 0;
}
