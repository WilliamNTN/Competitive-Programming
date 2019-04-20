#include <bits/stdc++.h>
using namespace std;
#define LL long long int


int n;
int vals[1012345];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=1; i<=n; i++) cin>>vals[i];

	LL count = 0;
	LL done  = 0;

	while(!done){
		done = 1;
		for(int i = 1; i<=n; i++){
			if(vals[i] != i){
				count++;
				swap(vals[i],vals[vals[i]]);
				i = n;
				done = 0;
			}
		}
	}
	for(int i = 1; i<=n;i ++) cout<<vals[i]<<" "<<endl;
	if((count%2) == ((3*n)%2))
		cout<<"Petr"<<endl;
	else cout<<"Um_nik"<<endl;
	return 0;
}
