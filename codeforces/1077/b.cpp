
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;

LL n;
int vals[maxN];

bool isDisturbed(int i){
	return (vals[i] == 0 && vals[i-1] == 1 && vals[i+1] == 1);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
	}

	int ans = 0;
	bool done = 0;
	for(int i = 1; i < n-1; i++){
		if(isDisturbed(i)){
			if((i-2) >= 0 && isDisturbed(i-2) && !done)
				done = true;
			else{
				ans++;
				done = false;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
