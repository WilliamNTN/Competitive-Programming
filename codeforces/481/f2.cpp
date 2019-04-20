#include <bits/stdc++.h>
using namespace std;

#define LL long long int

typedef struct{
	LL skill;
	LL pos;
}Cell;

LL n,k;
Cell data[201234];
LL ment[201234];

bool sortBySkill(const Cell &a, const Cell &b){
	return a.skill > b.skill;
}
bool sortByPosition(const Cell &a, const Cell &b){
	return a.pos < b.pos;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>k;

	for(LL i=1; i<= n; i++){
		Cell aux;
		LL a;
		cin>>a;
		aux.skill = a;
		aux.pos = i;
		data[i-1] = aux;
	}

	sort(data,data+n,sortBySkill);

	

	memset(ment,0,sizeof(ment));

	for(LL i = n-1; i>=0; i--){
		for(LL j = i+1; j<n; j++)
			if(data[i].skill > data[j].skill){
				ment[data[i].pos-1] = ment[data[j].pos-1] + 1;
				j++;
				while(data[j].skill == data[j-1].skill){
					j++;
					ment[data[i].pos-1]++;
				}
				j = n+1;
			}
			else if(data[i].skill == data[j].skill){
				ment[data[i].pos-1] = ment[data[j].pos-1];
				j = n+1;
			}
	}
	sort(data,data+n,sortByPosition);


	while(k--){
		LL x,y;
		cin>>x>>y;

		if(data[x-1].skill > data[y-1].skill)
			ment[x-1]--;
		else if(data[x-1].skill < data[y-1].skill)
			ment[y-1]--;
	}

	for(LL i=0; i<n; i++)
		cout<<ment[i]<<" ";
	cout<<endl;
	return 0;
}
