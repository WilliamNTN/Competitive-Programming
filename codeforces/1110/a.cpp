
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 102134;
int b,k;
int vals[maxN];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>b>>k;
	for(int i = 0; i < k; i++)
		cin>>vals[i];
	
	if(b%2 == 0){ //even
		if(vals[k-1]%2 == 0) cout<<"even"<<endl;
		else cout<<"odd"<<endl;
		return 0;
	} 
	//odd
	//odd * odd = odd

	//even * odd = even
	//odd * odd = odd

	int result = 0;
	for(int i = 0; i < k; i++){
		result = (result + vals[i]%2)%2;
	}
	if(result == 0) cout<<"even"<<endl;
	else cout<<"odd"<<endl;
	return 0;
}
