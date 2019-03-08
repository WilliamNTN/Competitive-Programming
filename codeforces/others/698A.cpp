#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int n;
int vals[maxN];

int solve(int position, int last){
	if(position >= n) return 0;

	if(vals[position] == 0) return solve(position+1,0)+1;
	if(vals[position] == 1){
		if(last != 1) return solve(position+1,1);
		return solve(position+1,0)+1;
	} 
	if(vals[position] == 2){
		if(last != 2) return solve(position+1,2);
		return solve(position+1,0)+1;
	}

	LL a = LONG_MAX;
	LL b = LONG_MAX;
	if(last != 1)
		a = solve(position+1,1);
	if(last != 2)
		b = solve(position+1,2);

	return min(a,b);
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	cout<<solve(0,0)<<endl;
	return 0;
}