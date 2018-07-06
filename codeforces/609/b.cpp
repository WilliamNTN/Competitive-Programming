#include <bits/stdc++.h>
using namespace std;

int n,m;
int genres[12] = {0};

int main(){
	cin>>n>>m;
	int aux;
	for(int i=0;i<n;i++){
		cin>>aux;
		genres[aux-1]++;
	}

	long long int sum = 0;
	for(int i=0;i<(m-1);i++){
		for(int j=i+1;j<m;j++){
			sum += genres[i]*genres[j];
		}
	}

	cout<<sum<<endl;
	return 0;
}