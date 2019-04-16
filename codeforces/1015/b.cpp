#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s,t;
int n;
string a1,a2;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s>>t;
	//apply to s

	a1 = s;
	a2 = t;
	sort(a1.begin(),a1.end());
	sort(a2.begin(),a2.end());

	if(a1 != a2){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> ans;
	int pt1 = n-1;
	while(pt1 >= 1){
		int pt2 = 0;
		while(s[pt2] != t[pt1]) pt2++;
		while(pt2 < pt1){
			ans.pb(pt2+1);
			swap(s[pt2],s[pt2+1]);
			pt2++;
		}
		pt1--;
	}
	cout<<ans.size()<<endl;
	for(int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
