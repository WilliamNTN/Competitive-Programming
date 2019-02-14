
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 1012;
LL n;
LL s;
LL vals[maxN];
LL totalSum;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	totalSum = 0;
	cin>>n>>s;
	LL less = 0x3f3f3f3f;
	for(int i = 0; i < n; i++){
		cin>>vals[i];
		totalSum += vals[i];
		less = min(less,vals[i]);
	}
	if(s > totalSum){
		cout<<-1<<endl;
		return 0;
	}
	LL soFar = 0;
	for(int i = 0; i < n; i++){
		soFar += vals[i]-less;
		vals[i] = less;
	}
	if(soFar >= s){
		cout<<less<<endl;
		return 0;
	}
	while(soFar < s){
		LL rest = s - soFar;
		LL howMuch = ceil(rest/(n*1.0));
		less -= howMuch; break;
	}
	cout<<less<<endl;

}
