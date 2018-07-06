#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n,m,k;
int vals[502134];

void solve(){

	int vp = 0, thiscount = 0;
	int i = 1, j =1;
	int count = n*m;
	int mvi = 1, idir = 1, itop = 1, ibot = n;
	int mvj = 0, jdir = 1, jleft = 2, jrit = m;
	cout<<vals[vp]<<" ";
	while(count){
		count--;
		cout<<i<<" "<<j<<" ";
		thiscount++;
		if(thiscount == vals[vp]){
			cout<<endl;
			vp++;
			thiscount = 0;
			if(vp < k)
				cout<<vals[vp]<<" ";
		}
		if(mvi){
			if(idir == 1){ // go down
				i++;
				if(i == ibot){
					mvi = 0;
					mvj = 1;
					idir = 0;
					ibot--;
				}
			}
			else if(idir == 0){ // go up
				i--;
				if(i == itop){
					mvi = 0;
					mvj = 1;
					idir = 1;
					itop++;
				}
			}
		}
		else{
			if(jdir == 1){ // go right
				j++;
				if(j == jrit){
					mvj = 0;
					mvi = 1;
					jdir = 0;
					jrit--;
				}
			}
			else if(jdir == 0){ // go left
				j--;
				if(j == jleft){
					mvj = 0;
					mvi = 1;
					jdir = 1;
					jleft++;
				}
			}
		}
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m>>k;
	int total = n*m;
	for(int i = 0; i < k-1; i++)
		vals[i] = total / k;
	vals[k-1] = total - ((total/k)*(k-1));

	solve();
	return 0;
}
