#include <bits/stdc++.h>
using namespace std;

int n;
int vals[100];

#define LL long long int
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i<=n/2;i++)
		cin>>vals[i];

	sort(vals+1,vals+(n/2)+1);
	//odd
	int totalMoves = 0;
	int target = n-1;

	for(int i = n/2; i >=1; i--){
		totalMoves += abs((target - vals[i]));
		target -=2;
	}

	//even
	int totalMoves2 = 0;
	target = n;

	for(int i = n/2; i>=1; i--){
		totalMoves2 += abs((target - vals[i]));
		target -=2;
	}

	cout<<min(totalMoves2,totalMoves)<<endl;
	return 0;
}
