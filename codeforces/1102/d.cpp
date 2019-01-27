
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 301234;
int n;
string s;
int dif0,dif1,dif2;
int n0,n1,n2;
int ideal;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>s;
	n0 = n1 = n2 = dif0 = dif1 = dif2 = 0;
	ideal = n/3;
	for(int i = 0; i < n; i++){
		if(s[i] == '1') n1++;
		if(s[i] == '2') n2++;
		if(s[i] == '0') n0++;
	}

	dif0 = ideal - n0;
	dif1 = ideal - n1;
	dif2 = ideal - n2;


	for(int i = 0; i < n; i++){
		if(s[i] == '2' && dif2 < 0){
			if(dif0 > 0){//2 for 0
				s[i] = '0';
				dif2++;
				dif0--;
			}
			else if(dif1 > 0){ // 2 for 1
				s[i] = '1';
				dif2++;
				dif1--;
			}
		}
		else if(s[i] == '1' && dif1 < 0 && dif0 > 0){// 1 for 0
			s[i] = '0';
			dif1++;
			dif0--;
		}
	}

	for(int i = n-1; i>=0; i--){
		if(s[i] == '0' && dif0 < 0){

			if(dif2 > 0){// 0  to 2
				s[i] = '2';
				dif0++;
				dif2--;
			}
			else if(dif1 > 0){ // 0 to 1
				s[i] = '1';
				dif0++;
				dif1--;
			}
		}
		else if(s[i] == '1' && dif1 < 0 && dif2 > 0){//1 to 2
			s[i] = '2';
			dif1++;
			dif2--;
		}
	}

	cout<<s<<endl;
	return 0;
}
