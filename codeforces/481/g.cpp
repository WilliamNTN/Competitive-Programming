#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int n,m;

int days[112];
int daysAux[112];

map<int,int> initialDate; //test number -> initialDay
map<int,int> prepareDay; //test number -> prepareNumber
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n>>m;
	int count = 0;

	memset(days,0,sizeof(days));
	memset(daysAux,0,sizeof(daysAux));
	while(count < m){
		count++;
		int s,d,c;
		cin>>s>>d>>c;

		daysAux[d] = count;
		days[d] = m+1;

		initialDate[count] = s;
		prepareDay[count] = c;

	}
	priority_queue<pair<int,int> > todo; // folga, id;
	for(int i = n; i>=1; i--){
		if(daysAux[i]){

			int testId = daysAux[i];
			int nDays = prepareDay[testId];
			//cout<<i<<" é dia de prova "<<testId<<endl; 
			while(nDays--){
				todo.push(make_pair(initialDate[testId],testId));
				//cout<<"Colocou valor "<< testId<<" com folga "<<folga<<endl;
			}
		}
		else{
			if(todo.size() != 0){
				int testId= todo.top().second; todo.pop();
				//cout<<"Vai tentar colocar estudo para a prova "<<testId<<endl;
				if(i < initialDate[testId]){
					cout<<-1<<endl;
					return 0;
				}
				//cout<<"Conseguiu"<<endl;
				daysAux[i] = testId;
				days[i] = testId;
			}
		}
	}

	if(todo.size())
		cout<<-1<<endl;
	else{
		for(int i=1; i<=n; i++)
			cout<<days[i]<<" ";
		cout<<endl;
	}


	return 0;
}
