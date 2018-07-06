#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


int n, a,b,totalTime,actualFloor;

queue <pair<int,int> > globalOrder;	// .ff = src, .ss = dst
queue <pair<int,int> > flr[9];
list<int> elevator;



int move(int dst){
	int time = 0;
	int up = actualFloor <= dst? 1 : 0;
	for(int i=actualFloor; up? i<=dst: i >= dst; up? i++ : i--){
		time++;
		actualFloor = i;
		int thisSize = elevator.size();
		elevator.remove(i);
		time += thisSize - elevator.size();
	}
	return time-1;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		flr[a].push(make_pair(i,b));
		globalOrder.push(make_pair(a,b));
	}
	totalTime = 0;
	actualFloor = 1;
	while(globalOrder.size()){
		int src = globalOrder.front().ff;
		int dst = globalOrder.front().ss;
		globalOrder.pop();

		totalTime += move(src); // take
		elevator.push_back(dst); totalTime++;
		while(globalOrder.front().ff == actualFloor){
			elevator.push_back(globalOrder.front().ss);
			totalTime++;
			globalOrder.pop();
		}
		totalTime += move(dst); // drop
	}

	cout<<totalTime<<endl;
	return 0;
}
