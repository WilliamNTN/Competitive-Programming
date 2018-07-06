#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define LL long long int
#define pair pair<LL,LL>
const int N = 101234;

pair exams[N];
LL n,r,avg;

bool sortSecond(const pair &a,const pair &b){
	return a.ss < b.ss;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>r>>avg;
	LL total = (n*avg);
	for(LL i=0;i<n;i++){
		LL a,b;
		cin>>a>>b;
		exams[i] = make_pair(a,b);
		total -=a;
	}
	sort(exams,exams+n,sortSecond);
	

	LL count = 0;

	for(int i = 0; i<n && total > 0; i++){
		LL toMove = total >= (r - exams[i].ff)? r-exams[i].ff : total;
		total -= toMove;
		count += toMove * exams[i].ss;
	}

	cout<<count<<endl;
	return 0;
}
