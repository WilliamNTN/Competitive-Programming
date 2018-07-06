#include <bits/stdc++.h>
using namespace std;
#define LL long long int

int n,m;
string grades[110];
set<int> ss;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>grades[i];

	int count = 0;
	for(int i = 0; i < m; i++){
		int maxValue = 0;
		for(int j = 0; j<n; j++){
			if(grades[j][i] - '0' > maxValue)
				maxValue = grades[j][i] - '0';
		}

		for(int j = 0; j<n; j++)
			if(grades[j][i] - '0' == maxValue){
				if(ss.count(j) == 0) count++;
				ss.insert(j);
			} 
	}

	cout<<count<<endl;
	return 0;
}
