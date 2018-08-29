#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int maxN = 0;


void flip(vector<int> &arr, int k){
	int pt1 = 0, pt2 = k-1;

	while(pt1 < pt2){
		swap(arr[pt1],arr[pt2]);
		pt1++; pt2--;
	}
}


void pancakeSort(vector<int> &arr){

}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin>>n;
	vector<int> arr;
	for(int i = 0; i<n; i++){
		int a; cin>>a;
		arr.pb(a);
	}

	pancakeSort(arr);
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}