#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	if(n <= 2){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	if(n%2 == 0){
		//s1 = all even
		//s2 = all odd
		cout<<n/2;
		for(int i = 1; i <= n; i += 2)
			cout<<" "<<i;
		cout<<endl<<n/2;
		for(int i = 2; i <= n; i += 2)
			cout<<" "<<i;
		cout<<endl;
	}else{
		cout<<n-1;
		for(int i = 1; i < n; i++)
			cout<<" "<<i;
		cout<<endl<<1<<" "<<n<<endl;
	}
	return 0;
}
