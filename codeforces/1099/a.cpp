
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;

int h,w;
int u1,d1;
int u2,d2;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>w>>h;
	cin>>u1>>d1;
	cin>>u2>>d2;


	while(h > 0){
		w += h;
		if(h == d1){
			w -= u1;
			w = max(0,w);
		}
		if(h == d2){
			w -= u2;
			w = max(0,w);
		}

		h--;
	}

	cout<<w<<endl;
	return 0;
}