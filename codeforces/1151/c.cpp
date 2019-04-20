#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL l,r;
LL mod = 1000000007;
LL curOdd,curEven,curTotal;
LL lOdd,lEven,rOdd,rEven;
bool doneL;

LL getEvenSum(int nE){

	return ((((nE%mod)*(nE%mod))%mod) + (nE%mod))%mod;
}
LL getOddSum(int nO){

	return ((nO%mod) * (nO%mod))%mod;
}

LL modPow(LL a, LL b) {
  a %= mod;
  LL ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans%mod;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	curOdd = curEven = curTotal = 0;
	rOdd = lOdd = rEven = lEven = 0;
	cin>>l>>r;
	LL index = 0;
	LL side = 1;
	doneL = false;
	while(true){
		curTotal += pow(2,index);
		//curTotal = (curTotal + modPow(2,index))%mod;
		if(side == 1){
			//curOdd += pow(2,index);
			curOdd = (curOdd + modPow(2,index))%mod;
		}
		else{
			//curEven += pow(2,index);
			curEven = (curEven + modPow(2,index))%mod;
		}

		if(!doneL && curTotal >= l){
			LL diff = ((curTotal%mod) - (l%mod))%mod;
			lOdd = curOdd;
			lEven = curEven;
			if(side == 1)
				lOdd -= (diff+1);
			else
				lEven -= (diff+1);
			doneL = true;
		}
		if(curTotal >= r){
			LL diff = ((curTotal%mod) - (r%mod))%mod;
			rOdd = curOdd;
			rEven = curEven;
			if(side == 1)
				rOdd -= diff;
			else
				rEven -= diff;
			break;
		}
		index++;
		if(side == 1) side = 0;
		else side = 1;
	}

	
	LL rSum = (getOddSum(rOdd)%mod + getEvenSum(rEven)%mod)%mod;
	LL lSum = (getOddSum(lOdd)%mod + getEvenSum(lEven)%mod)%mod;

	cout<<rSum - lSum<<endl;
	return 0;
}
