#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int t;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>t;

	while(t){
	    t--;
		double angle;
		cin>>angle;

		if(angle >= 60){
			double x = 180.0 / angle;

			double n = (2.0*x)/(x-1.0);
            
            if((n-(int)n)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}

	return 0;
}
