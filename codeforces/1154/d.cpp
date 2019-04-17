#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
LL n,a,b;
LL maxA;
int vals[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>b>>a;
	maxA = a;
	for(int i = 0; i < n; i++)
		cin>>vals[i];
	int i;
	for(i = 0; i < n; i++){
		if(!b && !a) break;
		if(a == maxA){
			a--;
		}
		else{
			if(vals[i] == 1){
				if(b > 0){
					b--; a++;
				}else a--;
			}
			else{
				if(a > 0)a--;
				else b--;
			}
		}
	}
	cout<<i<<endl;
	return 0;
}
