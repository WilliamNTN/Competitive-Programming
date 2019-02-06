
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair


/*
    b[i] = a[i] + a[n-i+1]
	a[i] = b[i] - a[n-i+1];
	
	se n = 6
	n/2 = 3;
	b[1] = a[1] + a[6-1+1(6)]
	b[2] = a[2] + a[6-2+1(5)]
	b[3] = a[3] + a[6-2+1(4)]

	a[i] = b[i] - a[n-i+1]
	
	a[n-i+1] = b[i] - a[i]
	i -> n/2 + 1 -> n

	10 20 30



b[i] = a[i] + a[n-i+1];


4
5 6
b[1] = a[1] + a[4]
b[2] = a[2] + a[3]


*/
const int maxN = 201234;
LL n;
LL b[maxN];
LL a[maxN];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i = 1; i <= n/2; i++)
		cin>>b[i];


	LL i = 2, j = n-1;
	a[1] = 0;
	a[n] = b[1];

	while(i < j){
		//b[i] = a[i] + a[j]
		a[i] = a[i-1];
		a[j] = b[i] - a[i];
		LL diff = a[j] - a[j+1];
		if(diff > 0){
			a[j] -= diff;
			a[i] += diff;
		}
		i++; j--;

	}

	for(LL i = 1; i <=n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
