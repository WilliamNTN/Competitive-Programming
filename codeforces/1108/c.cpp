
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 201234;
int n;
char vals[maxN];


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>vals[i];

	
	char ansPattern[3] = {'R','G','B'};
	int ansDiff = n+1;
	char holders[3] = {'R','G','B'};

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				if(i != j && j != k && i != k){
					char thisPattern[3] = {holders[i],holders[j],holders[k]};
					int diff = 0;
					for(int l = 0; l < n; l++)
						if(vals[l] != thisPattern[l%3])
							diff++;
					if(diff < ansDiff){
						ansDiff = diff;
						for(int l = 0; l < 3; l++)
							ansPattern[l] = thisPattern[l];
					}
				}
			}
		}
	}

	cout<<ansDiff<<endl;
	for(int i = 0; i < n; i++){
		cout<<ansPattern[i%3];
	}
	cout<<endl;
	return 0;
}
