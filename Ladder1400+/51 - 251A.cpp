#include <bits/stdc++.h>
using namespace std;
#define LL long long int

LL n,d;
vector<LL> vals;

LL binomialCoeff(LL a, LL k){
    LL res = 1;
 
    if (k > a - k)
        k = a - k;
 
    for (LL i = 0; i < k; ++i){
        res *= (a - i);
        res /= (i + 1);
    }

    return res;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>d;
	for(int i=0;i<n;i++){
		LL a; cin>>a;
		vals.push_back(a);
	}

	LL pos = 0, minPos = 2;
	LL start = 0;
	LL count = 0;
	while(pos != (n-1)){
		pos = lower_bound(vals.begin()+start, vals.end(), vals[start]+d) - vals.begin();
		if(vals[pos] != (vals[start]+d)) pos--;
		if(pos == start || pos < minPos){
			start++;
			minPos = start+2;
			continue;
		}
		count += binomialCoeff(pos-start+1,3);
		start++;
		minPos = pos+1;
	}

	cout<<count<<endl;
	return 0;
}
