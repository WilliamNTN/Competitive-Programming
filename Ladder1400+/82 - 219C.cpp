#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 501210;
int n,k;
string s;
string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){ 
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>k;
	cin>>s;
	if(k == 2){
		string pt1 = "AB";
		string pt2 = "BA";
		int ans0 = 0,ans1 = 0;
		for(int i=0; i < n; i++){
			if(s[i] != pt1[i%2]) ans0++;
			if(s[i] != pt2[i%2]) ans1++;
		}
		string final = ans0 <= ans1 ? pt1 : pt2;
		cout<<min(ans0,ans1)<<endl;
		for(int i = 0; i < n; i++)
			cout<<final[i%2];
		cout<<endl;
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j < n && s[i] == s[j]) j++;

		string q = letters;
		q.erase(q.find(s[i]),1);
		if(j < n) q.erase(q.find(s[j]),1);
		for(int k = i+1; k < j; k += 2){
			ans++;
			s[k] = q[0];
		}
	}

	cout<<ans<<endl<<s<<endl;

	return 0;
}