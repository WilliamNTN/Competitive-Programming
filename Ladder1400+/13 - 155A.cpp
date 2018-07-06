#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n;
int vals[1010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	cin>>vals[0];
	int best = vals[0], worst = vals[0];
	int amazing = 0;
	for(int i=1; i<n; i++){
		cin>>vals[i];
		if(vals[i] > best){
			amazing++;
			best = vals[i];
		}

		else if(vals[i] < worst){
			amazing++;
			worst =vals[i];
		}
	}

	cout<<amazing<<endl;
	return 0;
}

