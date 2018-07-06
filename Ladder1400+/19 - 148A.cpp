#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int k,l,m,n,d;
int vals[4];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>vals[0]>>vals[1]>>vals[2]>>vals[3];
	cin>>d;

	sort(vals,vals+4);
	map<int,int> done;
	int count = 0;
	for(int i = 0; i<4; i++){
		for(int j = vals[i]; j<=d; j+=vals[i]){
			if(done[j] == 0){
				done[j]++;
				count++;
			}
		}
	}

	cout<<count<<endl;


	return 0;
}
