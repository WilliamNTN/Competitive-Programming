
// Correct for small and large
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second

const int maxN = 0;
LL t,n;


LL getLower(vector<int> digits){
	LL ans = 0;
	int check = 1;
	for(int i = 0; i < digits.size(); i++){
		if(digits[i]%2 != 0 && check){
			check = 0;
			digits[i]--;
			ans = ans*10 + digits[i];
		}
		else if(check)
			ans = ans*10 + digits[i];

		else if(!check){
			ans = ans*10 + 8;
		}
	}
	return ans;
}

LL getUpper(vector<int> digits, LL n){
	
	int pos;
	for(pos=0; digits[pos]%2 == 0 && pos < digits.size(); pos++);

	if(pos == digits.size()) return n;
	
	LL ans = 0;

	if(digits[pos] != 9){
		for(int i = 0; i < pos; i++)
			ans = ans*10 + digits[i];
		ans = ans*10 + digits[pos]+1;

		ans *= pow(10,digits.size()-pos-1);
		return ans;
	}
	pos--;
	while(pos >= 0 && digits[pos] == 8) pos--;
	if(pos == -1){
		ans = 2;
		ans *= pow(10,digits.size());
		return ans;
	}

	for(int i = 0; i < pos; i++)
		ans = ans*10 + digits[i];
	ans = ans*10 + digits[pos]+2;
	ans *= pow(10,digits.size() -1 - pos);
}	
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);


	cin>>t;
	int count = 1;
	while(t--){
		cin>>n;
		LL nn = n;
		vector<int> digits;
		while(nn){
			digits.insert(digits.begin(),(nn-(nn/10)*10));
			nn /= 10;
		}

		LL lower = getLower(digits);
		LL upper = getUpper(digits,n);
		//cout<<"LOWER: "<<lower<<endl;
		//cout<<"Upper: "<<upper<<endl;
		LL ans = min(abs(n-lower),abs(n-upper));
		cout<<"Case #"<<count++<<": "<<ans<<endl;
	}
	return 0;
}
