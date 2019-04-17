#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
LL a,b,c;
string order = "abcacba";
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>a>>b>>c;   //fish, rabbit, chicken
	//3a, 2b, 2c, starting from monday
	//2a, 2b, 2c, starting from tuesday

	LL fullWeeks = 0;
	fullWeeks = min(a/3,min(b/2,c/2));
	a -= (fullWeeks * 3);
	b -= (fullWeeks * 2);
	c -= (fullWeeks * 2);
	LL days;
	LL ans = 0;
	LL a1,b1,c1;
	
	for(int i = 0; i < 7; i++){
		days = 0;
		a1 = a; b1 = b; c1 = c;
		for(int j = i; ; j = (j+1)%7){
			if(order[j] == 'a'){
				if(a1 > 0) a1--;
				else break;
			}else if(order[j] == 'b'){
				if(b1 > 0) b1--;
				else break;
			}else{
				if(c1 > 0) c1--;
				else break;
			}
			days++;
		}
		ans = max(ans,days);
	}

	cout<<fullWeeks*7 + ans<<endl;

	return 0;
}
