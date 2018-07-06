#include <bits/stdc++.h>
using namespace std;
#define LL long long int

const int maxN =101234;

int n;
int vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i<n; i++) cin>>vals[i];

	sort(vals,vals+n);
	
	int acc = 0;
	int count = 0;
	for(int i = 0; i<n; i++){
		if(vals[i] != 0 && vals[i] + acc != 0 && (i == 0? 1 : vals[i] != vals[i-1])){
			count++;
			acc += - (vals[i] + acc);
			
		}
	}

	cout<<count<<endl;
	return 0;
}
