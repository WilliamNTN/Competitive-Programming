#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,x;
int vals[20];

vector<string> bins;

void generateGray(){
	bins.push_back("0");
	bins.push_back("1");

	for(int i=2; i< (1<<n); i = i<<1){
		if((i<<1) < (1<<n)){
			for(int j=i-1; j>=0; j--)
				bins.push_back(bins[j]);
		}

		for(int j=0; j<i; j++)
			bins[j] = "0" + bins[j];

		if((i<<1) < (1<<n)){
			for(int j=i; j<(2*i); j++)
				bins[j] = "1"+bins[j];
		}
	}
}


int getSum(string a){
	int sum = 0;

	for(int i=0; i<n; i++)
		if(a[i] == '1')
			sum += vals[i];

	return sum;
}

int getSumi(string a){
	int sum = 0;

	for(int i=0; i<n; i++)
		if(a[i] == '0')
			sum += vals[i];

	return sum;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>x;

	for(int i=0; i<n; i++){
		cin>>vals[i];
	}

	generateGray();

	int count = 0;

	for(int i=0; i<bins.size(); i++){
		if(getSum(bins[i]) == x)
			count++;
		if(getSumi(bins[i]) == x)
			count++;
	}

	cout<<count<<endl;
}