#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;

int t;
int n;
string s;


int distance(char a, char b){
	return abs(a-b);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
		
	cin >> t;
	while(t--){
		cin>>n>>s;
		int i = 0, j = n-1;
		bool flag = true;
		while(i < j){
			if(distance(s[i],s[j]) != 0 && distance(s[i],s[j]) != 2)
				flag = false;
			i++; j--;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}

	return 0;
}
