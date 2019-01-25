#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
using namespace std;


int partition(vector<int>& arr, int left, int right){
	cout<<"Partition "<<left<<" "<<right<<endl;
	int pivot = arr[right];

	int i = left-1;

	for(int j = left; j < right; j++){

		if(arr[j] <= pivot){
			swap(arr[++i],arr[j]);
		}
	}
	swap(arr[++i],arr[right]);

	return i;
}

void quickSort(vector<int>& arr, int low, int high){
	if(low < high){
		int p = partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}
void quickSort(vector<int>& arr){
	return quickSort(arr,0,arr.size()-1);
}

void merge(vector<int>&arr, int left, int middle, int right){

	vector<int> aux(right-left+1);
	int auxPointer = 0;

	int leftPointer = left;
	int rightPointer = middle+1;

	while(leftPointer <= middle && rightPointer <= right){

		if(arr[leftPointer] <= arr[rightPointer]){
			aux[auxPointer++] = arr[leftPointer++];
		}else{
			aux[auxPointer++] = arr[rightPointer++];
		}
	}

	while(leftPointer <= middle){
		aux[auxPointer++] = arr[leftPointer++];
	}
	while(rightPointer <= right){
		aux[auxPointer++] = arr[rightPointer++];
	}

	for(int i = left; i <= right; i++)
		arr[i] = aux[i-left];
}

void mergeSort(vector<int>&arr, int left, int right){
	if(left < right){
		int m = left+(right-left)/2;
		mergeSort(arr,left,m);
		mergeSort(arr,m+1,right);
		merge(arr,left,m,right);
	}
}
void mergeSort(vector<int>& arr){
	return mergeSort(arr,0,arr.size()-1);
}


void coutingSort(vector<int>&arr){
	map<int,int> hash;
	int min = INT_MAX,max = INT_MIN;

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] < min) min = arr[i];
		else if(arr[i] > max) max = arr[i];
		hash[arr[i]]++;
	}
	int arrCounter = 0;
	for(int i = min; i<=max; i++){
		while(hash[i] > 0){
			arr[arrCounter++] = i;
			hash[i]--;
		}
	}
}
bool isSorted(vector<int> arr){
	if(arr.size() == 0) return true;

	for(int i = 1; i < arr.size(); i++){
		if(arr[i] < arr[i-1]) return false;
	}
	return true;
}


int main(){
	int n; cin>>n;
	vector<int> arr(n);

	for(int i = 0; i < n; i++){
		arr[i] = abs((int)(rand()%n));
	}
	coutingSort(arr);
	cout<<isSorted(arr)<<endl;
	return 0;

}