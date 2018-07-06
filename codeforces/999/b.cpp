#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;

string inverse(string a, int index){
	string res = a;
	int i,j;
	for(i=0,j=index; i<= index; i++,j--){
		res[j] = a[i];
	}	
	return res;

}
int n;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;

	for(int i = 0; i<n; i++){
		if(n%(i+1) == 0)
			s = inverse(s,i);
	}

	cout<<s<<endl;
	return 0;
}
