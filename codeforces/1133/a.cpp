#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
int h1,h2;
int m1,m2;
string a,b;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b;
	h1 = stoi(a.substr(0,a.find(":")));
	a = a.substr(a.find(":")+1);
	m1 = stoi(a);

	h2 = stoi(b.substr(0,b.find(":")));
	b = b.substr(b.find(":")+1);
	m2 = stoi(b);

	
	int minutes = (m2-m1) + (h2-h1)*60;
	minutes = minutes/2;

	m1 += minutes;
	while(m1 >= 60){
		m1 -= 60;
		h1++;
	}
	cout<<setfill('0')<<setw(2)<<h1<<":";
	cout<<setfill('0')<<setw(2)<<m1<<endl;

	return 0;
}
