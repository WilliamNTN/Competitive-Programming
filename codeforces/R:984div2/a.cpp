#include <bits/stdc++.h>
using namespace std;

int n;
int vals[1001];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; i++)
		cin>>vals[i];

	sort(vals,vals+n);

	int t = n;
	int max = n-1;
	int min = 0;
	while(t > 1){
		max--;
		t--;
		if(t > 1){
			min++;
			t--;
		}
	}

	cout<<vals[max]<<endl;

	return 0;
}
