#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 110;
int t;
int n;
int first[maxN];
int inter[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>t;
	for(int i = 0; i < n; i++){
		cin>>first[i];
		cin>>inter[i];
	}
	int minTime = INT_MAX;
	int index = -1;
	for(int i = 0; i < n; i++){
		int time = first[i];
		while(time < t){
			time += inter[i];
		}
		if(time < minTime){
			minTime = time;
			index = i+1;
		}
	}
	cout<<index<<endl;
	return 0;
}
