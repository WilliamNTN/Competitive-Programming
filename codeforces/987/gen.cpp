#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,d;
int valstest[1021345];
int vals[1012345];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 1; i<=n; i++) cin>>vals[i];


	///// 3n
	for(int i = 1; i<=n; i++) valstest[i] = i;
	
	for(int i = 1; i<=(3*n);i++){
		int a = rand() % n + 1;
		int b = rand() % n + 1;

		swap(valstest[a], valstest[b]);
	}
	int count1 = 0, done = 0;
	while(!done){
		done = 1;
		for(int i = 1; i<=n; i++){
			if(valstest[i] != i){
				count1++;
				swap(valstest[i],valstest[valstest[i]]);
				i = n;
				done = 0;
			}
		}
	}

	for(int i = 1; i<=n; i++) valstest[i] = i;
	
	for(int i = 1; i<=((7*n)+1);i++){
		int a = rand() % n + 1;
		int b = rand() % n + 1;

		swap(valstest[a], valstest[b]);
	}
	int count2 = 0;
	done = 0;
	while(!done){
		done = 1;
		for(int i = 1; i<=n; i++){
			if(valstest[i] != i){
				count2++;
				swap(valstest[i],valstest[valstest[i]]);
				i = n;
				done = 0;
			}
		}
	}

	
	int count3 = 0;
	done = 0;
	while(!done){
		done = 1;
		for(int i = 1; i<=n; i++){
			if(vals[i] != i){
				count3++;
				swap(vals[i],vals[vals[i]]);
				i = n;
				done = 0;
			}
		}
	}
	cout<<"1: "<<count1<<" 2: "<<count2<<" count3: "<<count3<<endl;

	return 0;
}
