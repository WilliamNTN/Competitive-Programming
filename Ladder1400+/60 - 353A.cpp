#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
int valsUp[110], valsDown[110];
int sUp, sDown;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	sUp = sDown = 0;
	for(int i=0; i<n; i++){
		cin>>valsUp[i]>>valsDown[i];
		sUp += valsUp[i];
		sDown += valsDown[i];
	}

	if(sUp % 2 != sDown % 2){
		cout<<-1<<endl; return 0;
	}

	if(sUp % 2 == 0){
		cout<<0<<endl; return 0;
	}
	int ans = -1;
	for(int i=0;i<n;i++)
		if(valsUp[i]%2 != valsDown[i]%2)
			ans = 1;

	cout<<ans<<endl;
	return 0;
}
