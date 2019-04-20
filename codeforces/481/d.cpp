#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL vals[100100];
LL acMin;


LL solve(LL factor, LL last, LL acc){

	LL count = 0;

	for(LL i = 2; i< n; i++){
		if(vals[i] - last == factor)
			last = vals[i];
		else if((vals[i]+1)-last == factor){
			last = vals[i]+1;
			count++;
			if(count + acc > acMin) return acMin+1;
		}
		else if((vals[i]-1)-last == factor){
			last = vals[i]-1;
			count++;
			if(count + acc > acMin) return acMin+1;

		}
		else
			return 0x3f3f3f3f;
	}

	return count;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;

	for(LL i=0; i<n; i++) cin>>vals[i];


	int gamb1[3] = {-1,0,1};
	int gamb2[3] = {-1,0,1};

	acMin = 0x3f3f3f3f;
	for(int i =0 ; i<3; i++){
		for(int j = 0; j<3; j++){
			LL factor = (vals[1]+gamb2[j]) - (vals[0]+gamb1[i]);
			LL res = 0;
			if(i != 1) res++; if(j != 1) res++;
			res += solve(factor,vals[1]+gamb2[j],res);
			//cout<<vals[0] + gamb1[i]<<" "<<vals[1]+gamb2[j]<<": "<<factor<<" res: "<<res<<endl;

			if(res < acMin)
				acMin = res;
		}
	}
	if(acMin > n)
		cout<<-1<<endl;
	else
		cout<<acMin<<endl;

	return 0;
}
