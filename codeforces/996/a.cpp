#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;

LL n;


int b[] = {1,5,10,20,100};

int solve(int target){

	int count = 0;

	for(int i = 4; i>=0; i--){
		while(target >= b[i]){
			count++;
			target -= b[i];
		}
		if(target == 0) break;
	}

	return count;

}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	cout<<solve(n)<<endl;

	return 0;
}
