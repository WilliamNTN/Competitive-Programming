
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int q;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>q;
	while(q--){
		int n;
		string s;
		cin>>n>>s;

		if(n==2){
			if(s[0] < s[1]){
				cout<<"YES"<<endl<<2<<endl;
				cout<<s[0]<<" "<<s[1]<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl<<2<<endl;
			cout<<s[0]<<" "<<s.substr(1)<<endl;
		}
	}
	return 0;
}
