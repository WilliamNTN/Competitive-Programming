#include <bits/stdc++.h>
using namespace std;


#define LL long long int
#define fi first
#define se second
#define pair pair<LL,LL>

LL n,m;
pair a[1012345];

bool byValue(const pair &a, const pair &b){
	return (a.fi < b.fi);
}

LL getDiffPosition(LL li, LL ri, LL xi){

	for(LL i = 0; a[i].fi != xi; i++)
		if( (a[i].se >= li) && (a[i].se <= ri))
			return a[i].se+1;

	for(LL i = (n-1); a[i].fi != xi; i--)
		if((a[i].se >= li) && (a[i].se <= ri))
			return a[i].se+1;

	return -1;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;

	for(LL i=0;i<n;i++){
		LL entry;
		cin>>entry;
		a[i] = make_pair(entry,i); // fi = value, se = position
	}

	sort(a,a+n,byValue);

	while(m > 0){
		m--;
		LL li,ri,xi;
		cin>>li>>ri>>xi; li--; ri--;

		cout<<getDiffPosition(li,ri,xi)<<endl;
	}

	return 0;
}
