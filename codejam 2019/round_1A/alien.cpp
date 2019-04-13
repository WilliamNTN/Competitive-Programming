#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1010;
int n;
string vals[maxN];
int t;
int used[maxN];
set<string> suffixUsed;

bool compare(string a, string b){
	return a.size() > b.size();
}
int getSufixSize(string a, string b){

	int pt1 = a.size()-1, pt2 = b.size()-1;
	int ans = 0;
	while(pt1 >= 0 && pt2 >= 0 && a[pt1] == b[pt2]){
		ans++;
		pt1--;
		pt2--;
	}

	return ans;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>vals[i];

		sort(vals,vals+n,compare);
		memset(used,0,sizeof(used));
		suffixUsed.clear();
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(used[i] == 1) continue;
			int betterIndex = -1, betterSize = 0;
			for(int j = i+1; j < n; j++){
				if(used[j] == 1) continue;

				int size = getSufixSize(vals[i],vals[j]);
				string s = vals[i].substr(vals[i].size()-size);
				while(size > 0 && suffixUsed.find(s) != suffixUsed.end()){
					size--;
					if(size > 0)
						s = vals[i].substr(vals[i].size()-size);
				}
				if(size > betterSize){
					betterSize = size;
					betterIndex = j;
				}
			}
			if(betterIndex != -1){
				ans += 2;
				used[i] = 1;
				used[betterIndex] = 1;
				string s = vals[i].substr(vals[i].size()-betterSize);
				suffixUsed.insert(s);
			}
		}

		cout<<"Case #"<<casen<<": "<<ans<<endl;
	}
	return 0;
}
