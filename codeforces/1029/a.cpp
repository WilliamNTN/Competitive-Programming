#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string t;
int n,k;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	cin>>t;
	int i;
	for(i = 0; i < (n-1); i++){
		string thisAdd = t.substr(t.size()-1-i);
		string whithOut = t.substr(i+1);
		if((whithOut + thisAdd) == t){
			break;
		}
	}
	string ans = "";
	if(i == (n-1))
		ans = t;
	else
		ans = t.substr(t.size()-1-i);

	cout<<t;
	for(int i = 1; i < k; i++)
		cout<<ans;
	cout<<endl;
	return 0;
}
