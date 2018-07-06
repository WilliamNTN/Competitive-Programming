#include <bits/stdc++.h>
using namespace std;
#define LL long long int


vector<int> getDivisors(int n){

	set<int> used;
	vector<int> divs;
	for(int i =2; i*i <= n; i++){
		if(n%i == 0){
			if(used.count(i) == 0){
				divs.push_back(i);
				used.insert(i);
			}
			if(used.count(n/i) == 0){
				divs.push_back(n/i);
				used.insert(n/i);
			}
		}
	}

	if(n > 2) divs.push_back(n);

	return divs;
}


bool isLucky(int n){
	while(n > 0){
		int r = n%10;
		n = n/10;
		if(r != 4 && r != 7){
		 return false;
		}
	}
	return true;
}
int n;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int ans = 0;
	vector<int> divs = getDivisors(n);
	for(int i=0; i < divs.size(); i++){
		if(isLucky(divs[i])) ans = 1;
	}

	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
