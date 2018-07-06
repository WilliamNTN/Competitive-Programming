#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;
int vals[10];
int n;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	int min = 1;
	for(int i = 1; i<=9; i++){
		cin>>vals[i];
		if(vals[i] <= vals[min]) min = i;
	}

	int len = n/vals[min];
	if(len == 0){cout<<-1<<endl; return 0;}
	char m = min + '0';
	string ans = "";
	for(int i = 0; i<len; i++)
		ans += m;

	int remain = n - len * vals[min];
	

	while(remain > 0){

		int disp = remain + vals[min];
		int gr = min;

		for(int i = 1; i<=9; i++)
			if(vals[i] <= disp) gr = i;


		int ch = 0;
		for(int i = 0; i<ans.size(); i++){
			if((ans[i] - '0') < gr){
				ch = 1;
				ans[i] = (gr + '0');
				break;
			}
		}

		if(ch)
			remain = disp - vals[gr];
		else
			remain = 0;

	}

	cout<<ans<<endl;
	return 0;
}
