#include <bits/stdc++.h>
using namespace std;
#define LL long long int
#define ff first
#define ss second

int n,k;
vector<int> team;
pair<int,int> students[110]; // grade, pos
set<int> use;

bool sortFirst(const pair<int,int> a, const pair <int,int> b){
	return a.ff < b.ff;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		students[i] = make_pair(a,i+1);
	}

	sort(students,students+n,sortFirst);	
	int count = 1;
	team.push_back(students[0].ss);
	int last = students[0].ff;

	for(int i=1; i<n; i++){
		if(students[i].ff != last){
			last = students[i].ff;
			team.push_back(students[i].ss);
			count++;
			if(count == k) break;
		}
	}

	if(team.size() == k){
		cout<<"YES"<<endl;
		for(int i=0; i<team.size(); i++)
			cout<<team[i]<<" ";
		cout<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
