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

bool isEven(char c){
	int a = c - 'O';
	if(a%2 != 0) return true;
	return false;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(isEven(s[i])){
			ans += (i+1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
