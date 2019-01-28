
#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int maxN = 0;
string s;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>s;

	// 1 - >  row always 1, col changes from 1 to 4
	// 0  ->  row always 3, col changes in 1 and 3

	int HActualCol = 1;
	int VActualCol = 1;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0'){
			cout<<1<<" "<<VActualCol<<endl;
			VActualCol = (VActualCol%4)+1;
		}
		else{
			cout<<3<<" "<<HActualCol<<endl;
			HActualCol = (HActualCol+2)%4;
		}
	}
	return 0;
}
