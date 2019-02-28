#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL w1,h1,w2,h2;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>w1>>h1>>w2>>h2;

	LL botton = w1 + 2 + 2*h1;
	LL top = w2 + 2 + 2*h2;
	LL right = w1-w2;

	cout<<botton+top+right<<endl;
	return 0;
}
