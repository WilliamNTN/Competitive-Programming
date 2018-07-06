#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    cin>>n;
	while(n--){
		double p,q,b;
		cin>>p>>q>>b;
		double frac = fabs((int) (p/q) - (double)(p/q));
		cout<<frac<<endl;

		set<double> used;
		int ans = 1;
		cout<<"N = "<<n<<endl;
		setprecision(1);
		while(frac != 0.0 && ans == 1){
			cout<<"Entry frac "<<frac<<endl;
			used.insert(frac);
			frac = fabs( (int)(frac*b) - (double)(frac*b));

			if(used.count(frac) > 0){
				ans = 0;
			}

			cout<<"Out frac "<<frac<<endl;
		}

		if(ans)
			cout<<"Finite"<<endl;
		else
			cout<<"Infinite"<<endl;
	}

	return 0;
}
