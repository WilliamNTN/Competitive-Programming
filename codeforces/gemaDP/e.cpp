#include <bits/stdc++.h>
using namespace std;
#define LL long long int

string s1,s2;
LL count4,count7;
LL total;
LL dp[20][20][20][2];
int limit[20];

LL solve(int ndigit, int n4, int n7, int islimited, int maxpos){

	if(ndigit > maxpos){
		if(n4 == count4 || n7 == count7) return 1;
		return 0;
	}

	if(dp[ndigit][n4][n7][islimited] != -1)
		return dp[ndigit][n4][n7][islimited];

	int thisLimit = islimited == 1? limit[ndigit]:9;
	LL ans = 0;
	for(int i=0; i<=thisLimit;i++){
		int nextLimited = (i == thisLimit && islimited == 1)? 1 : 0;
		if(i == 4)
			ans += solve(ndigit+1,n4+1,n7,nextLimited,maxpos);
		else if(i == 7)
			ans += solve(ndigit+1,n4,n7+1,nextLimited,maxpos);
		else
			ans += solve(ndigit+1,n4,n7,nextLimited,maxpos);
	}	

	return dp[ndigit][n4][n7][islimited] = ans;

}


void remove1FromS1(){

	int actualPos = s1.size()-1;
	int check = 0;
	while(!check){
		if(s1[actualPos] == '0'){
			s1[actualPos] = '9';
			actualPos--;
		}
		else{
			check = 1;
			s1[actualPos] = (((s1[actualPos]-'0') -1 ) + '0');
		}
	}
	int i;
	for(i = 0; i< s1.size(); i++)
		if(s1[i] != '0') break;

	s1 = s1.substr(i);

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>count4>>count7;
	cin>>s1>>s2;
	remove1FromS1();
	
	for(int i = s2.size(); i>=1; i--)
		limit[i] = s2[i-1] - '0';

	memset(dp,-1,sizeof(dp));
	LL rs2 = solve(1,0,0,1,s2.size());

	for(int i = s1.size(); i>=1; i--)
		limit[i] = s1[i-1] - '0';

	memset(dp,-1,sizeof(dp));
	LL rs1 = solve(1,0,0,1,s1.size());

	cout<<rs2 - rs1<<endl;

}
