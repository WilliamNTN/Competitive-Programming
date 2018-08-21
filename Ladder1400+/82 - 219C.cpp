#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 501210;
int n,k;
string row;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);



	cin>>n>>k;
	cin>>row;
	int ans = 0;
	for(int i = 1; i<n; i++){
		if(row[i] == row[i-1]){
			ans++;
			char one = row[i-1];
			char two = one;
			if((i+1) < n) two = row[i+1];
			for(int count = 0; count < k; count++){
				char thisChar = 'A' + count;
				if(thisChar == one || thisChar == two) continue;
				else{
					row[i] = thisChar;
					count = k+1;
				}
			}
		}
	}

	cout<<ans<<endl;
	cout<<row<<endl;
	return 0;
}
