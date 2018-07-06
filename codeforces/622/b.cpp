#include <bits/stdc++.h>
using namespace std;

#define LL long long int

LL n;
LL hour, minute;
string s;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	char *endptr = NULL;
	cin>>s>>n;

	hour = strtoll(s.substr(0,2).c_str(),&endptr,10);
	minute = strtoll(s.substr(3,2).c_str(),&endptr,10);

	LL addHours = n/60;
	LL addMinutes = n-(addHours*60);

	
	hour += addHours; minute += addMinutes;

	addHours = minute/60;
	hour+=addHours;

	hour = hour%24;
	minute = minute%60;
	cout<<setw(2)<<setfill('0')<<hour<<":";
	cout<<setw(2)<<setfill('0')<<minute<<endl;

	return 0;
}
