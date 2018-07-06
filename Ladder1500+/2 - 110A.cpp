#include <bits/stdc++.h>
using namespace std;

#define LL long long int

string n;

LL getNLuck(string entry){
	LL count = 0;

	for(LL i=0; i<entry.size(); i++)
		if(entry[i] == '4' || entry[i] == '7')
			count++;

	return count;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	
	int luck = 0;

	LL nLuck = getNLuck(n);
	n = to_string(nLuck);

	nLuck = getNLuck(n);
	
	if(nLuck == n.size())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
	return 0;
}
