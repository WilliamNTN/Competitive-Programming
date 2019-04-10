#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int t;
string n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;
	for(int casen = 1; casen <= t; casen++){
		cin>>n;
		string a = n;
		string b = n;
		for(int i = 0; i < n.size(); i++){
			if(n[i] == '4'){
				a[i] = '3';
				b[i] = '1';
			}else{
				a[i] = n[i];
				b[i] = '0';
			}
		}

		int i = 0;
		while(a[i] == '0') i++;
		a = a.substr(i);
		i = 0;
		while(b[i] == '0') i++;
		b = b.substr(i);

		cout<<"Case #"<<casen<<": "<<a<<" "<<b<<endl;
	}
	return 0;
}
