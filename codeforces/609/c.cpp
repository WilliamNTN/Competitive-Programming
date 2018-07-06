#include <bits/stdc++.h>
using namespace std;

int n;
int tasks[101234];
int result[101234];


int main(){
	cin>>n;

	long long int mean = 0;

	for(int i=0;i<n;i++){
		cin>>tasks[i];
		mean += tasks[i];
	}
	
	if(mean%n == 0){
		for(int i=0;i<n;i++)
			result[i] = mean/n;
	}
	else{
	    int i;
		for(i=0; i<n-(mean)%n;i++)
			result[i] = floor(mean/n);
			
		for(i;i<n;i++)
		    result[i] = ceil((double)mean/n);
	}

	int sum = 0;

	sort(tasks,tasks+n);

	for(int i=0;i<n;i++){
		sum+=(abs(result[i]-tasks[i]));
	}
	cout<<sum/2<<endl;
	
}