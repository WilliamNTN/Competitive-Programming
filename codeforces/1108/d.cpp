
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j < n && s[j] == s[i]) j++;

		string q = "RGB";
		q.erase(q.find(s[i]),1);
		if(j < n) q.erase(q.find(s[j]),1);
		for(int k = i+1; k < j; k += 2){
			s[k] = q[0];
			ans++;
		}
	}

	cout<<ans<<endl<<s<<endl;
	return 0;
}
