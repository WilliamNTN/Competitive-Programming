#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n, numbers[101234];
unordered_set<LL> tprimes;
LL maior = 1012345;

void SE(){
	bool primes[maior+1];
	memset(primes,true,sizeof(primes));

	for(LL p = 2; (p*p)<=maior; p++){

		if(primes[p]){
			for(LL i = p*2; i<=maior; i+=p)
				primes[i] = false;
		}
	}

	for(LL p = 2; p<=maior; p++)
		if(primes[p]){
			tprimes.insert((p));
		}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(LL i =0; i<n; i++){
		cin>>numbers[i];
	}
	
	SE();
	for(LL i=0; i<n; i++){
	    if(sqrt(numbers[i]) - (int)sqrt(numbers[i]) == 0){
    		if(tprimes.count( sqrt(numbers[i]) ) > 0)
    			cout<<"YES"<<endl;
    		else
    			cout<<"NO"<<endl;
	    }
    	else
    		cout<<"NO"<<endl;
	    
	}

	return 0;
}
